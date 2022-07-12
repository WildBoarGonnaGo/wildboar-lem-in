/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_bag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 22:56:08 by lchantel          #+#    #+#             */
/*   Updated: 2022/06/25 23:06:09 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "new.h"

void	delete_bag(t_st_bag **item, void (*del)(void *))
{
	if (!item || !*item)
		return ;
	st_bag_dtor(item, del);
	free(*item);
	*item = NULL;
}