cmake_minimum_required(VERSION 3.26)
project(Chapter_5 C)

set(CMAKE_C_STANDARD 11)

add_executable(Chapter_5
        duplicating_fd.c
        fd_openfiles_rel.c
        getflags.c
        io_spec_offset.c
        scatter_gather_io.c
        t_readv.c
        t_truncate.c)
