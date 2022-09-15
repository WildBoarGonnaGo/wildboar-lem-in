/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_list2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 21:12:06 by lchantel          #+#    #+#             */
/*   Updated: 2022/07/11 21:12:09 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bag.h"

void	del_list2(void *item)
{
	t_list	*data;

	data = (t_list *)item;
	if (data->content)
	{
		free(data->content);
		data->content = NULL;
	}
	free(item);
	item = NULL;
}
