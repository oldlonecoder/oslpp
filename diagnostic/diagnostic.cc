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


diagnostic::diagnostic(std::string app_name, tux::string::view_list _args/*, tux::string::view_list _env*/):ui::application(std::move(app_name),std::move(_args)/*, std::move(_env)*/){}
diagnostic::diagnostic(const std::string& _app_name, int argc, char** argv, int index, char** env): ui::application(_app_name, tux::string::string_view_list(argc,argv,index)){}


rem::code diagnostic::run()
{
    log::debug() << pretty_id() << " : Running diagnostic for " << _args_ << log::eol;
    return ui::application::run();
    //return rem::code::notimplemented;
}


rem::code diagnostic::terminate()
{
    log::debug() << " nothing to do here. Calling base application::terminate():" << log::eol;
    return application::terminate();
}


rem::code diagnostic::setup_ui()
{
    return application::setup_ui();
}


// diagnostic::~diagnostic()
// {
//
// }





} // namespace tux::rem


auto main(int argc, char** argv) -> int
{
    //tux::log::init(nullptr);
    tux::diagnostic diagnostic("lux++ api diagnostic app", tux::string::string_view_list(argc,argv,1));

    return static_cast<int>(diagnostic.run());
}
