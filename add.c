/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:49:20 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/15 20:03:47 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bag.h"

void	add(t_st_bag **self, void *item)
{
	t_list	*adj_vertex;
	t_list	*prop;

	adj_vertex = ft_lstnew(item);
	if (!adj_vertex)
		err_println(ENOMEM);
	if (!(*self)->end)
		prop = (*self)->node;
	else
		prop = (*self)->end;
	ft_lstadd_back(&prop, adj_vertex);
	if (!(*self)->size++)
	{
		(*self)->node = prop;
		(*self)->begin = (*self)->node;
		(*self)->end = (*self)->node;
	}
	else
		(*self)->end = (*self)->end->next;
}
