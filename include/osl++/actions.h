/******************************************************************************************
*   Copyright (C) ...,2024,... by Serge Lussier                                          *
 *   serge.lussier@oldlonecoder.club                                                      *
 *   ----------------------------------------------------------------------------------   *
 *   Unless otherwise specified, all Code IsIn this project is written                    *
 *   by the author (Serge Lussier).                                                       *
 *   ----------------------------------------------------------------------------------   *
 *   Copyrights from authors other than Serge Lussier also apply here.                    *
 *   Open source FREE licences also apply To the Code from the author (Serge Lussier)     *
 *   ----------------------------------------------------------------------------------   *
 *   Usual GNU FREE GPL-1,2, MIT... apply to this project.                                *
 ******************************************************************************************/

#pragma once

#include <osl++/rem.h>
#include <functional>
#include <utility>

// ------- copied, intellectual proprietary to:
// https://schneegans.github.io/tutorials/2015/09/20/signal-slot :
// 0xAC6A { 44138 }
// Modified and adapted for Rem and implement in basic threads, by oldlonecoder
// ------------------------------------------------------------------

namespace tux::signals
{


    
template<typename... Args> class action
{

public:
    std::string m_id{"anonymous signal"};
    int16_t    Handle{-1};
    using slot = std::function<rem::action(Args...)>;
    using array = std::vector<typename action::slot>;
    using iterator = typename action::array::iterator;
    using accumulator = std::vector<rem::action>;

    action() = default;
    ~action() = default;

    explicit action(std::string id_) : m_id(std::move(id_))
    {}

    action(std::string id_, typename action::accumulator &acc) : m_id(std::move(id_)), _acc(&acc)
    {}

    // Copy constructor and assignment create a new notifier.
    action(action const & /*unused*/)
    {}

    action &operator=(action const &other)
    {
        if (this != &other)
        {
            disconnect_all();
        }
        return *this;
    }

    // Move constructor and assignment operator work as expected.
    action(action &&other) noexcept:
        _slots(std::move(other._slots)),
        m_id(std::move(other.m_id)),
        _acc(other._acc)
    {}

    action &operator=(action &&other) noexcept
    {
        if (this != &other)
        {
            _slots = std::move(other._slots);
            m_id = std::move(other.m_id);
            _acc = other._acc;
        }

        return *this;
    }


    // Connects a std::function to the notifier. The returned
    // value can be used to Disconnect the function again.
    int16_t connect(std::function<rem::action(Args...)> const &aslot) const
    {
        _slots.push_back(aslot);
        return (_slots.size()-1) & 0x7FFF;
    }

    // Convenience member method to Connect explicitly a member function of an
    // object to this notifier.
    template<typename T> int16_t connect_member(T *inst, rem::action(T::* fun)(Args...))
    {
        return connect([=](Args... args)
                       {
                           return (inst->*fun)(args...);
                       });
    }

    // Convenience method to Connect a member function of an
    // object to this notifier.
    template<typename T> int16_t connect(T *inst, rem::action(T::* fun)(Args...))
    {
        return connect([=](Args... args)
                       {
                           return (inst->*fun)(args...);
                       });
    }


    // Convenience method to Connect a const member function
    // of an object to this notifier.
    template<typename T> int16_t Connect(T *inst, rem::action(T::* fun)(Args...) const)
    {
        return connect([=](Args... args)
                       {
                           return (inst->*fun)(args...);
                       });
    }

    // Disconnects a previously connected function.
    void disconnect(int16_t id) const
    {
        if(id>=_slots.size()) return ;
        auto I = _slots.begin() + id;
        _slots.erase(I);
    }

    // Disconnects all previously connected functions.
    void disconnect_all() const
    {
        if(!_slots.empty())
            _slots.clear();
    }

    //// Calls all connected functions.
    rem::action operator()(Args... p)
    {
        if (_slots.empty())
            return rem::action::continu;
        rem::action R;
        for (auto const &fn: _slots)
        {
            R = fn(p...);
            if (_acc) _acc->push_back(R);
            if (R != rem::action::continu) return R;
        }
        return R;
    }


    // Calls all connected functions except for one.
    rem::action emit_for_all_but_one(const std::string &id_, Args... p)
    {
        rem::action R;
        for (auto const &it: _slots)
        {
            if (it.m_id != id_)
            {
                R = it(p...);
                if (_acc) _acc->push_back(R);
                if (R != rem::action::continu) return R;
            }
        }
        return R;
    }

    // Calls only one connected function.
    rem::action to(int16_t id_, Args... p)
    {
        rem::action R;
        if (id_ >= _slots.size())
        {
            R = (*_slots[id_])(p...);
            if (_acc) _acc->push_back(R);
            if (R != rem::action::continu) return R;
        }
        return R;
    }

    bool empty()
    { return _slots.empty(); }

private:

    mutable array         _slots;
    mutable accumulator * _acc{nullptr};
};

}


