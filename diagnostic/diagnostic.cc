//
// Created by oldlonecoder on 24-12-10.
//



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


//#pragma once


#include "diagnostic.h"

#include <utility>

namespace tux
{

diagnostic::diagnostic(object* _parent, const std::string& _name):object(_parent, _name){}


diagnostic::diagnostic(object* _parent, const std::string& _name, tux::string::list _args): _args_(std::move(_args)), object(_parent, _name){}


expect<> diagnostic::run()
{
    log::debug() << pretty_id() << " : Running diagnostic for " << _args_ << log::eol;
    return rem::code::notimplemented;
}

// diagnostic::~diagnostic()
// {
//
// }



#pragma region _DIGANOSTICS_
diagnostics::diagnostics(const std::string& _name):object(nullptr, _name){}


rem::code diagnostics::run()
{
    for (auto* o: m_children)
    {
        if (auto* d = dynamic_cast<diagnostic*>(o); d != nullptr) d->run();
    }
    return rem::code::done;
}


#pragma endregion _DIGANOSTICS_


} // namespace tux::rem


auto main(int argc, char** argv) -> int
{
    tux::log::init(nullptr);
    tux::diagnostics diagnostics{"diagnostics"};
    new tux::diagnostic(&diagnostics,"test1", tux::string::make_list(argc, argv,1));


    diagnostics.run();
    return 0;
}
