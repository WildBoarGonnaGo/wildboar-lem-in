/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 00:18:09 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/07 00:20:39 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	delete_stack(t_stack **self)
{
	if (!self || !*self)
		err_println(EFAULT);
	stack_dtor(self);
	free(*self);
	*self = NULL;
}