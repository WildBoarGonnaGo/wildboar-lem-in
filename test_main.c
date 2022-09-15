/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 21:32:10 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/15 13:11:19 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph/depth_first_search.h"
#include "graph/stack.h"
#include "queue/queue.h"
#include <stdio.h>
#include "lem_in.h"

int 	main(int argc, char *argv[]) {
	t_st_bag			*bag;
	t_st_bag_iterator 	*it;
	t_graph 			*graph;
	int					check;
	char				*graph_str;
	char				*path_str;
	t_dfs_data			*graph_rim;
	int					src_v;
	int					*test_stack_arr;
	t_stack				*test_stack;
	t_queue				*test_queue;
	t_list				*final[3];
	t_arr_struct		*rage;

	check = check_prog_input(argc, argv);
	if (!check)
		err_println_str("wrong argument syntax or wrong input file extension (.map)");
	else {
		ft_putendl_fd(argv[1], 1);
		ft_putendl_fd(argv[2], 1);
	}
	bag = new_bag();
	add(&bag, "Kono");
	add(&bag, "Dio");
	add(&bag, "Da!");
	it = new_bag_iterator(bag);
	while (has_next(it))
	{
		ft_putendl_fd(it->it->content, 1);
		next(&it);
	}
	ft_putendl_fd(it->it->content, 1);
	delete_bag(&bag, del_list);
	delete_bag_iterator(&it);

 	graph = new_graph();
	graph_str = to_string(graph);
	ft_putendl_fd(graph_str, 1);

	src_v = 0;
	graph_rim = new_dfs_data(graph, src_v);
	printf("Init vertex: %d\n", graph->start);
	printf("List of connected vertecies to %s: ", (char *)((t_data *)graph->adj[graph->start]->node->content)->name);
	for (int i = 0; i < graph->v; ++i)
	{
		if (i == src_v)
			continue ;
		if (graph_rim->marked[i])
			printf("%s ", (char *)((t_data *)graph->adj[i]->node->content)->name);
	}
	ft_putchar_fd('\n', 1);

	//ants move on!
	final[0] = routing(graph);
	final[1] = forwarding(&final[0], &graph);
	while (final[1])
	{
		path_str = (char *)final[1]->content;
		if (*path_str)
		write(1, path_str, ft_strlen(path_str));
		final[2] = final[1];
		final[1] = forwarding(&final[0], &graph);
		ft_lstdelone(final[2], del_list2);
	}
	final[2] = final[0];
	while (final[2])
	{
		rage = (t_arr_struct *)final[2]->content;
		if (rage->arr)
		{
			free(rage->arr);
			rage->arr = NULL;
		}
		final[2] = final[2]->next;
	}
	ft_lstclear(&final[0], del_list2);
	delete_graph_2(&graph);
	delete_dfs_data(&graph_rim);

	//stack test
	test_stack_arr = (int *)malloc(sizeof(int) * 10);
	for (int i = 0; i < 10; ++i)
		test_stack_arr[i] = i + 1;
	test_stack = new_stack();
	for (int i = 0; i < 10; ++i)
		push(&test_stack, &test_stack_arr[i]);
	printf("\nis test stack empty %s\n", stack_is_empty(test_stack) ? "true" : "false");
	printf("stack elements:");
	for (int i = 0; i < 10; ++i)
	{
		int *aux = (int *)pop(&test_stack);
		printf(" %d", *aux);
	}
	printf("\nis test stack empty %s\n\n", stack_is_empty(test_stack) ? "true" : "false");
	delete_stack(&test_stack);

	//queue test
	test_queue = new_queue();
	for (int i = 0; i < 10; ++i)
		enqueue(&test_queue, &test_stack_arr[i]);
	printf("\nis test queue empty %s\n", queue_is_empty(test_queue) ? "true" : "false");
	printf("queue elements:");
	for (int i = 0; i < 10; ++i)
	{
		int *aux = (int *)dequeue(&test_queue);
		printf(" %d", *aux);
	}
	printf("\nis test queue empty %s\n", queue_is_empty(test_queue) ? "true" : "false");
	delete_queue(&test_queue);
	free(test_stack_arr);
	test_stack_arr = NULL;
	free(graph_str);
	graph_str = NULL;
	return (0);
}