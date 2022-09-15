/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_arrs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 20:54:14 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/15 20:57:03 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	delete_arrs(t_list **list_path)
{
	t_arr_struct	*data;
	t_list			*roll;

	if (!list_path || !*list_path)
		err_println(EFAULT);
	roll = *list_path;
	while (roll)
	{
		data = (t_arr_struct *)roll->content;
		if (data->arr)
		{
			free(data->arr);
			data->arr = NULL;
		}
		roll = roll->next;
	}
}