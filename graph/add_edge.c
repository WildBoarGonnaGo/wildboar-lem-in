/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_edge.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 20:09:52 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/18 20:19:17 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

void	delete_str_edge_2d(char **str)
{
	int	i;

	i = -1;
	if (!str || !*str)
		return ;
	while (str[++i])
	{
		free(str[i]);
		str[i] = NULL;
	}
	free(str);
	str = NULL;
}

void	vertex_seek_failure(t_graph **me, char **str, char *line, int indx)
{
	char	v_str[128];
	char	*aux;
    int		i[3];

    i[0] = -1;
	ft_bzero(v_str, 128);
    aux = ft_strdup("there is no such vertex: ");
    while (aux[++i[0]])
    {
        v_str[i[0]] = aux[i[0]];
    }
	free(aux);
	aux = str[indx];
    i[1] = -1;
    i[2] = ft_strlen(aux);
    while (++i[1] < i[2])
    {
        v_str[i[0]++] = aux[i[1]];
    }
	aux = NULL;
	delete_str_edge_2d(str);
	delete_graph_2(me);
	free(line);
	line = NULL;
	err_println_str(v_str);
}

int	seek_indx(t_graph **me, char *str)
{
	int		i;
	int		res;
	t_data	*tmp;

	res = -1;
	i = -1;
	while (++i < (*me)->v)
	{
		tmp = (t_data *)((*me)->adj[i]->begin->content);
		if (!ft_strncmp(str, tmp->name, ft_strlen(str)))
		{
			res = tmp->indx;
			break ;
		}
	}
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

void	add_edge(t_graph **me, char **str, char *line)
{
	t_data	*alloc_v;
	t_data	*alloc_w;
	int		node[2];

	node[0] = seek_indx(me, str[0]);
	if (node[0] < 0)
		vertex_seek_failure(me, str, line, 0);
	node[1] = seek_indx(me, str[1]);
	if (node[1] < 0)
		vertex_seek_failure(me, str, line, 1);
	validate_vertex(*me, node[0]);
	validate_vertex(*me, node[1]);
	++(*me)->e;
	alloc_v = cp_data(*me, node[0]);
	alloc_w = cp_data(*me, node[1]);
	add(&(*me)->adj[node[0]], alloc_w);
	add(&(*me)->adj[node[1]], alloc_v);
}
