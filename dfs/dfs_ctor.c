/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs_ctor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 01:34:51 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/15 16:54:06 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "depth_first_search.h"

void	dfs(t_dfs_data **self, const t_graph *tgt, int src)
{
	t_st_bag_iterator	*roll;
	t_list				*lurker;
	t_data				*chest;

	roll = new_bag_iterator(tgt->adj[src]);
	++(*self)->count;
	(*self)->marked[src] = 1;
	while (has_next(roll))
	{
		lurker = next(&roll);
		chest = (t_data *)lurker->content;
		if (!(*self)->marked[chest->indx])
		{
			(*self)->edge_to[chest->indx] = src;
			dfs(self, tgt, chest->indx);
		}
	}
	delete_bag_iterator(&roll);
}

void	dfs_ctor(t_dfs_data **self, const t_graph *tgt, int src)
{
	int	i;

	i = -1;
	validate_vertex(tgt, src);
	(*self)->marked = (unsigned short *)malloc(
			sizeof(unsigned short) * tgt->v);
	(*self)->edge_to = (int *)malloc(
			sizeof(int) * tgt->v);
	while (++i < tgt->v)
		(*self)->edge_to[i] = -1;
	if (!(*self)->marked)
		err_println(ENOMEM);
	(*self)->count = 0;
	dfs(self, tgt, src);
}
