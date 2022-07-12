/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_bag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:00:56 by lchantel          #+#    #+#             */
/*   Updated: 2022/06/26 19:48:10 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "new.h"

t_st_bag	*new_bag(void)
{
	t_st_bag	*res;

	res = (t_st_bag *)malloc(sizeof(t_st_bag));
	if (!res)
		err_println(12);
	st_bag_ctor(&res);
	return (res);
}
