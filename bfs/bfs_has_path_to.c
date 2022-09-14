/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_has_path_to.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 10:37:31 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/13 20:52:46 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bfs.h"

int		bfs_has_path_to(t_bfs *self, int v)
{
	bfs_validate_vertex(self, v);
	return (self->marked[v]);
}