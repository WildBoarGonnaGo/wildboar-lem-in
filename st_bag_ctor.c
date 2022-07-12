/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_bag_ctor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 23:03:22 by lchantel          #+#    #+#             */
/*   Updated: 2022/06/26 18:48:32 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bag.h"

void	st_bag_ctor(t_st_bag **self)
{
	if (!self || !*self)
		return ;
	(*self)->node = NULL;
	(*self)->size = 0;
	(*self)->begin = NULL;
	(*self)->end = NULL;
	(*self)->state = 0;
}