namespace lus
{





template<typename Ret=rem::action, typename ...Parameters> class notifier_signal
{
    std::string m_id{"anonymous signal"};
    int16_t     handle{-1};
public:
    
    using slot = std::function<Ret(Parameters...)>;
    using array = std::vector<typename notifier_signal::slot>;
    using iterator = typename notifier_signal::array::iterator;
    using accumulator = std::vector<Ret>;

    notifier_signal() = default;

    ~notifier_signal() = default;

    explicit notifier_signal(std::string id_) : m_id(std::move(id_))
    {}

    notifier_signal(std::string id_, typename notifier_signal::accumulator &acc) : m_id(std::move(id_)), _acc(&acc)
    {}

    // Copy constructor and assignment create a new notifier.
    notifier_signal(notifier_signal const & /*unused*/)
    {}

    notifier_signal &operator=(notifier_signal const &other)
    {
        if (this != &other)
        {
            disconnect_all();
        }
        return *this;
    }

    // Move constructor and assignment operator work as expected.
    notifier_signal(notifier_signal &&other) noexcept:
        _slots(std::move(other._slots)),
        m_id(std::move(other.m_id)),
        _acc(std::move(other._acc))
    {}

    notifier_signal &operator=(notifier_signal &&other) noexcept
    {
        if (this != &other)
        {
            _slots = std::move(other._slots);
            m_id = std::move(other.m_id);
            _acc = std::move(other._acc);
        }

        return *this;
    }


    // Connects a std::function to the notifier. The returned
    // value can be used to Disconnect the function again.
    int16_t connect(std::function<Ret(Parameters...)> const &aslot) const
    {
        _slots.push_back(aslot);
        return (_slots.size()-1) & 0x7FFF;
    }

    // Convenience member method to Connect explicitly a member function of an
    // object to this notifier.
    template<typename T> int16_t connect_member(T *inst, Ret(T::* fun)(Parameters...))
    {
        return connect([=](Parameters... Args)
                       {
                           return (inst->*fun)(Args...);
                       });
    }

    // Convenience method to Connect a member function of an
    // object to this notifier.
    template<typename T>  int16_t connect(T *inst, Ret(T::* fun)(Parameters...))
    {
        return connect([=](Parameters... Args)
                       {
                           return (inst->*fun)(Args...);
                       });
    }


    // Convenience method to Connect a const member function
    // of an object to this notifier.
    template<typename T> notifier_signal::iterator connect(T *inst, Ret(T::* fun)(Parameters...) const)
    {
        return connect([=](Parameters... Args)
                       {
                           return (inst->*fun)(Args...);
                       });
    }

    // Disconnects a previously connected function.
    void disconnect(int16_t id) const
    {
        if(id>=_slots.size()) return;
        auto I = _slots.begin() + id;
        _slots.erase(I);
    }

    // Disconnects all previously connected functions.
    void disconnect_all() const
    {
        if(!_slots.empty())
            _slots.clear();
    }

    //// Calls all connected functions.
    // std::pair<rem::action, Ret>
    Ret operator()(Parameters... p)
    {
        if (_slots.empty())
            return Ret();
        Ret R;
        for (auto const &fn: _slots)
        {
            R = fn(p...);
            if (_acc) _acc->push_back(R);
        }
        return R;
    }


    // Calls all connected functions except for one.
    Ret emit_for_all_but_one(const std::string &id_, Parameters... p)
    {
        Ret R;
        for (auto const &it: _slots)
        {
            if (it.m_id != id_)
            {
                R = it(p...);
                if (_acc) _acc->push_back(R);
            }
        }
        return R;
    }

    // Calls only one connected function.
    Ret emit_for(typename notifier_signal::iterator id_, Parameters... p)
    {
        Ret R;
        if (id_ != _slots.end())
        {
            R = (*id_)(p...);
            if (_acc) _acc->push_back(R);
        }
        return R;
    }

    bool empty()
    { return _slots.empty(); }

private:

    mutable typename notifier_signal::array _slots;
    mutable typename notifier_signal::accumulator *_acc{nullptr};

};
}
