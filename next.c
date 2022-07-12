/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:13:42 by lchantel          #+#    #+#             */
/*   Updated: 2022/06/26 20:16:06 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bag.h"

t_list	*next(t_st_bag_iterator **self) {
	t_list	*res;

	res = (*self)->it->next;
	(*self)->it = (*self)->it->next;
	return (res);
}