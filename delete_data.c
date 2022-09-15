/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:41:27 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/13 20:40:58 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bag.h"

void	delete_data(void *self)
{
	if (!self)
		err_println(EFAULT);
	data_dtor(self);
	free(self);
	self = NULL;
}
