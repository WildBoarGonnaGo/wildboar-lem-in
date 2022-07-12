/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_bag_dtor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:42:17 by lchantel          #+#    #+#             */
/*   Updated: 2022/07/11 17:32:13 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bag.h"

void	st_bag_dtor(t_st_bag **self, void (*del)(void *))
{
	ft_lstclear(&(*self)->node, del);
	(*self)->size = 0;
	(*self)->begin = NULL;
	(*self)->end = NULL;
}
