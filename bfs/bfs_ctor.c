/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_ctor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:55:12 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/13 22:38:42 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bfs.h"
#include "../queue/queue.h"
#include <limits.h>

void	bfs(t_bfs **self, t_graph *graph, int s)
{
	t_queue	*q;
	int		v;
	t_list	*w;
	int		*adj_num;

	q = new_queue();
	v = -1;
	while (++v < graph->v)
		(*self)->dist_to[v] = INT_MAX;
	(*self)->dist_to[s] = 0;
	(*self)->marked[s] = 1;
	enqueue(&q, &s);

	while (!queue_is_empty(q))
	{
		v = *(int *)dequeue(&q);
		w = graph->adj[v]->node->next;
		while (w)
		{
			adj_num = &((t_data *)w->content)->indx;
			if (!(*self)->marked[*adj_num])
			{
				(*self)->edge_to[*adj_num] = v;
				(*self)->dist_to[*adj_num] = (*self)->dist_to[v] + 1;
				(*self)->marked[*adj_num] = 1;
				enqueue(&q, adj_num);
			}
			w = w->next;
		}
	}
	delete_queue(&q);
}

void	bfs_ctor(t_bfs **self, t_graph *graph, int s)
{
	int	i;

	i = -1;
	(*self)->len = graph->v;
	(*self)->edge_to = (int *)malloc(sizeof(int) * (*self)->len);
	(*self)->marked = (int *)malloc(sizeof(int) * (*self)->len);
	(*self)->dist_to = (int *)malloc(sizeof(int) * (*self)->len);
	if (!(*self)->edge_to || !(*self)->marked || !(*self)->dist_to)
		err_println(ENOMEM);
	while (++i < (*self)->len)
		(*self)->marked[i] = 0;
	i = -1;
	while (++i < (*self)->len)
		(*self)->edge_to[i] = s;
	bfs_validate_vertex(*self, s);
	bfs(self, graph, s);
}