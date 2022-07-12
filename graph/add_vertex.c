/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_vertex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 02:30:37 by lchantel          #+#    #+#             */
/*   Updated: 2022/07/13 02:30:38 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph_ctor_in.h"

void	add_vertex(t_graph **me, char *line)
{
	t_data 	*data;
	char	**str;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		err_println(ENOMEM);
	str = ft_split(line, ' ');
	if (str[1] && str[1][0] && is_number(str[1]))
		data->x = ft_atoi(str[1]);
	else
		err_println_str("wrong vertex data input");
	if (str[2] && str[2][0] && is_number(str[2]))
		data->y = ft_atoi(str[2]);
	else
		err_println_str("wrong vertex data input");
	delete_array2d((void **)str);
	data->indx = (*me)->v;
	if ((*me)->v >= (*me)->size)
		alloc_array(me);
	//st_bag_ctor(&(*me)->adj[(*me)->v]);
	(*me)->adj[(*me)->v] = new_bag();
	add(&(*me)->adj[(*me)->v], data);
	if ((*me)->start == -1)
		(*me)->start = (*me)->v;
	if ((*me)->end == -1)
		(*me)->end = (*me)->v;
	++(*me)->v;
}