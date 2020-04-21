cmake_minimum_required(VERSION 3.15)
project(conf_reader C)

set(CMAKE_C_STANDARD 11)

include_directories(Includes)
include_directories(Sources)

add_executable(conf_reader
    Includes/conf.h
    Includes/list.h
    Includes/structures.h
    Sources/check_file.c
    Sources/check_uniq.c
    Sources/conf.c
    Sources/conf.h
    Sources/conf_help.c
    Sources/conf_reload.c
    Sources/create.c
    Sources/create_2.c
    Sources/create_3.c
    Sources/create_env.c
    Sources/create_job.c
    Sources/ft.c
    Sources/ft_strsplit.c
    Sources/get_nl.c
    Sources/list.c
    Sources/list.h
    Sources/list_2.c
    Sources/main.c
    Sources/str.c
    Sources/structures.h
    Sources/task_delete.c)
