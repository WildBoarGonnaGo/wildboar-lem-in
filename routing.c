/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 10:16:37 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/18 21:40:27 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	route_table(t_bfs **start_bfs,
					t_list **list)
{
	t_arr_struct	*warr;

	list_priority_push(list, start_bfs);
	if (list && *list)
	{
		warr = (t_arr_struct *)(*list)->content;
		warr->main_path = 1;
	}
}

void	no_route_error(t_graph **graph)
{
	delete_graph_2(graph);
    err_println_str("There is no route between from start to end verticies");
}

t_list	*routing(t_graph **graph)
{
	t_bfs			*start_bfs;
	t_list			*list;
	t_arr_struct	*warr;
	t_list			*roll;

	start_bfs = new_bfs((*graph), (*graph)->start);
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
	if (start_bfs->v_mark && start_bfs->v_mark->node)
	{
		ft_lstclear(&start_bfs->v_mark->node, del_list);
		start_bfs->v_mark->end = NULL;
	}
	delete_bfs(&start_bfs);
	if (!list)
		no_route_error(graph);
	return (list);
}
