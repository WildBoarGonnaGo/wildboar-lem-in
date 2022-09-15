/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_path_to.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 10:51:18 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/14 13:22:38 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bfs.h"

t_stack	*bfs_path_to(t_bfs *self, int *v)
{
	t_stack	*res;
	int		i;

	bfs_validate_vertex(self, *v);
	if (!bfs_has_path_to(self, *v))
		return (NULL);
	res = new_stack();
	i = *v;
	push(&res, v);
	while (self->dist_to[i])
	{
		push(&res, &self->edge_to[i]);
		i = self->edge_to[i];
	}
	return (res);
}
