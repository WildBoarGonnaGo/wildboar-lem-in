/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:11:40 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/07 17:32:15 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include "../libft/libft.h"
# include "../new.h"

typedef struct	s_stack
{
	t_list	*node;
	int		n;
}	t_stack;

void	stack_ctor(t_stack **self);
t_stack	*new_stack();
void	stack_dtor(t_stack **self);
void	delete_stack(t_stack **self);
int		stack_is_empty(t_stack *self);
void	*pop(t_stack **self);
void	*peek(t_stack *self);
void	push(t_stack **self, void *item);

#endif