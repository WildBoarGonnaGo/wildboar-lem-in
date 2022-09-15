/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_bag_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 11:55:01 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/13 11:55:03 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bag.h"

void	delete_bag_2(t_st_bag **item)
{
	if (!item || !*item)
		return ;
	st_bag_dtor_2(item);
	free(*item);
	*item = NULL;
}
