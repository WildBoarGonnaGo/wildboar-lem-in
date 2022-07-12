/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 02:28:40 by lchantel          #+#    #+#             */
/*   Updated: 2022/07/13 02:29:47 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph_ctor_in.h"

void	alloc_array(t_graph **me)
{
	int			i;
	int			oldsize;
	t_st_bag	**old_data;

	i = -1;
	if (!(*me)->size)
		(*me)->adj = (t_st_bag **)malloc(sizeof(t_st_bag *)
										 * ++(*me)->size);
	else
	{
		oldsize = (*me)->size;
		old_data = (*me)->adj;
		(*me)->size *= 2;
		(*me)->adj = (t_st_bag **)malloc(sizeof(t_st_bag *) * (*me)->size);
		while (++i < oldsize)
		{
			(*me)->adj[i] = new_bag();
			st_bag_copy_assign(&(*me)->adj[i], old_data[i]);
			delete_bag(&old_data[i], del_list2);
		}
		free(old_data);
		old_data = NULL;
	}
}