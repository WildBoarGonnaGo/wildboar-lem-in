/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enqueue.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 19:53:33 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/15 19:56:49 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

void	enqueue(t_queue **self, void *data)
{
	t_list	*new_lst;

	new_lst = ft_lstnew(data);
	ft_lstadd_back(&(*self)->node, new_lst);
	++(*self)->size;
}
