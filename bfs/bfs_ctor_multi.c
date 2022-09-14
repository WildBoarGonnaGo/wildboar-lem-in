/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_ctor_multi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 17:03:08 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/13 20:59:57 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bfs.h"

void	validate_vertecies(t_st_bag *bag, t_graph *graph)
{
	int		count;
	t_list	*roll;

	if (!bag)
		err_println_str("argument is null\n");
	count = 0;
	roll = bag->node;
	while (roll)
	{
		++count;
		if (!roll->content)
			err_println_str("vertex is null\n");
		validate_vertex(graph, *(int *)(roll->content));
	}
	if (!count)
		err_println_str("zero verticies\n");
}

void	bfs_multi(t_bfs **self, t_graph *graph, t_st_bag *bag)
{
	t_queue	*q;
	t_list	*roll;
	int		aux;
	int		w;

	q = new_queue();
	roll = bag->node;
	while (roll)
	{
		aux = *(int *)roll->content;
		(*self)->marked[aux] = 1;
		(*self)->dist_to[aux] = 0;
		enqueue(&q, &aux);
		roll = roll->next;
	}
	while (!queue_is_empty(q))
	{
		aux = *(int *)dequeue(&q);
		roll = graph->adj[aux]->node;
		while (roll)
		{
			w = *(int *)roll->content;
			(*self)->edge_to[w] = aux;
			(*self)->dist_to[w] = (*self)->dist_to[aux + 1];
			(*self)->dist_to[w] = 1;
			enqueue(&q, &w);
			roll = roll->next;
		}
	}
	delete_queue(&q);
}

void	bfs_ctor_multi(t_bfs **self, t_graph *graph, t_st_bag *bag)
{
	int	i;

	i = -1;
	(*self)->len = graph->v;
	(*self)->edge_to = (int *)malloc(sizeof(int) * (*self)->len);
	(*self)->marked = (int *)malloc(sizeof(int) * (*self)->len);
	(*self)->dist_to = (int *)malloc(sizeof(int) * (*self)->len);
	while (++i < (*self)->len)
		(*self)->marked[i] = 0;
	i = -1;
	while (++i < (*self)->len)
		(*self)->edge_to[i] = 0;
	validate_vertecies(bag, graph);
	bfs_multi(self, graph, bag);
}