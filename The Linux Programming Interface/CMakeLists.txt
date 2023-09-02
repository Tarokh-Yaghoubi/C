cmake_minimum_required(VERSION 3.26)
project(The_Linux_Programming_Interface C)

set(CMAKE_C_STANDARD 11)

include_directories("Chapter 3/headers")

add_executable(The_Linux_Programming_Interface
        "Chapter 3/headers/error_functions.c"
        "Chapter 3/headers/error_functions.h"
        "Chapter 3/headers/get_num.c"
        "Chapter 3/headers/get_num.h"
        "Chapter 3/headers/tlpi_hdr.h"
        "Chapter 3/bad_exclusive_open.c"
        "Chapter 3/copy.c"
        "Chapter 3/fcntl_getsettings.c"
        "Chapter 3/getid.c"
        "Chapter 4/seek_io.c"
        "Chapter 5/getflags.c"
        callback_example.c
        sys_read.c)
