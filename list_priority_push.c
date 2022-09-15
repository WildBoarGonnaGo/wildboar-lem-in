/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_priority_push.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 09:55:59 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/15 10:54:31 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	list_midst_add(t_list **set, t_list **unit)
{
	(*unit)->next = (*set)->next;
	(*set)->next = *unit;
}

void	prior_midst(t_list **list, t_bfs *bfs,
					t_st_bag *bag, int end)
{
	t_data			*data;
	t_arr_struct	*check;
	t_list			*roll;

	roll = *list;
	data = (t_data *)bag->node->content;
	while (roll->next)
	{
		check = (t_arr_struct *)roll->next->content;
		if (bfs_dist_to(bfs, check->indx)
			< bfs_dist_to(bfs, data->indx))
		{
			roll = ft_lstnew(arr_path(bfs, &check->indx, end));
			list_midst_add(&roll, &roll);
			return ;
		}
	}
	check = (t_arr_struct *)roll->content;
	roll = ft_lstnew(arr_path(bfs, &data->indx, end));
	if (bfs_dist_to(bfs, check->indx)
		> bfs_dist_to(bfs, data->indx))
		ft_lstadd_front(list, roll);
	else
		ft_lstadd_back(list, roll);
}

void	list_priority_push(t_list **list, t_bfs *bfs,
			t_st_bag *bag, int end)
{
	t_data			*data;
	t_list			*roll;

	data = (t_data *)bag->node->content;
	if (!*list)
	{
		roll = ft_lstnew(arr_path(bfs, &data->indx, end));
		ft_lstadd_back(list, roll);
	}
	else
		prior_midst(list, bfs, bag, end);
}
