
message("Configuring the Diagnostic subdir")

add_executable("${Target}++.diagnostic.app"
    diagnostic.h diagnostic.cc
)



target_link_libraries("${Target}++.diagnostic.app" "${Target}++")
