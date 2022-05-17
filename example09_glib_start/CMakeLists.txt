cmake_minimum_required(VERSION 3.22)
project(FirstProgram)

include(FindPkgConfig)
pkg_check_modules(GLIB glib-2.0 REQUIRED)
include_directories(/usr/local/Cellar/glib/2.72.1/include/glib-2.0)

set(CMAKE_C_STANDARD 99)

add_executable(FirstProgram c_main.c print_message.h print_message.c print_helloworld_goodbyeworld.h print_helloworld_goodbyeworld.c c_main.c)
target_link_libraries(FirstProgram -I/usr/local/include/glib-2.0 -L/usr/local/lib -lglib-2.0 -lintl -liconv)



