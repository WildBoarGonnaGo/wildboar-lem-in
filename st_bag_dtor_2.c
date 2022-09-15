/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_bag_dtor_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 10:14:55 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/15 07:49:20 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bag.h"

void	st_bag_dtor_2(t_st_bag **self)
{
	t_list	*lst;
	t_data	*data;

	lst = (*self)->node;
	data = (t_data *)(lst->content);
	if (data->name)
	{
		free(data->name);
		data->name = NULL;
	}
	if (data->ants)
		delete_queue(&data->ants);
	ft_lstclear(&lst, del_list2);
	(*self)->size = 0;
	(*self)->begin = NULL;
	(*self)->end = NULL;
}
