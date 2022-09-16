/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_priority_push.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 09:55:59 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/16 15:04:15 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	list_priority_push(t_list **list, t_bfs **bfs)
{
	t_arr_struct	*check;
	t_list			*roll;

	check = arr_path(bfs, &(*bfs)->graph->end);
	while (check)
	{
		roll = ft_lstnew(check);
		ft_lstadd_back(list, roll);
		check = arr_path(bfs, &(*bfs)->graph->end);
	}
}
