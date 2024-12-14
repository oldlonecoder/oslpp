//
// Created by oldlonecoder on 24-12-12.
//

//#ifndef THREADS_POOL_H
//#define THREADS_POOL_H
/******************************************************************************************
 *   Copyright (C) ...,2024,2025,... by Serge Lussier                                     *
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


#include <osl++/journal/logger.h>
#include <condition_variable>
#include <mutex>
#include <thread>
#include <utility>
#include <functional>
#include <vector>
#include <osl++/tui/events.h>
namespace tux::ui
{


class OSL_API ui_worker
{
public:
    ui_worker();

    ~ui_worker();
    ui_worker(ui_worker const&) = delete;
    ui_worker& operator=(ui_worker const&) = delete;
    ui_worker(ui_worker&&) noexcept;
    ui_worker& operator=(ui_worker&&) noexcept;
    rem::code start();
    rem::code stop();
    rem::code pause();
    rem::code resume();
    rem::code join();

private:
    using list = std::vector<ui_worker>;
    //...
    friend class threads_pool;
    std::thread::id _id_{};

    rem::action operator()(event& ev);

};


class OSL_API threads_pool
{

public:
    threads_pool();
    ~threads_pool();
    void start();
    void pause();
    void stop();
    void terminate();
private:
    ui_worker::list _workers_{};
    std::mutex mutex;
    std::condition_variable condition;
    bool stopped = false;
    bool paused = false;
    bool terminating = false;
    size_t _num_threads = std::thread::hardware_concurrency();

};



} // namespace tux::ui


//#endif //THREADS_POOL_H
