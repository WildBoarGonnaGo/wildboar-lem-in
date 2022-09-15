/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_queue.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 19:53:25 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/15 19:56:10 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

void	delete_queue(t_queue **self)
{
	if (!self || !*self)
		err_println(EFAULT);
	queue_dtor(self);
	free(*self);
	*self = NULL;
}
