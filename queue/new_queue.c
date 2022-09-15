/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_queue.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 19:57:21 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/15 19:57:23 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

t_queue	*new_queue(void)
{
	t_queue	*res;

	res = (t_queue *)malloc(sizeof(t_queue));
	if (!res)
		err_println(ENOMEM);
	queue_ctor(&res);
	return (res);
}
