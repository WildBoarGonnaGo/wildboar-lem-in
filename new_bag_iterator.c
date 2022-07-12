/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_bag_iterator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:41:27 by lchantel          #+#    #+#             */
/*   Updated: 2022/06/27 09:49:33 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "new.h"

t_st_bag_iterator	*new_bag_iterator(const t_st_bag *item) {

	t_st_bag_iterator	*it;

	it = (t_st_bag_iterator *)malloc(sizeof(t_st_bag_iterator));
	if (!it)
		err_println(12);
	t_st_bag_iterator_ctor(&it, item);
	return (it);
}
