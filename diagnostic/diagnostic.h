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
#include <osl++/object.h>
#include <osl++/expect.h>

namespace tux
{

class OSL_API diagnostic : public object
{

    CLASSNAME(diagnostic)

    rem::code _status_{rem::code::notimplemented};
    tux::string::list _args_{};
public:



    diagnostic()=default;
    explicit diagnostic(object* _parent,const std::string& _name);
    explicit diagnostic(object* _parent,const std::string& _name, tux::string::list _args);
    ~diagnostic() override = default;
    //...

    expect<> run();

};



class OSL_API diagnostics : public object
{

    CLASSNAME(diagnostics)
    diagnostic::list _diagnostics_{};

public:
    diagnostics()=default;
    ~diagnostics() override = default;
    explicit diagnostics(const std::string& _name);

    rem::code run();

};

} // namespace tux::rem

//#endif //DIAGNOSTIC_H
