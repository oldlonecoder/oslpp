
# osl++ project ( Formely Old Serge Lussier ++)

# Roadmap of this hobby project

### Exploring, Learning and write a set of C++ framework of (from my own) libraries/ or a single big static lib

## core support classes ( namespace osl ) main directory( for ex.: #include <osl++/string.h>)

    - [class osl::string]
        Composite std::string accumulator for serializing and formatting supported components
    - [osl::color]
        Ansi (and future HTML) colours mnemonics.
    - [rem :  Coherant and consistent Global Return Codes Mnemonics and Enumerations]
        messages and logs.
        Note:   The osl::rem class is the kernel of the later/projected logger book API
    - [class osl::signals::action; osl::signals::signal ]
        C++ template header for basic signal-slots.
        -> Not fully multi-threads yet, but I am starting to explore using a working notify signals across threads.
    - [class osl::ui::application]
        Base application class..., will holds and manage the config data of the components and events queu, and will manage a threads pool.
    - [ osl::ui::geometry classes ]
        {osl::ui::cxy, osl::ui::size, osl::ui::rectangle, osl::ui::string2d} Base 2D geometry components.
    - [class  osl::object]
        Base Object class on the parent-child relational logistic ( smart-pointers not used there. Too much overload (yet?) )
    -[class  osl::glyph and  osl::accent_fr]
        Actually, some hardcoded unicode and french accent glyphes. Waiting to find a coherant and definitive unicode API.
    -[ osl::cmd::cmd_switch osl::cmd::line,  with notify-hook]
        Developping my own command-line arguments processor.
        -> It is very hard to create a coherent logistic-model. POSIX or not, the syntax is a mess because there is NO real strict format rules.
    
---

## rem : (namespace rem) Return Enumeration Mnemonics
    - Consistent and Coherant Global Enumeration Mnemonics system.
---

## est : (namespace osl::est) Expression SyntaxTree
    - Mathematical Expression Parser and Compiler.
---

## tui : (namespace osl::ui): Standard Ansi Console UI using ...Standard Ansi Codes
    -[namespace osl::terminal]
        Related console/terminal for init, config and finish
    -[class osl::terminal::vchar ]
        Backbuffer packing
        32 bits packed char to represent the character and its attributes on screen
    -[class osl::ui::widget **]
        - Base ui element (widget) object
    -[ui classes]
        All derived from ui::widget so they draw, act and interact according to their ...class.
---

### Note

* Backbuffer commits on console are converted to ansi256 (true color) ESC sequences for rendering the text and attributes.
* Not very compatible to non-graphical 16 colors raw tty terminals.
* Management of the ui::widget/windows hierarchy is at application level, not at system level.
* tui is NOT a text console processes/desktop/window manager despite I use it to manage one single application and its renderings
* tui is an Application TUI API using elements (Widgets) on the console for its user interface.
* tui is Not a fast UI renderer especially on Microsoft Windows Terminal where it is very,very, v-e-r-y slow.

---

## dlapi : Basic support for dynamic dll/so components (future) library loader

    Very basic plugins like support manager. [not started yet]
    -[class osl::dlapi]
        File-level handling of object; Shared-object/dll/dylib contents loader.
    -[class osl::dl::plugin ]
        Abstract bridge object between the library loader and the C++ components

    Since there is absolutely NO framework logistic at all (such as Windows/COM;OLE, Qt,KDE, [IOS/OSX]:Cocoa ), osl::dlapi must be implemented in higher derived implementation using std::function, lambdas and variadic template/ params.
    Maybe there will be a kind of plugin framework implemented in the osl .. Stay tuned ...:)
---

## todo
    ... lots todo! 
---

* Unless otherwise specified, all code in this project is written by the author (Serge oslsier)  and no one else (...unless otherwise specified...).
---
copyrights ...,2025,... Serge oslsier