/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_path_to.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 07:15:56 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/15 19:51:33 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "depth_first_search.h"

void	dfs_validate_vertex(t_dfs_data *self, int v)
{
	if (v < 0 || v > self->count)
		err_println_str("no such vertex");
}

int	has_path_to(t_dfs_data *self, int v)
{
	dfs_validate_vertex(self, v);
	return (self->marked[v]);
}
