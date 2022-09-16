/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_ctor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:55:12 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/16 13:35:16 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bfs.h"

void	bfs_ctor(t_bfs **self, t_graph *graph, int s)
{
	(*self)->len = graph->v;
	(*self)->edge_to = (int *)malloc(sizeof(int) * (*self)->len);
	(*self)->marked = (int *)malloc(sizeof(int) * (*self)->len);
	(*self)->dist_to = (int *)malloc(sizeof(int) * (*self)->len);
	if (!(*self)->edge_to || !(*self)->marked || !(*self)->dist_to)
		err_println(ENOMEM);
	(*self)->src = s;
	(*self)->v_mark = NULL;
	(*self)->graph = graph;
	bfs_data_init(self);
	bfs_validate_vertex(*self, s);
	bfs(self, graph, s);
}
