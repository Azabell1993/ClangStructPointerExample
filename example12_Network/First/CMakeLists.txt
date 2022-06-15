project(First C)
cmake_minimum_required(VERSION 3.22)

include(FindPkgConfig)
pkg_check_modules(GLIB glib-2.0 REQUIRED)
pkg_check_modules(GTK gtk4 REQUIRED)
include_directories(/usr/local/Cellar/glib/2.72.1/include/glib-2.0)
include_directories(/usr/local/Cellar/gtk4/4.6.3/include/gtk-4.0)
######
#gcc -I/usr/local/Cellar/mysql/8.0.29/include/mysql -lmysqlclient main.c  -Wall -Werror -o main
include_directories(/usr/local/Cellar/mysql/8.0.29/include/mysql)
######
include_directories(/usr/local/Cellar/cairo/1.16.0_5/include/cairo)
include_directories(/usr/local/Cellar/pango/1.50.6/include/pango-1.0)
include_directories(/usr/local/Cellar/freetype/2.12.1/include/freetype2)
include_directories(/usr/local/Cellar/mysql/8.0.29/include/mysql)
include_directories(/usr/local/Cellar/gtk4/4.6.4/include/gtk-4.0)
include_directories(/usr/local/Cellar/harfbuzz/4.3.0/include/harfbuzz)
include_directories(/usr/local/Cellar/gdk-pixbuf/2.42.8/include/gdk-pixbuf-2.0)
include_directories(/usr/local/Cellar/graphene/1.10.8/include/graphene-1.0)
include_directories(/usr/local/Cellar/graphene/1.10.8/lib/graphene-1.0/include)
#######

set(CMAKE_C_STANDARD 99)
set(CMAKE_APPLE_SILICON_PROCESS, arm64)
set(CMAKE_OSX_ARCHITECTURES, arm64)
set(CMAKE_C_STANDARD 11)
set(SOURCE_FILES main.c)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c11")

find_package(PkgConfig REQUIRED)

#c_main.c -> 메인파일
add_executable(hello main.c)
target_link_libraries(hello PRIVATE ${GTK_LIBRARIES})
target_compile_definitions(hello PRIVATE ${GTK_CFLAGS_OTHER})
target_include_directories(hello PRIVATE ${GTK_INCLUDE_DIRS})
target_link_directories(hello PRIVATE ${GTK_LIBRARY_DIRS})

#FirstProgram -> 프로젝트 이름
add_executable(First  main.c)

target_link_libraries(First
        -mfpmath=sse -msse -msse2
        -I/usr/local/Cellar/mysql/8.0.29/include/mysql
        -I/usr/local/Cellar/cairo/1.16.0_5
        -I/usr/local/Cellar/gtk+/2.24.33
        -I/usr/local/Cellar/glib/2.72.1
        -I/usr/local/include/**
        -I/usr/local/Cellar/**
        -I/usr/local/opt/**
        -I/usr/local/include/glib-2.0
        -L/usr/local/lib -lglib-2.0
        -I/usr/local/Cellar/pango/1.50.6
        -I/usr/local/Cellar/freetype/2.12.1
        -I/usr/local/Cellar/mysql/8.0.29
        -I/usr/local/Cellar/gtk4/4.6.4
        -I/usr/local/Cellar/harfbuzz/4.3.0
        -I/usr/local/Cellar/gdk-pixbuf/2.42.8
        -I/usr/local/Cellar/graphene/1.10.8
        -lcairo -lgraphene-1.0 -lgdk_pixbuf-2.0 -lintl -liconv -lmysqlclient
        -lgtk-4 -lpangocairo-1.0 -lpango-1.0 -lharfbuzz -lgdk_pixbuf-2.0 -lcairo-gobject -lcairo -lgraphene-1.0 -lgio-2.0 -lgobject-2.0 -lglib-2.0
        -Wall -Werror
        )
