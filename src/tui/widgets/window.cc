/***************************************************************************
 *   Copyright (C) 1965/1987/2023 by Serge Lussier                         *
 *   serge.lussier@oldlonecoder.club                                       *
 *                                                                         *
 *                                                                         *
 *   Unless otherwise specified, all Code in this project is written       *
 *   by the author (Serge Lussier)                                         *
 *   and no one else then not even {copilot, chatgpt, or any other AI}     *
 *   --------------------------------------------------------------------- *
 *   Copyrights from authors other than Serge Lussier also apply here      *
 ***************************************************************************/


//#include <tuxtui/ui/widgets/window.h>
#include <osl++/tui/widgets/screen.h>

#include "osl++/tui/application.h"

namespace tux::ui
{



/*!
 * \brief window::window
 * \param _parent
 * \param _id
 * \param _components additional window;s sub-components
 * @note Window class objects are systematically toplevel widgets.
 */
window::window(object *_parent, const std::string &_id, ui::components::type _components): widget(_parent,_id)
{
    _anchor_=0;
    set_components(_components); // |ui::components::MenuBar|ui::components::StatusBar);
    set_uistyle(ui::uistyle::Window);

}



window::~window()
= default;

rem::code window::hide()
{
    //_desktop_->hide_window(this);
    return rem::code::notimplemented;
}


/*!
 * @brief Show on the screen.
 * @return done;
 */
rem::code window::show()
{
    //if(!_screen_) return rem::code::rejected;
    //...
    //_screen_->add_window(this);
    _uistate_ |= ui::uistate::Visible;
    //render_line();
    application::screen()->add_window(this);
    application::screen()->show_window(this);

    return rem::code::done;
}


rem::code window::setup_ui()
{
    if(_uicomponents_ == ui::components::StatusBar)
    {
        //log::log() << log::fn::func << pretty_id() << " Adding StatusBar component:" << log::eol;
        //_status_bar_ = new status_bar(this,id() + "_status_bar");
        //anchor_widget(_status_bar_);
    }
    return rem::code::done;
}


/*!
 * @brief  window::dirty addresses directly the screen's dirty function that owns this window
 * @param _dirty_rect
 * @return
 */
rem::code window::dirty(const rectangle& _dirty_rect)
{
    auto r = widget::dirty(_dirty_rect);
    if(!r)
        return rem::code::rejected;
    if(_desktop_)
        return _desktop_->dirty(_dirty_area_);
    return rem::code::null_ptr;

}


}