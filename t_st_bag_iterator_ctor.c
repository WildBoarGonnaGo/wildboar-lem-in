/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_st_bag_iterator_ctor.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 13:19:48 by lchantel          #+#    #+#             */
/*   Updated: 2022/06/27 09:48:12 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "new.h"

void	t_st_bag_iterator_ctor(t_st_bag_iterator **self,
			const t_st_bag *src)
{
	if (!src)
		err_println(EFAULT);
	(*self)->it = src->begin;
}
