/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_bag_copy_assign.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 15:00:34 by lchantel          #+#    #+#             */
/*   Updated: 2022/07/12 22:14:29 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bag.h"

void	delete_elem(void *data)
{
	t_list	*list_data;

	if (!data)
		return ;
	list_data = (t_list *)data;
	if (list_data->content)
	{
		free(list_data->content);
		list_data->content = NULL;
	}
	free(list_data);
	list_data = NULL;
}

t_data	*t_data_copy(const t_data *src)
{
	t_data	*dst;

	dst = (t_data *)malloc(sizeof(t_data));;
	dst->indx = src->indx;
	dst->x = src->x;
	dst->y = src->y;
	return (dst);
}

void	st_bag_copy_assign(t_st_bag **self, const t_st_bag *that)
{
	t_list	*to_be_freed;
	t_list	*roll;

	//(*self)->size = that->size;
	to_be_freed = (*self)->node;
	if (to_be_freed)
		ft_lstclear(&to_be_freed, delete_elem);
	(*self)->begin = NULL;
	(*self)->end = NULL;
	(*self)->state = that->state;
	roll = that->node;
	if (!that->node)
	{
		(*self)->node = NULL;
		return ;
	}
	while (roll)
	{
		add(self, t_data_copy(roll->content));
		roll = roll->next;
	}
}