project(example00Struct C)

cmake_minimum_required(VERSION 3.22)

include(FindPkgConfig)
pkg_check_modules(GLIB glib-2.0 REQUIRED)
pkg_check_modules(GTK gtk4 REQUIRED)
include_directories(/usr/local/Cellar/glib/2.72.1/include/glib-2.0)
include_directories(/usr/local/Cellar/gtk4/4.6.3/include/gtk-4.0)

set(CMAKE_C_STANDARD 99)

#c_main.c -> 메인파일
add_executable(hello main.c)
target_link_libraries(hello PRIVATE ${GTK_LIBRARIES})

target_compile_definitions(hello PRIVATE ${GTK_CFLAGS_OTHER})

target_include_directories(hello PRIVATE ${GTK_INCLUDE_DIRS})
target_link_directories(hello PRIVATE ${GTK_LIBRARY_DIRS})

#FirstProgram -> 프로젝트 이름
add_executable(example00Struct  main.c azabell_glib_program.h)
target_link_libraries(example00Struct
        -I/usr/local/Cellar/cairo/1.16.0_5
        -I/usr/local/Cellar/gtk+/2.24.33
        -I/usr/local/Cellar/glib/2.72.1
        -I/usr/local/include/**
        -I/usr/local/Cellar/**
        -I/usr/local/opt/**
        -I/usr/local/include/glib-2.0
        -L/usr/local/lib -lglib-2.0
        -lcairo -lgraphene-1.0 -lgdk_pixbuf-2.0 -lintl -liconv)