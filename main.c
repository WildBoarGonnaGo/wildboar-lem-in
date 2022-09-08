/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 21:32:10 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/07 17:48:20 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph/depth_first_search.h"
#include "graph/stack.h"
#include <stdio.h>

int	check_prog_input(int argc, char **input)
{
	int	len;

	if (argc < 3)
		return (0);
	if (ft_strncmp(input[1], "<", 1))
		return (0);
	len = ft_strlen(input[2]);
	if (len < 5 || ft_strncmp(".map", *(input + 2) + len - 4, 4))
		return (0);
	return (1);
}

int main(int argc, char *argv[]) {
	t_st_bag			*bag;
	t_st_bag_iterator 	*it;
	t_graph 			*graph;
	int					check;
	char				*graph_str;
	t_dfs_data			*graph_rim;
	int					src_v;
	int					*test_stack_arr;
	t_stack				*test_stack;

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
	printf("Init vertex: %d\n", src_v);
	printf("List of connected vertecies to %d: ", src_v);
	for (int i = 0; i < graph->v; ++i)
	{
		if (i == src_v)
			continue ;
		if (graph_rim->marked[i])
			printf("%d ", i);
	}
	ft_putchar_fd('\n', 1);
	delete_graph(&graph, del_list2);
	free(graph_str);
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
	printf("\nis test stack empty %s\n", stack_is_empty(test_stack) ? "true" : "false");
	delete_stack(&test_stack);
	free(test_stack_arr);
	test_stack_arr = NULL;
	free(graph_str);
	graph_str = NULL;
	return (0);
}