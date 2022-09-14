/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_bag_dtor_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 10:14:55 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/14 15:16:21 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bag.h"

void	st_bag_dtor_2(t_st_bag **self)
{
	t_list	*lst;

	lst = (*self)->node;
	ft_lstclear(&lst, delete_data);
	(*self)->size = 0;
	(*self)->begin = NULL;
	(*self)->end = NULL;
}