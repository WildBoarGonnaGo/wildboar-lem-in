/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 00:03:13 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/15 17:03:28 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*new_stack(void)
{
	t_stack	*self;

	self = (t_stack *)malloc(sizeof(t_stack));
	if (!self)
		err_println(ENOMEM);
	stack_ctor(&self);
	return (self);
}
