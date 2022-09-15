/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_bfs_multi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:54:47 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/09 16:55:49 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bfs.h"

t_bfs	*new_bfs_multi(t_graph *graph, t_st_bag *bag)
{
	t_bfs	*res;

	res = (t_bfs *)malloc(sizeof(t_bfs));
	if (!res)
		err_println(ENOMEM);
	bfs_ctor_multi(&res, graph, bag);
	return (res);
}
