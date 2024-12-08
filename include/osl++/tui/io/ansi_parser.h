//
// Created by oldlonecoder on 24-11-17.
//

//#ifndef ANSI_PARSER_H
//#define ANSI_PARSER_H
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

#include <osl++/tui/events.h>
#include <osl++/tui/io/polling.h>

namespace tux::ui::io
{



class OSL_API ansi_parser
{

public:
    ansi_parser() = default;
    ~ansi_parser() = default;

    explicit ansi_parser(descriptor& _stream);
    rem::code parse(event& ev);

private:

    rem::code parse_ESC(event& ev);
    rem::code parse_csi(event& ev);
    rem::code parse_mouse(event& ev, std::vector<int>&& args);
    rem::code parse_ss1_2(event& ev);
    descriptor& stream;

    bool next_byte();
    std::string::iterator cursor{};
    //...
    
};


}//namespace tux::ui::io

//#endif //ANSI_PARSER_H
