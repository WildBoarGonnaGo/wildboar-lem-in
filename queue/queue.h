/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 19:53:45 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/15 19:57:36 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H
# include "../new.h"

typedef struct s_queue
{
	t_list			*node;
	unsigned int	size;
}	t_queue;

void	del_list(void *item);
void	del_list2(void *item);
t_queue	*new_queue(void);
void	queue_ctor(t_queue **self);
void	delete_queue(t_queue **self);
void	queue_dtor(t_queue **self);
void	enqueue(t_queue **self, void *data);
void	*dequeue(t_queue **self);
void	*queue_peek(t_queue *self);
int		queue_is_empty(t_queue *self);

#endif
