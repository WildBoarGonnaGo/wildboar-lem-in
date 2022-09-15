/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_validate_vertex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 21:16:45 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/13 21:18:01 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bfs.h"

void	bfs_validate_vertex(t_bfs *self, int v)
{
	if (v < 0 || v > self->len)
		err_println_str("no such vertex");
}
