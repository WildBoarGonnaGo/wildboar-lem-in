cmake_minimum_required(VERSION 3.7.2)
project(lem-in C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_COMPILER gcc)
add_compile_options(-Wall -Wextra -Werror -g -O0 -D BUFFER_SIZE=512)
# file(GLOB LIBFT_SRC ./libft/*.c)

add_executable(${PROJECT_NAME} add.c arr_path.c data_dtor.c
    check_prog_input.c del_list.c del_list2.c delete_arrs.c
    delete_bag.c delete_bag_2.c delete_bag_iterator.c delete_data.c
    err_println.c err_println_str.c forwarding.c ft_stack_itoa.c
    has_next.c is_empty.c list_priority_push.c main.c new_bag.c
    new_bag_iterator.c next.c routing.c size.c st_bag_copy_assign.c
    st_bag_ctor.c st_bag_dtor.c st_bag_dtor_2.c t_st_bag_iterator_ctor.c t_st_bag_iterator_dtor.c
    delete_bag_iterator.c gnl/get_next_line.c del_list.c del_list2.c

        gnl/get_next_line_utils.c graph/add_edge.c graph/add_vertex.c
        graph/adj.c graph/alloc_array.c graph/check_input_data.c graph/delete_array2d.c
        graph/delete_graph.c graph/delete_graph_2.c
        graph/delete_line.c
        graph/get_number.c
        graph/graph_ctor_in.c graph/graph_dtor.c graph/graph_dtor_2.c
        graph/graph_init.c
        graph/is_number.c graph/line_analisys.c graph/mark_end.c graph/mark_start.c
        graph/new_graph.c
        graph/parse_line.c
        graph/to_string.c graph/validate_vertex.c

        dfs/delete_dfs_data.c dfs/dfs_ctor.c dfs/dfs_dtor.c dfs/has_path_to.c
        dfs/new_dfs_data.c

        stack/delete_stack.c stack/new_stack.c stack/peek.c stack/peek.c
        stack/pop.c stack/push.c stack/stack_ctor.c stack/stack_dtor.c
        stack/stack_is_empty.c

        queue/delete_queue.c queue/dequeue.c queue/enqueue.c queue/new_queue.c
        queue/queue_peek.c queue/queue_ctor.c queue/queue_dtor.c queue/queue_is_empty.c

        bfs/bfs.c bfs/bfs_ctor.c bfs/bfs_ctor_multi.c bfs/bfs_data_init.c bfs/bfs_dist_to.c bfs/bfs_dtor.c
        bfs/bfs_has_path_to.c bfs/bfs_path_to.c bfs/bfs_validate_vertex.c
        bfs/delete_bfs.c bfs/new_bfs.c bfs/new_bfs_multi.c
        )
target_link_libraries(${PROJECT_NAME} PUBLIC -lft)
target_link_directories(${PROJECT_NAME} PUBLIC libft)
target_include_directories(${PROJECT_NAME} PUBLIC
        ${PROJECT_SOURCE_DIR}/libft
        ${PROJECT_SOURCE_DIR}/gnl
        ${PROJECT_SOURCE_DIR}/graph
        ${PROJECT_SOURCE_DIR}/queue
        ${PROJECT_SOURCE_DIR}/bfs
        ${PROJECT_SOURCE_DIR}/dfs
        ${PROJECT_SOURCE_DIR}/stack)