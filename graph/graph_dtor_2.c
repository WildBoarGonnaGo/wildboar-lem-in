/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_dtor_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 11:26:14 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/13 11:51:31 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

void	graph_dtor_2(t_graph **self)
{
	int	i;

	i = -1;
	while (++i < (*self)->v)
		delete_bag_2(&(*self)->adj[i]);
	free((*self)->adj);
    if ((*self)->ants)
    {
        free((*self)->ants);
        (*self)->ants = NULL;
    }
	(*self)->adj = NULL;
}
