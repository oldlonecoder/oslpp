cmake_minimum_required(VERSION 3.13..3.29 FATAL_ERROR)

project("oslpp" VERSION 0.1.0 LANGUAGES CXX)
set(Target "osl")
set(CMAKE_CXX_STANDARD 20)

message("Entering tools lib configuration:")
include(GNUInstallDirs)
SET(CMAKE_EXPORT_COMPILE_COMMANDS ON)


message("Current SourceDir:" ${CMAKE_CURRENT_SOURCE_DIR})


add_library("${Target}" STATIC

            #-----------TOOLS:
            include/${Target}++/_start_.h       src/rem.cc 
            include/${Target}++/colors.h        src/colors.cc
            include/${Target}++/glyphes.h       src/glyphes.cc
            include/${Target}++/cadres.h        src/cadres.cc
            include/${Target}++/string.h        src/string.cc
            # include/${Target}++/logger.h cc/tools/logger.cc
            include/${Target}++/object.h        src/object.cc
            # include/${Target}++/geometry.h cc/tools/geometry.cc
            # include/${Target}++/actions.h
            # include/${Target}++/cmdargs.h cc/tools/cmdargs.cc
            # include/${Target}++/sscan.h cc/tools/sscan.cc
            # # --------- LEXER:
            # include/${Target}++/lexer/lexer_types.h cc/lexer/lexer_types.cc
            # include/${Target}++/lexer/token_data.h cc/lexer/token_data.cc
            # include/${Target}++/lexer/tokens_table.h cc/lexer/tokens_table.cc
            # include/${Target}++/lexer/lexer.h cc/lexer/lexer.cc
            # # --------- EST : { Expression Syntax Tree }
            # include/${Target}++/est/alu.h cc/est/alu.cc
            # include/${Target}++/est/node.h cc/est/node.cc
            # include/${Target}++/est/variable.h cc/est/variable.cc
            # include/${Target}++/est/bloc.h cc/est/bloc.cc
            # include/${Target}++/est/expression.h cc/est/expression.cc
            # # --------- TUI :
            # include/${Target}++/tui/terminal.h cc/tui/terminal.cc
            # include/${Target}++/tui/vchar.h cc/tui/terminal.vchar.cc
            # include/${Target}++/tui/events.h cc/tui/events.cc
            # include/${Target}++/tui/application.h cc/tui/application.cc
            # include/${Target}++/tui/widget.h cc/tui/widget.cc cc/tui/widget_painter.cc
            # include/${Target}++/tui/widgets/label.h cc/tui/widgets/label.cc
            # include/${Target}++/tui/widgets/icon.h cc/tui/widgets/icon.cc
            # include/${Target}++/tui/widgets/window.h cc/tui/widgets/window.cc
            # include/${Target}++/tui/widgets/screen.h cc/tui/widgets/screen.cc
            # include/${Target}++/tui/widgets/status_bar.h cc/tui/widgets/status_bar.cc
            # include/${Target}++/tui/widgets/input_track.h cc/tui/widgets/input_track.cc
            # include/${Target}++/tui/io/ansi_colours_parser.h cc/tui/io/ansi_colours_parser.cc
            # include/${Target}++/tui/io/ansi_parser.h cc/tui/io/ansi_parser.cc
            # include/${Target}++/tui/io/polling.h cc/tui/io/polling.cc
            # include/${Target}++/tui/tuxns.h cc/tui/tuxns.cc
            # include/${Target}++/tools/expect.h
)


target_include_directories(${Target} PUBLIC
                           "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
                           $<INSTALL_INTERFACE:include>
)

target_compile_definitions(${Target} PUBLIC "${Target}_DEBUG=$<CONFIG:Debug>")
include(GenerateExportHeader)
generate_export_header(${Target} EXPORT_FILE_NAME ${Target}_export)

IF (EXISTS "${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json")
    EXECUTE_PROCESS(COMMAND ${CMAKE_COMMAND} -E copy_if_different
                    ${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json
    )
ENDIF ()


target_link_libraries(${Target} ${CMAKE_DL_LIBS} ) # and other system dependencies...


# add_executable(lus++.app
#     tddv.app/tddv.h tddv.app/tddv.cc
# )

# target_link_libraries(lus++.app lus)


install(TARGETS ${Target}
        EXPORT ${Target}
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
        INCLUDES DESTINATION include)



install(DIRECTORY
        include/
        DESTINATION "${CMAKE_INSTALL_PREFIX}/include"
)


#add_custom_target("uninstall" COMMENT "Uninstall installed files")
#add_custom_command(
#    TARGET "uninstall"
#    POST_BUILD
#    COMMENT "Uninstall files with install_manifest.txt"
#    COMMAND xargs rm -vf < install_manifest.txt || echo Nothing in
#    install_manifest.txt to be uninstalled!
#)
## Enable packaging
#set(CPACK_PROJECT_NAME ${PROJECT_NAME})
#set(CPACK_PACKAGE_NAME ${Target})
#set(CPACK_GENERATOR "TGZ")

# Include CPack
#include(CPack) # Scrap!! No way to include header files!
