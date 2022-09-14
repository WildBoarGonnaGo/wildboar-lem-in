/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 00:22:42 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/08 20:35:46 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	*pop(t_stack **self)
{
	t_list	*member;
	void	*item;

	member = (*self)->node;
	item = (*self)->node->content;
	if (stack_is_empty(*self))
		err_println(EFAULT);
	if ((*self)->node->next)
		(*self)->node = (*self)->node->next;
	else
	{
		ft_lstdelone((*self)->node, del_list);
		(*self)->node = NULL;
	}
	--(*self)->n;
	if ((*self)->node)
		ft_lstdelone(member, del_list);
	member = NULL;
	return (item);
}