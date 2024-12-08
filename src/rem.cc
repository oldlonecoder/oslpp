#include <map>
#include <osl++/colors.h>
#include <osl++/glyphes.h>

//#include <vector>

using tux::ui::color;
using tux::glyph;
using tux::accent_fr;

bool operator !(rem::code c)
{
    return (c != rem::code::accepted)&&
           (c != rem::code::ok)      &&
           (c != rem::code::success) &&
           (c != rem::code::done)    &&
           (c != rem::code::ready)   &&
           (c != rem::code::finish)  &&
           (c != rem::code::complete);
}



std::map<rem::type, const char*> enums_type_dictionary = {
    {rem::type::none,        "none"},
    {rem::type::err  ,       "err"},
    {rem::type::warning,     "warning"},
    {rem::type::fatal,       "fatal"},
    {rem::type::except,      "exception"},
    {rem::type::message,     "message"},
    {rem::type::output,      ""},
    {rem::type::debug,       "debug"},
    {rem::type::info,        "info"},
    {rem::type::comment,     "comment"},
    {rem::type::syntax,      "syntax error"},
    {rem::type::status,      "status"},
    {rem::type::test,        "test"},
    {rem::type::interrupted, "interrupted"},
    {rem::type::aborted,     "aborted"},
    {rem::type::segfault,    "segmentation fault"},
    {rem::type::log,         "log"}
};


std::map<rem::code, const char*> return_codes_dictionary = {
    {rem::code::ok,             "ok"},
    {rem::code::accepted,       "accepted"},
    {rem::code::success,        "success "},
    {rem::code::rejected,       "rejected"},
    {rem::code::failed,         "failed"},
    {rem::code::empty,          "empty"},
    {rem::code::full,           "full"},
    {rem::code::notempty,       "not empty"},
    {rem::code::implemented,    "implemented"},
    {rem::code::notimplemented, "not implemented"},
    {rem::code::untested,       "untested"},
    {rem::code::eof,            "end of file"},
    {rem::code::eos,            "end of stream or string"},
    {rem::code::null_ptr,       "null pointer"},
    {rem::code::notexist,       "does not exist"},
    {rem::code::exist,          "exist"},
    {rem::code::unexpected,     "unexpected"},
    {rem::code::expected,       "expected"},
    {rem::code::blocked,        "blocked"},
    {rem::code::locked,         "locked"},
    {rem::code::overflow,       "buffer overflow"},
    {rem::code::oob,            "out of boundaries"},
    {rem::code::reimplement,    "need to be re-implemented in derived instances"},
    {rem::code::done,           "done"},
    {rem::code::complete,       "completed"},
    {rem::code::finish,         "finished"},
    {rem::code::undefined,      "undefined"},
    {rem::code::ready,          "Ready"},
    {rem::code::terminate,      "terminate"},
    {rem::code::timeout,        "timeout"},
    {rem::code::divbyzero,      "division by zero"},
    {rem::code::notvisible,     "not visible"},
    {rem::code::cancel,         "cancel"},
    {rem::code::object_ptr,     "object"},
    {rem::code::object_id,      "object id"},
};


std::map<rem::action, const char*> actions_dictionary= {
    {rem::action::enter,   "enter"},
    {rem::action::leave,   "leave"},
    {rem::action::begin,   "begin"},
    {rem::action::end,     "end"},
    {rem::action::commit,  "commit"},
    {rem::action::continu, "continue"},
    {rem::action::dismiss, "dismissed"},
};


std::map<rem::fn, const char*> functions_dictionary= {

    {rem::fn::endl,           "end line"},
    {rem::fn::func,            "function"},
    {rem::fn::file,           "file"},
    {rem::fn::line,           "line"},
    {rem::fn::stamp,          "stamp"},
    {rem::fn::hour,           "hour"},
    {rem::fn::minute,         "minute"},
    {rem::fn::seconds,        "seconds"},
    {rem::fn::weekday,        "weekday"},
    {rem::fn::month,          "month name"},
    {rem::fn::dayname,        "day name"},
    {rem::fn::day,            "day"},
    {rem::fn::monthnum,       "month number"},
    {rem::fn::year,           "year"}
};




std::string rem::to_string(rem::type ty)
{
    return enums_type_dictionary[ty];
}

std::string rem::to_string(rem::code cod)
{
    return return_codes_dictionary[cod];
}



std::string rem::to_string(rem::fn fn)
{
    return functions_dictionary[fn];
}

std::string rem::to_string(rem::action ac)
{
    return actions_dictionary[ac];
}
