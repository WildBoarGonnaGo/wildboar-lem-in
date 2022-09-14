/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 21:32:10 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/14 17:28:15 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph/depth_first_search.h"
#include "graph/stack.h"
#include "queue/queue.h"
#include "bfs/bfs.h"
#include <stdio.h>

typedef struct s_arr_struct
{
	int	*arr;
	int	size;
	int	stp;
	int	main_path;
}	t_arr_struct;

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

void			list_midst_add(t_list **set, t_list **unit)
{
	(*unit)->next = (*set)->next;
	(*set)->next = *unit;
}

t_arr_struct 	*arr_path(t_bfs *bfs, int *v, int end)
{
	t_stack			*stack;
	t_arr_struct	*res;
	int				len;

	if (!bfs)
		return (NULL);
	res = (t_arr_struct *)malloc(sizeof(t_arr_struct));
	stack = bfs_path_to(bfs, v);
	res->size = bfs_dist_to(bfs, *v) + 2;
	len = -1;
	res->arr = (int *)malloc(sizeof(int) * res->size);
	while (++len < res->size - 1)
		res->arr[len] = *(int *)pop(&stack);
	res->arr[len] = end;
	res->stp = res->arr[0];
	delete_stack(&stack);
	return (res);
}

void	list_priority_push(t_list **list, t_bfs *bfs,
						   t_st_bag *bag, int end)
{
	t_data	*data;
	t_data	*check;
	t_list	*roll;

	data = (t_data *)bag->node->content;
	if (!*list)
	{
		check = (t_data *)bag->node->content;
		roll = ft_lstnew(arr_path(bfs, &check->indx, end));
		ft_lstadd_back(list, roll);
	}
	else
	{
		roll = *list;
		while (roll->next)
		{
			check = (t_data *)roll->next->content;
			if (bfs_dist_to(bfs, check->indx)
				< bfs_dist_to(bfs, data->indx))
			{
				roll = ft_lstnew(arr_path(bfs, &check->indx, end));
				list_midst_add(&roll, &roll);
			}
		}
		check = (t_data *)roll->next->content;
		roll = ft_lstnew(arr_path(bfs, &check->indx, end));
		if (bfs_dist_to(bfs, check->indx)
			< bfs_dist_to(bfs, data->indx))
			ft_lstadd_front(list, roll);
		else
			ft_lstadd_back(list, roll);
	}
}

t_list	*routing(t_graph *graph)
{
	t_st_bag		*bag;
	t_bfs			*bfs;
	t_bfs			*start_bfs;
	t_list			*roll;
	t_data			*data;
	t_list			*list;
	t_arr_struct	*warr;

	bag = adj(graph, graph->end);
	start_bfs = new_bfs(graph, graph->start);
	roll = bag->node->next;
	list = NULL;
	while (roll)
	{
		data = (t_data *)roll->content;
		bfs = new_bfs(graph, data->indx);
		if (bfs_has_path_to(bfs, graph->start))
			list_priority_push(&list, start_bfs,
							   adj(graph, data->indx),
							   graph->end);
		warr = (t_arr_struct *)list->content;
		warr->main_path = 1;
		roll = roll->next;
		delete_bfs(&bfs);
	}
	if (list)
	{
		roll = list->next;
		while (roll)
		{
			warr = (t_arr_struct *)roll->content;
			warr->main_path = 0;
			roll = roll->next;
		}
	}
	delete_bfs(&start_bfs);
	return (list);
}

static int	getnumsize(long n)
{
	int size;

	size = 0;
	if (!n)
		return (1);
	if (n < 0)
	{
		n *= -1;
		++size;
	}
	while (n /= 10)
		++size;
	return (++size);
}

void	ft_stack_itoa(char **str, long n, int *r)
{
	long	val;
	int		size;

	val = n;
	size = getnumsize(val);
	*r += size;
	val *= (n < 0) ? -1 : 1;
	*(*str + size--) = '\0';
	while (size >= 0)
	{
		if (!size && n < 0)
		{
			*(*str + size) = '-';
			break ;
		}
		*(*str + size) = val % 10 + 48;
		val /= 10;
		--size;
	}
}

t_list	*forwarding(t_list **list_path, t_graph **graph)
{
	t_st_bag		**adj;
	int				num[6];
	t_list			*roll;
	t_arr_struct	*aux;
	t_data			*data[2];
	char			str[512];
	char			*aux_str;

	adj = (*graph)->adj;
	if (!list_path || !*list_path)
		err_println_str("routes can't be established");
	ft_bzero(str, 512);
	roll = *list_path;
	num[4] = 0;
	while (roll)
	{
		aux = (t_arr_struct *)roll->content;
		num[0] = aux->stp;
		num[1] = aux->size;
		if (!num[0] && !aux->main_path && aux->size - 1 > (*graph)->ants_num)
			break ;
		data[0] = (t_data *)adj[aux->arr[num[0]]]->node->content;
		while (!data[0]->ants)
			data[0] = (t_data *)adj[aux->arr[++num[0]]]->node->content;
		aux->stp = num[0];
		num[2] = 1;
		while (num[0] < num[1] - 1)
		{
			data[0] = (t_data *)adj[aux->arr[num[0]]]->node->content;
			data[1] = (t_data *)adj[aux->arr[num[0] + 1]]->node->content;
			if (!data[1]->ants || queue_is_empty(data[1]->ants))
				num[2] = 0;
			if (!num[0])
				--(*graph)->ants_num;
			if (data[0]->ants && !queue_is_empty(data[0]->ants))
			{
				num[3] = *(int *)queue_peek(data[0]->ants);
				if (!data[1]->ants)
					data[1]->ants = new_queue();
				enqueue(&data[1]->ants, dequeue(&data[0]->ants));
				if (num[4])
				{
					str[num[4]++] = ' ';
				}
				str[num[4]++] = 'L';
				aux_str = str + num[4];
				ft_stack_itoa(&aux_str, num[3], &num[4]);
				str[num[4]++] = '-';
				num[3] = -1;
				num[5] = ft_strlen(data[1]->name);
				while (++num[3] < num[5])
					str[num[4]++] = data[1]->name[num[3]];
				if (queue_is_empty(data[0]->ants))
					delete_queue(&data[0]->ants);
			}
			if (!num[2])
				break ;
			++num[0];
		}
		roll = roll->next;
	}
	if (!str[0])
		return (NULL);
	str[num[4]] = '\n';
	return (ft_lstnew(ft_strdup(str)));
}

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