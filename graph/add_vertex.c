/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_vertex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 02:30:37 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/18 17:22:26 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph_ctor_in.h"

void	wrong_vertex(t_graph **me, char *line, t_data *data)
{
	if (data)
		delete_data(data);
	if (line)
	{
		free(line);
		line = NULL;
	}
	delete_graph_2(me);
	err_println_str("wrong vertex data input");
}

void	wrong_alloc(t_graph **me, char *line)
{
	if (line)
	{
		free(line);
		line = NULL;
	}
	delete_graph_2(me);
	err_println(ENOMEM);
}

t_data	*verify_data(t_graph **me, char *line)
{
	t_data	*data;
	char	**str;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		wrong_alloc(me, line);
	str = ft_split(line, ' ');
	data->name = ft_strdup(str[0]);
	if (str[1] && str[1][0] && is_number(str[1]))
		data->x = ft_atoi(str[1]);
	else
		wrong_vertex(me, line, data);
	if (str[2] && str[2][0] && is_number(str[2]))
		data->y = ft_atoi(str[2]);
	else
		wrong_vertex(me, line, data);
	delete_array2d((void **)str);
	data->indx = (*me)->v;
	if ((*me)->v >= (*me)->size)
		alloc_array(me);
	(*me)->adj[(*me)->v] = new_bag();
	return (data);
}

void	add_vertex(t_graph **me, char *line)
{
	t_data	*data;
	int		i;

	data = verify_data(me, line);
	if ((*me)->start == -1)
	{
		(*me)->start = (*me)->v;
		data->ants = new_queue();
		i = -1;
		while (++i < (*me)->ants_num)
			enqueue(&data->ants, &(*me)->ants[i]);
		data->ant_num = 1;
	}
	else
	{
		data->ant_num = 0;
		data->ants = NULL;
	}
	if ((*me)->end == -1)
		(*me)->end = (*me)->v;
	add(&(*me)->adj[(*me)->v], data);
	++(*me)->v;
}
