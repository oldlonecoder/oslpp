
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

#include <osl++/tui/widgets/threads_pool.h>




namespace tux::ui
{
ui_worker::ui_worker()
{
    //...stop here - have to go to work...:(
}


threads_pool::threads_pool() = default;


void threads_pool::start()
{
    for (auto n = 0; n< _num_threads; ++n)
    {
        _workers_.emplace_back();
    }
}
} // namespace tux::ui
