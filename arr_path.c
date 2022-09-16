/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 09:13:51 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/16 15:11:42 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "stack/stack.h"

void	quake(t_bfs **bfs_obj)
{
	t_list	*roll;
	int		*grep;

	bfs_data_init(bfs_obj);
	roll = (*bfs_obj)->v_mark->node;
	while (roll)
	{
		grep = (int *)roll->content;
		(*bfs_obj)->marked[*grep] = 1;
		roll = roll->next;
	}
	bfs(bfs_obj, (*bfs_obj)->graph, (*bfs_obj)->src);
}

void	mark_verticies(t_bfs **bfs, t_arr_struct *pool)
{
	int			i;
	t_list		*lst;
	int			*indx;

	i = 0;
	if (!bfs || !*bfs || !pool)
		return ;
	if (!(*bfs)->v_mark)
	{
		(*bfs)->v_mark = (t_marked *)malloc(sizeof(t_marked));
		if (!(*bfs)->v_mark)
			err_println(EFAULT);
		(*bfs)->v_mark->end = NULL;
	}
	while (++i < pool->size - 1)
	{
		indx = &pool->arr[i];
		lst = ft_lstnew(indx);
		ft_lstadd_back(&(*bfs)->v_mark->node, lst);
		if (!(*bfs)->v_mark->end)
			(*bfs)->v_mark->end = (*bfs)->v_mark->node;
		else
			(*bfs)->v_mark->end = (*bfs)->v_mark->end->next;
	}
}

t_arr_struct	*arr_path(t_bfs **bfs_obj, int *end)
{
	t_stack			*stack;
	t_arr_struct	*res;
	int				len;

	if (!bfs_obj || !*bfs_obj)
		return (NULL);
	if ((*bfs_obj)->v_mark)
		quake(bfs_obj);
	if (!bfs_has_path_to(*bfs_obj, *end))
		return (NULL);
	res = (t_arr_struct *)malloc(sizeof(t_arr_struct));
	stack = bfs_path_to(*bfs_obj, end);
	res->size = bfs_dist_to(*bfs_obj, *end) + 1;
	len = -1;
	res->arr = (int *)malloc(sizeof(int) * res->size);
	while (++len < res->size)
		res->arr[len] = *(int *)pop(&stack);
	mark_verticies(bfs_obj, res);
	res->stp = 0;
	res->ogate = 0;
	delete_stack(&stack);
	return (res);
}
