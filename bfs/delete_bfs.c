/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_bfs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 08:35:07 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/13 08:43:04 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bfs.h"

void	delete_bfs(t_bfs **self)
{
	if (!self || !*self)
		err_println(EFAULT);
	bfs_dtor(self);
	free(*self);
	*self = NULL;
}
