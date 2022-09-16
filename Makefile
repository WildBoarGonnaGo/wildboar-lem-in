# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/16 16:59:54 by lchantel          #+#    #+#              #
#    Updated: 2022/09/16 20:10:22 by lchantel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC_FILE = lem-in
LIB = ./libft/libft.a

SRC =	./add.c      						\
	 	./arr_path.c						\
		./check_prog_input.c				\
		./data_dtor.c			        	\
		./del_list.c						\
		./del_list2.c						\
		./delete_arrs.c		    			\
		./delete_bag.c     					\
		./delete_bag_2.c  					\
		./delete_bag_iterator.c				\
		./delete_data.c 					\
		./err_println.c						\
		./err_println_str.c					\
		./forwarding.c						\
		./ft_stack_itoa.c					\
		./has_next.c						\
		./is_empty.c						\
		./list_priority_push.c    			\
		./new_bag.c							\
		./new_bag_iterator.c				\
		./next.c							\
		./routing.c							\
		./size.c							\
		./st_bag_copy_assign.c				\
		./st_bag_ctor.c	    				\
		./st_bag_dtor.c						\
		./st_bag_dtor_2.c  					\
		./t_st_bag_iterator_ctor.c			\
		./t_st_bag_iterator_dtor.c			\
		./bfs/bfs.c	   						\
		./bfs/bfs_ctor.c	    			\
		./bfs/bfs_ctor_multi.c				\
		./bfs/bfs_data_init.c        		\
		./bfs/bfs_dist_to.c 				\
		./bfs/bfs_dtor.c              		\
		./bfs/bfs_has_path_to.c             \
		./bfs/bfs_path_to.c              	\
		./bfs/bfs_validate_vertex.c         \
		./bfs/delete_bfs.c        			\
		./bfs/new_bfs.c      				\
		./bfs/new_bfs_multi.c               \
		./gnl/get_next_line.c             	\
		./gnl/get_next_line_utils.c  		\
		./graph/add_edge.c					\
		./graph/alloc_array.c 				\
		./graph/delete_graph.c 				\
 		./graph/get_number.c        		\
 		./graph/graph_init.c        		\
 		./graph/mark_end.c          		\
 		./graph/parse_line.c        		\
 		./graph/add_vertex.c        		\
 		./graph/check_input_data.c  		\
 		./graph/delete_graph_2.c    		\
 		./graph/graph_dtor.c        		\
 		./graph/is_number.c         		\
 		./graph/mark_start.c        		\
 		./graph/to_string.c         		\
 		./graph/adj.c               		\
 		./graph/delete_array2d.c    		\
 		./graph/delete_line.c       		\
 		./graph/graph_ctor_in.c     		\
 		./graph/graph_dtor_2.c      		\
 		./graph/line_analisys.c     		\
 		./graph/new_graph.c         		\
 		./graph/validate_vertex.c   		\
 		./queue/delete_queue.c				\
 		./queue/dequeue.c					\
 		./queue/enqueue.c					\
 		./queue/new_queue.c					\
 		./queue/queue_ctor.c				\
 		./queue/queue_dtor.c				\
 		./queue/queue_is_empty.c			\
 		./queue/queue_peek.c 				\
 		./stack/delete_stack.c				\
 		./stack/new_stack.c					\
 		./stack/peek.c						\
 		./stack/pop.c						\
 		./stack/push.c						\
 		./stack/stack_ctor.c				\
 		./stack/stack_dtor.c				\
 		./stack/stack_is_empty.c				

CC = clang
WARNS = -Wall -Wextra -Werror -O0 -D BUFFER_SIZE=512
OBJ = $(SRC:.c=.o)

$(EXEC_FILE): $(LIB) $(OBJ)
	@echo "Every funtion is compile proved ..."
	@echo "Making program executable ..."
	@$(CC) $(WARNS) ./main.c -o $(EXEC_FILE) $(OBJ) -L./libft -lft

$(LIB):
	@echo "Building libft static library ..."
	@make all bonus -C ./libft
	@echo "All functions added to static lib ..."

$(OBJ): %.o :%.c
	@echo "Check $< to be right ..."
	@$(CC) $(WARNS) -o $@ -c $<

all: $(EXEC_FILE)

clean:
	@echo "Removing all binaries ..."
	@rm -rf $(OBJ)
	@echo "Removing all libft binaries"
	@make clean -C ./libft/

fclean: clean
	@echo "Removing static library ..."
	@rm -rf $(LIB)
	@rm -rf $(EXEC_FILE)
	@echo "Removing libft static library ..."
	@make fclean -C ./libft/

re: fclean all