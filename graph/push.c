/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:27:40 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/07 17:36:00 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	push(t_stack **self, void *item)
{
	t_list	*new_lst;

	new_lst = ft_lstnew(item);
	ft_lstadd_front(&(*self)->node, new_lst);
	++(*self)->n;
}
