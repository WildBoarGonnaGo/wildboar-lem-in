cmake_minimum_required(VERSION 3.7.2)
project(lem-in C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_COMPILER gcc)
add_compile_options(-Wall -Wextra -Werror -g -O0 -D BUFFER_SIZE=512)
# file(GLOB LIBFT_SRC ./libft/*.c)

add_executable(${PROJECT_NAME} add.c delete_bag.c
    err_println.c err_println_str.c has_next.c
    is_empty.c main.c new_bag.c new_bag_iterator.c
    next.c size.c st_bag_copy_assign.c st_bag_ctor.c st_bag_dtor.c
    t_st_bag_iterator_ctor.c t_st_bag_iterator_dtor.c
    delete_bag_iterator.c gnl/get_next_line.c del_list.c del_list2.c
        gnl/get_next_line_utils.c graph/add_edge.c graph/add_vertex.c
        graph/adj.c graph/alloc_array.c graph/check_input_data.c graph/delete_array2d.c
        graph/delete_dfs_data.c graph/delete_graph.c graph/delete_line.c graph/delete_stack.c
        graph/dfs_ctor.c graph/dfs_dtor.c graph/get_number.c
        graph/graph_ctor_in.c graph/graph_dtor.c graph/graph_init.c graph/stack_is_empty.c
        graph/is_number.c graph/line_analisys.c graph/mark_end.c graph/mark_start.c
        graph/new_dfs_data.c graph/new_graph.c graph/new_stack.c graph/peek.c graph/pop.c
        graph/push.c graph/stack_ctor.c graph/stack_dtor.c graph/parse_line.c
        graph/to_string.c graph/validate_vertex.c
        queue/delete_queue.c queue/dequeue.c queue/enqueue.c queue/new_queue.c
        queue/peek.c queue/queue_ctor.c queue/queue_dtor.c queue/stack_is_empty.c)
target_link_libraries(${PROJECT_NAME} PUBLIC -lft)
target_link_directories(${PROJECT_NAME} PUBLIC libft)
target_include_directories(${PROJECT_NAME} PUBLIC
        ${PROJECT_SOURCE_DIR}/libft
        ${PROJECT_SOURCE_DIR}/gnl
        ${PROJECT_SOURCE_DIR}/graph
        ${PROJECT_SOURCE_DIR}/queue)