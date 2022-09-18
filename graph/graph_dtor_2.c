/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_dtor_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 11:26:14 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/18 15:12:25 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

void	graph_dtor_2(t_graph **self)
{
	int	i;

	i = -1;
	if ((*self)->adj)
	{
		while (++i < (*self)->v)
			delete_bag_2(&(*self)->adj[i]);
		free((*self)->adj);
		(*self)->adj = NULL;
	}
    if ((*self)->ants)
    {
        free((*self)->ants);
        (*self)->ants = NULL;
    }
	if ((*self)->input_data)
		ft_lstclear(&(*self)->input_data, del_list2);
}
