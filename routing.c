/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 10:16:37 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/16 15:17:45 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	route_table(t_bfs **start_bfs,
					t_list **list)
{
	t_arr_struct	*warr;

	list_priority_push(list, start_bfs);
	warr = (t_arr_struct *)(*list)->content;
	warr->main_path = 1;
}

t_list	*routing(t_graph *graph)
{
	t_bfs			*start_bfs;
	t_list			*list;
	t_arr_struct	*warr;
	t_list			*roll;

	start_bfs = new_bfs(graph, graph->start);
	list = NULL;
	route_table(&start_bfs, &list);
	if (list)
	{
		roll = list->next;
		while (roll)
		{
			warr = (t_arr_struct *)roll->content;
			warr->main_path = 0;
			roll = roll->next;
		}
	}
	ft_lstclear(&start_bfs->v_mark->node, del_list);
	delete_bfs(&start_bfs);
	return (list);
}
