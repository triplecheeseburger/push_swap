cmake_minimum_required(VERSION 3.21)
project(push_swap C)

link_directories(/Users/hakim/push_swap_git/libft)
include_directories(/Users/hakim/push_swap_git/includes)
#link_directories(/Users/hangyulkim/42/42cursus/2_circle/push_swap/libft)
#include_directories(/Users/hangyulkim/42/42cursus/2_circle/push_swap/includes)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-Wall -Wextra -Werror -I./includes")

add_executable(push_swap
        main.c
        deque/deque_2.c
        deque/deque_1.c
        operation/swap_n_push.c
        operation/rotate_n_reverse.c
        parser/parse.c
        parser/parsing_utils.c
        utils/lis.c
        utils/merge_sort.c
        utils/utils.c
        utils/utils_2.c
        sorting/sort_shorts.c
        sorting/push_swap.c
        sorting/sort_utils.c
        sorting/sort_gets.c
        sorting/sort_big.c
        sorting/sort_big_pos.c)

add_executable(checker
        deque/deque_2.c
        deque/deque_1.c
        parser/parse.c
        parser/parsing_utils.c
        utils/merge_sort.c
        utils/utils.c
        utils/utils_2.c
        sorting/sort_gets.c
        get_next_line/get_next_line.c
        get_next_line/get_next_line_utils.c
        checkerdir/checker.c
        checkerdir/checker_oper_1.c
        checkerdir/checker_oper_2.c)

target_link_libraries (push_swap ft)
target_link_libraries (checker ft)

