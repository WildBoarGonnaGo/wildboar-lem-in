/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_dfs_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 00:02:33 by lchantel          #+#    #+#             */
/*   Updated: 2022/07/15 00:08:03 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "depth_first_search.h"

void	delete_dfs_data(t_dfs_data **self)
{
	if (!self || !*self)
		err_println(EFAULT);
	dfs_dtor(self);
	free(*self);
	*self = NULL;
}
