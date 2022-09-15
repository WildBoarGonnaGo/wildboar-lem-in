/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_graph.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:11:09 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/15 15:19:55 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

void	delete_graph(t_graph **self, void (*del)(void *))
{
	graph_dtor(self, del);
	free(*self);
	*self = NULL;
}
