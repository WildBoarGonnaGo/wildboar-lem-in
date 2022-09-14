/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_bfs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:45:39 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/09 14:54:21 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bfs.h"

t_bfs	*new_bfs(t_graph *graph, int s)
{
	t_bfs	*res;

	res = (t_bfs *)malloc(sizeof(t_bfs));
	if (!res)
		err_println(ENOMEM);
	bfs_ctor(&res, graph, s);
	return (res);
}