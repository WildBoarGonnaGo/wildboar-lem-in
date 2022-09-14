/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_dtor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:10:14 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/13 11:27:43 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

void	graph_dtor(t_graph **me, void (*del)(void *))
{
	int	i;

	i = -1;
	while (++i < (*me)->v)
		delete_bag(&(*me)->adj[i], del);
	free((*me)->adj);
	(*me)->adj = NULL;
}