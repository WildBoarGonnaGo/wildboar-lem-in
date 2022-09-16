/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 11:55:14 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/16 13:34:02 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bfs.h"
#include <limits.h>
#include "../queue/queue.h"

void	bfs_routine(t_bfs **self, int *adj_num,
					int v, t_queue **q)
{
	(*self)->edge_to[*adj_num] = v;
	(*self)->dist_to[*adj_num] = (*self)->dist_to[v] + 1;
	(*self)->marked[*adj_num] = 1;
	enqueue(q, adj_num);
}

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
				bfs_routine(self, adj_num, v, &q);
			w = w->next;
		}
	}
	delete_queue(&q);
}
