
#include <osl++/glyphes.h>
#include <map>


namespace osl
{

std::vector<accent_fr::T> accent_fr::data =
    {
        L_agrave,
        L_acirc,
        L_cedile,
        L_eacute,
        L_egrave,
        L_ecirc,
        L_etrema,
        L_itrema,
        L_ocirc,
        L_ugrave,
        L_ucric,
        L_icirc,
        L_Agrave,
        L_Acirc,
        L_Cedile,
        L_Eacute,
        L_Egrave,
        L_Ecirc,
        L_Etrema,
        L_Itrema,
        L_Ocirc,
        L_Ugrave,
        L_Ucric,
        L_Icirc
    };
std::vector<std::string_view> accent_fr::name =
    {
        "agrave",
        "acirc",
        "cedile",
        "eacute",
        "egrave",
        "ecirc",
        "etrema",
        "itrema",
        "ocirc",
        "ugrave",
        "ucirc",
        "icirc",
        "Agrave",
        "Acirc",
        "Cedile",
        "Eacute",
        "Egrave",
        "Ecirc",
        "Etrema",
        "Itrema",
        "Ocirc",
        "Ugrave",
        "Ucirc",
        "Icirc"
    };


accent_fr::type accent_fr::get_enum(std::string_view accent_name)
{
    std::map<std::string_view, accent_fr::type> dictionary =
        {
            {"agrave", agrave},
            {"acirc",  acirc},
            {"cedile", cedile},
            {"eacute", eacute},
            {"egrave", egrave},
            {"ecirc",  ecirc},
            {"etrema", etrema},
            {"itrema", itrema},
            {"ocirc",  ocirc},
            {"ugrave", ugrave},
            {"ucirc",  ucirc},
            {"icirc",  icirc},
            {"Agrave", Agrave},
            {"Acirc",  Acirc},
            {"Cedile", Cedile},
            {"Eacute", Eacute},
            {"Egrave", Egrave},
            {"Ecirc",  Ecirc},
            {"Etrema", Etrema},
            {"Itrema", Itrema},
            {"Ocirc",  Ocirc},
            {"Ugrave", Ugrave},
            {"Ucirc",  Ucirc},
            {"Icirc",  Icirc}
        };
    for (auto const &[k, t]: dictionary)
    {
        if (k == accent_name) return t;
    }

    return type::Err;
}

std::pair<bool, accent_fr::type> accent_fr::scan_name(std::string_view accent_name)
{
    std::map<std::string_view, accent_fr::type> dictionary =
        {
            {"agrave", agrave},
            {"acirc",  acirc},
            {"cedile", cedile},
            {"eacute", eacute},
            {"egrave", egrave},
            {"ecirc",  ecirc},
            {"etrema", etrema},
            {"itrema", itrema},
            {"ocirc",  ocirc},
            {"ugrave", ugrave},
            {"ucirc",  ucirc},
            {"icirc",  icirc},
            {"Agrave", Agrave},
            {"Acirc",  Acirc},
            {"Cedile", Cedile},
            {"Eacute", Eacute},
            {"Egrave", Egrave},
            {"Ecirc",  Ecirc},
            {"Etrema", Etrema},
            {"Itrema", Itrema},
            {"Ocirc",  Ocirc},
            {"Ugrave", Ugrave},
            {"Ucirc",  Ucirc},
            {"Icirc",  Icirc}
        };
    for (auto const &[k, t]: dictionary)
    {
        if (k ==accent_name) return {true, t};
    }
    return {false, type::Err};
}



glyph::data_array glyph::data =
    {
        c_ok                     ,
        c_comment                ,
        c_arrow_right            ,
        c_arrow_left             ,
        c_arrow_up               ,
        c_arrow_down             ,
        c_arrow_up_right         ,
        c_arrow_up_left          ,
        c_arrow_down_right       ,
        c_arrow_down_left        ,
        c_arrow_head_right       ,
        c_arrowd_head_right      ,
        c_pencil_dr              ,
        c_pencil_ur              ,
        c_err1                   ,
        c_flag                   ,
        c_bolt                   ,
        c_success                ,
        c_small_dot              ,
        c_big_dot                ,
        c_ball1                  ,
        c_ball2                  ,
        c_dead_head              ,
        c_yinyang                ,
        c_sad_face               ,
        c_happy1                 ,
        c_happy2                 ,
        c_circle_x               ,
        c_function               ,
        c_cut1                   ,
        c_cut2                   ,
        c_cut3                   ,
        c_cmark_x                ,
        c_baseline               ,
        c_star5                  ,
        c_cmark_check            ,
        c_sword_cross            ,
        c_hammer_cross           ,
        c_small_dot2             ,
        c_err2                   ,
        c_err3                   ,
        c_squote1                ,
        c_dquote_left            ,
        c_dquote_right           ,
        c_down_to_bottom_left    ,
        c_undo                   ,
        c_enter                  ,
        c_key_enter              ,
        c_linux                  ,
        c_arch                   ,
        c_home                   ,
        c_file                   ,
        c_thumb_down             ,
        c_github_circle          ,
        c_github_folder          ,
        c_windows                ,
        c_pi                     ,
        c_folder                 ,
        c_bug                    ,
        c_info                   ,
        c_warning                ,
        c_bomb                   ,
        c_edit_pencil_br         ,
        c_edit_pencil_r          ,
        c_edit_pencil_ur         ,
        c_neg_cross_check        ,
        c_shadowed_checkbox      ,
        c_spin_arrow_spin0       ,
        c_spin_arrow_spin1       ,
        c_spin_arrow_spin2       ,
        c_spin_arrow_spin3       ,
        c_spin_arrow_spin4       ,
        c_spin_arrow_spin5       ,
        c_spin_arrow_spin6       ,
        c_spin_arrow_spin7       ,
        c_thumb_up               ,
        c_chronos                ,
        c_sand                   ,
        c_coffee                 ,
        c_unauth                 ,
        c_handwrite              ,
        c_world                  ,
        c_world_grid             ,
        c_school                 ,
        c_hat                    ,
        c_admin                  ,
        c_fabric                 ,
        c_cat                    ,
        c_fish                   ,
        c_search                 ,
        c_people                 ,
        c_alien                  ,
        c_light                  ,
        c_poop                   ,
        c_cash                   ,
        c_computer               ,
        c_notepad                ,
        c_books                  ,
        c_send                   ,
        c_recieve                ,
        c_email                  ,
        c_email2                 ,
        c_nullptr                ,
        c_stop                   ,
        c_debian                 ,
        c_terminal               ,
        c_log                    ,
        c_sqpixel                ,
        c_fbox                   ,
        c_dnpixel                ,
    };

std::map<glyph::type, std::string> glyph_dict =
    {
        {glyph::ok                 ,"ok"},                 
        {glyph::comment            ,"comment"},            
        {glyph::arrowright         ,"arrowright"},         
        {glyph::arrow_left         ,"arrow_left"},         
        {glyph::arrow_up           ,"arrow_up"},           
        {glyph::arrow_down         ,"arrow_down"},        
        {glyph::arrow_up_right     ,"arrow_up_right"},     
        {glyph::arrow_up_left      ,"arrow_up_left"},      
        {glyph::arrow_down_right   ,"arrow_down_right"},   
        {glyph::arrow_down_left    ,"arrow_down_left"},    
        {glyph::arrow_head_right   ,"arrow_head_right"},   
        {glyph::arrow_dhead_right  ,"arrow_dhead_right"},  
        {glyph::pencil_dr          ,"pencil_dr"},          
        {glyph::pencil_ur          ,"pencil_ur"},
        {glyph::err1               ,"err1"},               
        {glyph::flag               ,"flag"},               
        {glyph::bolt               ,"bolt"},               
        {glyph::success            ,"success"},            
        {glyph::small_dot          ,"small_dot"},          
        {glyph::big_dot            ,"big_dot"},            
        {glyph::ball1              ,"ball1"},              
        {glyph::ball2              ,"ball2"},              
        {glyph::dead_head          ,"dead_head"},          
        {glyph::yinyang            ,"yinyang"},            
        {glyph::sad_face           ,"sad_face"},           
        {glyph::happy1             ,"happy1"},             
        {glyph::happy2             ,"happy2"},             
        {glyph::circle_x           ,"circle_x"},           
        {glyph::function           ,"function"},
        {glyph::cut1               ,"cut1"},               
        {glyph::cut2               ,"cut2"},               
        {glyph::cut3               ,"cut3"},               
        {glyph::cmark_x            ,"cmark_x"},            
        {glyph::baseline           ,"baseline"},           
        {glyph::star5              ,"star5"},              
        {glyph::cmark_check        ,"cmark_check"},        
        {glyph::sword_cross        ,"sword_cross"},        
        {glyph::hammer_cross       ,"hammer_cross"},       
        {glyph::small_dot2         ,"small_dot2"},         
        {glyph::err2               ,"err2"},               
        {glyph::err3               ,"err3"},               
        {glyph::squote1            ,"squote1"},            
        {glyph::dquote_left        ,"dquote_left"},        
        {glyph::dquote_right       ,"dquote_right"},       
        {glyph::down_to_bottom_left,"down_to_bottom_left"},
        {glyph::undo               ,"undo"},               
        {glyph::enter              ,"enter"},              
        {glyph::key_enter          ,"key_enter"},          
        {glyph::linux_os           ,"linux_os"},           
        {glyph::arch               ,"arch"},               
        {glyph::home               ,"home"},               
        {glyph::file               ,"file"},               
        {glyph::thumb_down         ,"thumb_down"},         
        {glyph::github_circle      ,"github_circle"},      
        {glyph::github_folder      ,"github_folder"},      
        {glyph::windows            ,"windows"},            
        {glyph::pi                 ,"pi"},                 
        {glyph::folder             ,"folder"},             
        {glyph::bug                ,"bug"},                
        {glyph::info               ,"info"},               
        {glyph::warning            ,"warning"},            
        {glyph::bomb               ,"bomb"},               
        {glyph::edit_pencil_br     ,"edit_pencil_br"},
        {glyph::edit_pencil_r      ,"edit_pencil_r"},      
        {glyph::edit_pencil_ur     ,"edit_pencil_ur"},     
        {glyph::neg_cross_check    ,"neg_cross_check"},    
        {glyph::shadowed_checkbox  ,"shadowed_checkbox"},  
        {glyph::spin_arrow_spin0   ,"spin_arrow_spin0"},   
        {glyph::spin_arrow_spin1   ,"spin_arrow_spin1"},   
        {glyph::spin_arrow_spin2   ,"spin_arrow_spin2"},   
        {glyph::spin_arrow_spin3   ,"spin_arrow_spin3"},   
        {glyph::spin_arrow_spin4   ,"spin_arrow_spin4"},   
        {glyph::spin_arrow_spin5   ,"spin_arrow_spin5"},   
        {glyph::spin_arrow_spin6   ,"spin_arrow_spin6"},   
        {glyph::spin_arrow_spin7   ,"spin_arrow_spin7"},   
        {glyph::thumb_up           ,"thumb_up"},           
        {glyph::chronos            ,"chronos"},            
        {glyph::sand               ,"sand"},               
        {glyph::coffee             ,"coffee"},             
        {glyph::unauth             ,"unauth"},             
        {glyph::handwrite          ,"handwrite"},          
        {glyph::world              ,"world"},              
        {glyph::world_grid         ,"world_grid"},         
        {glyph::school             ,"school"},             
        {glyph::hat                ,"hat"},                
        {glyph::admin              ,"admin"},              
        {glyph::fabric             ,"fabric"},             
        {glyph::cat                ,"cat"},                
        {glyph::fish               ,"fish"},               
        {glyph::search             ,"search"},             
        {glyph::people             ,"people"},             
        {glyph::alien              ,"alien"},              
        {glyph::light              ,"light"},              
        {glyph::poop               ,"poop"},               
        {glyph::cash               ,"cash"},               
        {glyph::computer           ,"computer"},           
        {glyph::notepad            ,"notepad"},            
        {glyph::books              ,"books"},              
        {glyph::send               ,"send"},               
        {glyph::receive            ,"receive"},            
        {glyph::email              ,"email"},              
        {glyph::email2             ,"email2"},             
        {glyph::e_nullptr          ,"e_nullptr"},          
        {glyph::stop               ,"stop"},               
        {glyph::debian             ,"debian"},             
        {glyph::terminal           ,"terminal"},
        {glyph::log                ,"log"},
        {glyph::sqpixel            ,"sqpixel"},
        {glyph::fbox               ,"fbox"},
        {glyph::dnpixel            ,"dnpixel"},
    };


static glyph::type last_glyph_index = glyph::sqpixel;

std::map<rem::type, std::pair<osl::glyph::type, color::pair>> types_database={

    {rem::type::none,        {osl::glyph::computer,  {color::aquamarine1         , color::reset }}},
    {rem::type::err,         {osl::glyph::err1,      {color::red4                , color::reset }}},
    {rem::type::warning,     {osl::glyph::warning,   {color::yellow              , color::reset }}},
    {rem::type::fatal,       {osl::glyph::dead_head, {color::hotpink4            , color::reset }}},
    {rem::type::except,      {osl::glyph::bolt,      {color::skyblue3            , color::reset }}},
    {rem::type::message,     {osl::glyph::comment,   {color::green4              , color::reset }}},
    {rem::type::output,      {osl::glyph::notepad,   {color::grey39              , color::reset }}},
    {rem::type::debug,       {osl::glyph::bug,       {color::pink3               , color::reset }}},
    {rem::type::info,        {osl::glyph::info,      {color::lightskyblue4       , color::reset }}},
    {rem::type::comment,     {osl::glyph::comment,   {color::grey42              , color::reset }}},
    {rem::type::syntax,      {osl::glyph::handwrite, {color::lighcoreateblue     , color::reset }}},
    {rem::type::status,      {osl::glyph::admin,     {color::lightcyan3          , color::reset }}},
    {rem::type::test,        {osl::glyph::file,      {color::aquamarine3         , color::reset }}},
    {rem::type::interrupted, {osl::glyph::circle_x,  {color::khaki3              , color::reset }}},
    {rem::type::aborted,     {osl::glyph::stop,      {color::red4                , color::reset }}},
    {rem::type::segfault,    {osl::glyph::bomb,      {color::sandybrown          , color::reset }}},
    {rem::type::log,         {osl::glyph::log,       {color::orangered1          , color::reset }}}
    //...
};


std::map<rem::action      , std::pair<osl::glyph::type, color::pair>> actions_color_db = {
    {rem::action::enter   , {osl::glyph::enter        , {color::white               , color::reset}}},
    {rem::action::leave   , {osl::glyph::file         , {color::white               , color::reset}}},
    {rem::action::begin   , {osl::glyph::chronos      , {color::white               , color::reset}}},
    {rem::action::end     , {osl::glyph::dead_head    , {color::white               , color::reset}}},
    {rem::action::commit  , {osl::glyph::pencil_dr    , {color::white               , color::reset}}},
    {rem::action::continu , {osl::glyph::success      , {color::white               , color::reset}}},
       {rem::action::dismiss , {osl::glyph::arrow_dhead_right , {color::yellow         , color::reset}}},
};

std::map<rem::code, std::pair<osl::glyph::type, color::pair>> codes_database={
    {rem::code::ok,              {osl::glyph::thumb_up,        {color::lime              ,color::reset }}},
    {rem::code::accepted,        {osl::glyph::thumb_up,        {color::lime              ,color::reset }}},
    {rem::code::success,         {osl::glyph::success,         {color::darkgreen         ,color::reset }}},
    {rem::code::rejected,        {osl::glyph::thumb_down,      {color::hotpink4          ,color::reset }}},
    {rem::code::failed,          {osl::glyph::poop,            {color::darkgoldenrod     ,color::reset }}},
    {rem::code::empty,           {osl::glyph::arrowright,      {color::lighcoreategrey   ,color::reset }}},
    {rem::code::full,            {osl::glyph::small_dot,       {color::white             ,color::reset }}},
    {rem::code::notempty,        {osl::glyph::big_dot,         {color::white             ,color::reset }}},
    {rem::code::implemented,     {osl::glyph::arrow_head_right,{color::lime              ,color::reset }}},
    {rem::code::notimplemented,  {osl::glyph::err1,            {color::orange3           ,color::reset }}},
    {rem::code::untested,        {osl::glyph::flag,            {color::yellow            ,color::reset }}},
    {rem::code::eof,             {osl::glyph::baseline,        {color::white             ,color::reset }}},
    {rem::code::eos,             {osl::glyph::baseline,        {color::white             ,color::reset }}},
    {rem::code::null_ptr,        {osl::glyph::circle_x,        {color::hotpink4            ,color::reset }}},
    {rem::code::notexist  ,      {osl::glyph::circle_x ,       {color::white               ,color::reset }}},
    {rem::code::exist     ,      {osl::glyph::star5 ,          {color::white             ,color::reset }}},
    {rem::code::unexpected,      {osl::glyph::flag ,           {color::yellow            ,color::reset }}},
    {rem::code::expected  ,      {osl::glyph::cat ,            {color::white             ,color::reset }}},
    {rem::code::blocked   ,      {osl::glyph::unauth ,         {color::indianred3        ,color::reset }}},
    {rem::code::locked    ,      {osl::glyph::err3 ,           {color::white             ,color::reset }}},
    {rem::code::overflow  ,      {osl::glyph::dead_head,       {color::red4              ,color::reset }}},
    {rem::code::oob       ,      {osl::glyph::alien,           {color::lightcoral        ,color::reset }}},
    {rem::code::reimplement,     {osl::glyph::log,             {color::yellow            ,color::reset }}},
    {rem::code::done       ,     {osl::glyph::ok,              {color::yellow            ,color::reset }}},
    {rem::code::complete   ,     {osl::glyph::ok,              {color::yellow            ,color::reset }}},
    {rem::code::finish     ,     {osl::glyph::ok,              {color::lime              ,color::reset }}},
    {rem::code::undefined  ,     {osl::glyph::err3,            {color::red               ,color::reset }}},
    {rem::code::ready      ,     {osl::glyph::ok,              {color::lime              ,color::reset }}},
    {rem::code::terminate  ,     {osl::glyph::flag,            {color::hotpink4          ,color::reset }}},
    {rem::code::timeout    ,     {osl::glyph::chronos,         {color::lime              ,color::reset }}},
    {rem::code::divbyzero  ,     {osl::glyph::circle_x,        {color::red4                ,color::reset }}},
    {rem::code::notvisible ,     {osl::glyph::circle_x,        {color::yellow              ,color::reset }}},
    {rem::code::cancel     ,     {osl::glyph::circle_x,        {color::red4                ,color::reset }}},
    {rem::code::object_ptr ,     {osl::glyph::edit_pencil_br,{color::lightsteelblue3     ,color::reset }}},
    {rem::code::object_id ,      {osl::glyph::arrowright,      {color::yellow            ,color::reset }}},

};


std::map<rem::fn, std::pair<osl::glyph::type, color::pair>> functions_database={

    {rem::fn::stamp     ,      {osl::glyph::chronos  ,   {color::skyblue3          ,color::reset }}},
    {rem::fn::func      ,      {osl::glyph::function ,   {color::skyblue3          ,color::reset }}},
    {rem::fn::file      ,      {osl::glyph::file     ,   {color::lightcyan3        ,color::reset }}},
    {rem::fn::line      ,      {osl::glyph::baseline ,   {color::lime              ,color::reset }}},
    {rem::fn::stamp     ,      {osl::glyph::chronos  ,   {color::yellow            ,color::reset }}},
    {rem::fn::hour      ,      {osl::glyph::chronos  ,   {color::white             ,color::reset }}},
    {rem::fn::minute    ,      {osl::glyph::chronos  ,   {color::white             ,color::reset }}},
    {rem::fn::seconds   ,      {osl::glyph::chronos  ,   {color::white             ,color::reset }}},
    {rem::fn::weekday   ,      {osl::glyph::fabric   ,   {color::yellow            ,color::reset }}},
    {rem::fn::month     ,      {osl::glyph::chronos  ,   {color::white             ,color::reset }}},
    {rem::fn::dayname   ,      {osl::glyph::star5    ,   {color::white             ,color::reset }}},
    {rem::fn::day       ,      {osl::glyph::star5    ,   {color::white             ,color::reset }}},
    {rem::fn::monthnum  ,      {osl::glyph::star5    ,   {color::white             ,color::reset }}},
    {rem::fn::year      ,      {osl::glyph::star5    ,   {color::white             ,color::reset }}}

};

glyph::type glyph::scan(const std::string& ghname)
{

    for (auto& [N,Str] : glyph_dict)
    {
        if(ghname == Str) return N;
    }
    return 0;
}

std::pair<bool, glyph::type> glyph::scan_name(const std::string& glyph_name)
{
    for (auto& [N,Str] : glyph_dict)
    {
        if(glyph_name == Str) return {true, N};
    }
    return {false, 0};
}



std::string glyph::name(type gh)
{
    return glyph_dict[gh];
}


}

std::pair<osl::glyph::type, osl::color::pair> rem::type_attributes(rem::type ty)
{
    return types_database[ty];
}

std::pair<osl::glyph::type, osl::color::pair> rem::return_code_attributes(rem::code cod)
{
    return codes_database[cod];
}

std::pair<osl::glyph::type, osl::color::pair> rem::function_attributes(rem::fn fn)
{
    return functions_database[fn];
}

std::pair<osl::glyph::type, osl::color::pair> rem::action_attributes(rem::action a)
{
    return actions_color_db[a];
}