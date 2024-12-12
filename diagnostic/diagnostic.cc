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


diagnostic::diagnostic(std::string app_name, tux::string::view_list _args, tux::string::view_list _env):application(std::move(app_name),std::move(_args), std::move(_env)){}


rem::code diagnostic::run()
{
    log::debug() << pretty_id() << " : Running diagnostic for " << _args_ << log::eol;
    return rem::code::notimplemented;
}


// diagnostic::~diagnostic()
// {
//
// }





} // namespace tux::rem


auto main(int argc, char** argv) -> int
{
    tux::log::init(nullptr);
    tux::diagnostics diagnostics{"diagnostics"};
    new tux::diagnostic(&diagnostics,"test1", tux::string::make_list(argc, argv,1));


    diagnostics.run();
    return 0;
}
