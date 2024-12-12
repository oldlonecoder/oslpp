cmake_minimum_required(VERSION 3.13..3.29 FATAL_ERROR)

project("oslpp" VERSION 0.1.0 LANGUAGES CXX)
set(Target "osl")
set(CMAKE_CXX_STANDARD 20)

message("Entering tools lib configuration:")
include(GNUInstallDirs)
SET(CMAKE_EXPORT_COMPILE_COMMANDS ON)


message("Current SourceDir:" ${CMAKE_CURRENT_SOURCE_DIR})


add_library("${Target}++" STATIC

            #-----------TOOLS:
            include/${Target}++/_start_.h       src/rem.cc 
            include/${Target}++/colors.h        src/colors.cc
            include/${Target}++/glyphes.h       src/glyphes.cc
            include/${Target}++/cadres.h        src/cadres.cc
            include/${Target}++/string.h        src/string.cc
            include/${Target}++/journal/logger.h src/journal/logger.cc
            include/${Target}++/object.h        src/object.cc
            include/${Target}++/geometry.h      src/geometry.cc
            include/${Target}++/actions.h
            include/${Target}++/cmdargs.h       src/cmdargs.cc
            include/${Target}++/sscan.h         src/sscan.cc
            include/${Target}++/expect.h
            # # --------- LEXER:
            include/${Target}++/lexer/lexer_types.h     src/lexer/lexer_types.cc
            include/${Target}++/lexer/token_data.h      src/lexer/token_data.cc
            include/${Target}++/lexer/tokens_table.h    src/lexer/tokens_table.cc
            include/${Target}++/lexer/lexer.h           src/lexer/lexer.cc
            # # --------- EST : { Expression Syntax Tree }
            include/${Target}++/est/alu.h           src/est/alu.cc
            include/${Target}++/est/node.h          src/est/node.cc
            include/${Target}++/est/variable.h      src/est/variable.cc
            include/${Target}++/est/bloc.h          src/est/bloc.cc
            include/${Target}++/est/expression.h    src/est/expression.cc
            # # --------- TUI :
            include/${Target}++/tui/terminal.h src/tui/terminal.cc
            include/${Target}++/tui/vchar.h src/tui/terminal.vchar.cc
            include/${Target}++/tui/events.h src/tui/events.cc
            include/${Target}++/tui/widgets/threads_pool.h src/tui/widgets/threads_pool.cc
            include/${Target}++/tui/application.h src/tui/application.cc
            include/${Target}++/tui/widget.h src/tui/widget.cc src/tui/widget_painter.cc
            include/${Target}++/tui/widgets/label.h src/tui/widgets/label.cc
            include/${Target}++/tui/widgets/icon.h src/tui/widgets/icon.cc
            include/${Target}++/tui/widgets/window.h src/tui/widgets/window.cc
            include/${Target}++/tui/widgets/screen.h src/tui/widgets/screen.cc
            include/${Target}++/tui/widgets/status_bar.h src/tui/widgets/status_bar.cc
            include/${Target}++/tui/widgets/input_track.h src/tui/widgets/input_track.cc
            include/${Target}++/tui/io/ansi_colours_parser.h src/tui/io/ansi_colours_parser.cc
            include/${Target}++/tui/io/ansi_parser.h src/tui/io/ansi_parser.cc
            include/${Target}++/tui/io/polling.h src/tui/io/polling.cc
            include/${Target}++/tui/tuxns.h             src/tui/tuxns.cc
            
)


target_include_directories("${Target}++" PUBLIC
                           "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
                           $<INSTALL_INTERFACE:include>
)

target_compile_definitions("${Target}++" PUBLIC "${Target}++_DEBUG=$<CONFIG:Debug>")
include(GenerateExportHeader)
generate_export_header("${Target}++" EXPORT_FILE_NAME "${Target}++_export")

IF (EXISTS "${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json")
    EXECUTE_PROCESS(COMMAND ${CMAKE_COMMAND} -E copy_if_different
                    ${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json
    )
ENDIF ()


target_link_libraries("${Target}++" ${CMAKE_DL_LIBS} ) # and other system dependencies...


# add_executable(lus++.app
#     tddv.app/tddv.h tddv.app/tddv.cc
# )

# target_link_libraries(lus++.app lus)


install(TARGETS "${Target}++"
        EXPORT "${Target}++"
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
        INCLUDES DESTINATION include)



install(DIRECTORY
        include/
        DESTINATION "${CMAKE_INSTALL_PREFIX}/include"
)

add_subdirectory(diagnostic)

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
