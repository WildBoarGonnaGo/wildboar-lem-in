/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 10:16:37 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/15 10:49:38 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	route_table(t_list **roll, t_bfs **start_bfs,
					t_graph *graph, t_list **list)
{
	t_data			*data;
	t_bfs			*bfs;
	t_arr_struct	*warr;

	data = (t_data *)(*roll)->content;
	bfs = new_bfs(graph, data->indx);
	if (bfs_has_path_to(bfs, graph->start))
		list_priority_push(list, *start_bfs,
			adj(graph, data->indx),
			graph->end);
	warr = (t_arr_struct *)(*list)->content;
	warr->main_path = 1;
	(*roll) = (*roll)->next;
	delete_bfs(&bfs);
}

t_list	*routing(t_graph *graph)
{
	t_st_bag		*bag;
	t_bfs			*start_bfs;
	t_list			*roll;
	t_list			*list;
	t_arr_struct	*warr;

	bag = adj(graph, graph->end);
	start_bfs = new_bfs(graph, graph->start);
	roll = bag->node->next;
	list = NULL;
	while (roll)
		route_table(&roll, &start_bfs, graph, &list);
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
	delete_bfs(&start_bfs);
	return (list);
}
