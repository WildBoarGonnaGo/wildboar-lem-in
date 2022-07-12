/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_edge.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 20:09:52 by lchantel          #+#    #+#             */
/*   Updated: 2022/07/11 11:21:02 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

void	add_edge(t_graph **me, int v, int w)
{
	t_data	*alloc_v;
	t_data	*alloc_w;
	t_data	*tmp;

	validate_vertex(*me, v);
	validate_vertex(*me, w);
	++(*me)->e;
	alloc_v = (t_data *)malloc(sizeof(t_data));
	alloc_w = (t_data *)malloc(sizeof(t_data));
	tmp = (t_data *)((*me)->adj[v]->begin->content);
	alloc_v->x = tmp->x;
	alloc_v->y = tmp->y;
	alloc_v->indx = tmp->indx;
	tmp = (t_data *)((*me)->adj[w]->begin->content);
	alloc_w->x = tmp->x;
	alloc_w->y = tmp->y;
	alloc_w->indx = tmp->indx;
	add(&(*me)->adj[v], alloc_w);
	add(&(*me)->adj[w], alloc_v);
}