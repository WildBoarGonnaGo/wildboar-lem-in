/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_edge.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 20:09:52 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/15 14:55:04 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

int	seek_indx(t_graph *me, char *str)
{
	int		i;
	int		res;
	t_data	*tmp;

	res = -1;
	i = -1;
	while (++i < me->v)
	{
		tmp = (t_data *)(me->adj[i]->begin->content);
		if (!ft_strncmp(str, tmp->name, ft_strlen(str)))
		{
			res = tmp->indx;
			break ;
		}
	}
	if (res == -1)
		err_println_str("no such vertex");
	return (res);
}

t_data	*cp_data(t_graph *me, int src)
{
	t_data	*data;
	t_data	*res;

	res = (t_data *)malloc(sizeof(t_data));
	if (!res)
		err_println(ENOMEM);
	data = (t_data *)me->adj[src]->begin->content;
	res->x = data->x;
	res->y = data->y;
	res->name = data->name;
	res->ants = data->ants;
	res->ant_num = data->ant_num;
	res->indx = data->indx;
	return (res);
}

void	add_edge(t_graph **me, char *v, char *w)
{
	t_data	*alloc_v;
	t_data	*alloc_w;
	int		node[2];

	node[0] = seek_indx(*me, v);
	node[1] = seek_indx(*me, w);
	validate_vertex(*me, node[0]);
	validate_vertex(*me, node[1]);
	++(*me)->e;
	alloc_v = cp_data(*me, node[0]);
	alloc_w = cp_data(*me, node[1]);
	add(&(*me)->adj[node[0]], alloc_w);
	add(&(*me)->adj[node[1]], alloc_v);
}
