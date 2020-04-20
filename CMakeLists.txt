cmake_minimum_required(VERSION 3.15)
project(conf_reader C)

set(CMAKE_C_STANDARD 99)

include_directories(Includes)

add_executable(conf_reader Sources/conf.c Includes/conf.h Sources/ft.c Includes/structures.h Sources/check_file.c Sources/str.c Sources/get_nl.c Includes/list.h Sources/list.c Sources/list_2.c Sources/create_job.c Sources/create.c Sources/ft_strsplit.c Sources/create_2.c Sources/create_3.c Sources/create_env.c Sources/main.c Sources/conf_help.c Sources/check_uniq.c Sources/task_delete.c Sources/conf_reload.c)