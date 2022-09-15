/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 09:13:51 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/15 09:52:14 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "graph/stack.h"

t_arr_struct	*arr_path(t_bfs *bfs, int *v, int end)
{
	t_stack			*stack;
	t_arr_struct	*res;
	int				len;

	if (!bfs)
		return (NULL);
	res = (t_arr_struct *)malloc(sizeof(t_arr_struct));
	stack = bfs_path_to(bfs, v);
	res->size = bfs_dist_to(bfs, *v) + 2;
	len = -1;
	res->arr = (int *)malloc(sizeof(int) * res->size);
	while (++len < res->size - 1)
		res->arr[len] = *(int *)pop(&stack);
	res->arr[len] = end;
	res->stp = 0;
	res->indx = *v;
	res->ogate = 0;
	delete_stack(&stack);
	return (res);
}
