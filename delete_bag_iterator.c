/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_bag_iterator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:08:09 by lchantel          #+#    #+#             */
/*   Updated: 2022/06/27 15:13:40 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bag.h"

void	delete_bag_iterator(t_st_bag_iterator **item)
{
	if (!item || !*item)
		err_println(EFAULT);
	t_st_bag_iterator_dtor(item);
	free(*item);
	*item = NULL;
}
