/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_data_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 11:49:41 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/16 11:53:31 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bfs.h"

void	bfs_data_init(t_bfs **self)
{
	int	i;

	i = -1;
	while (++i < (*self)->len)
		(*self)->marked[i] = 0;
	i = -1;
	while (++i < (*self)->len)
		(*self)->edge_to[i] = (*self)->src;
}