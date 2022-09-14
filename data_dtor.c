/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_dtor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:46:40 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/14 15:27:27 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bag.h"

void	data_dtor(void *self)
{
	t_data	*data;
	t_list	*lst;

	lst = (t_list *)self;
	data = (t_data *)lst->content;
	if (data->name)
	{
		free(data->name);
		data->name = NULL;
	}
	if (data->ants)
		delete_queue(&data->ants);
}
