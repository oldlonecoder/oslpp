//
// Created by oldlonecoder on 24-12-10.
//

//#ifndef DIAGNOSTIC_H
//#define DIAGNOSTIC_H
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
//#include <osl++/rem.h>
#include <osl++/tui/application.h>
#include <osl++/expect.h>

namespace tux
{

class OSL_API diagnostic : public ui::application
{

    CLASSNAME(diagnostic)

    rem::code _status_{rem::code::notimplemented};
    tux::string::list _args_{};
public:

    diagnostic()=default;
    diagnostic(const std::string& _app_name, int argc, char** argv, int index=1, char** env={});

    diagnostic(std::string app_name, tux::string::view_list _args, tux::string::view_list _env);
    ~diagnostic() override = default;
    //...

    rem::code run() override;
    rem::code terminate() override;


protected:

    rem::code setup_ui() override;
};



} // namespace tux

//#endif //DIAGNOSTIC_H
