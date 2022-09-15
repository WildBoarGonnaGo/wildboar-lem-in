/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 21:32:10 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/16 02:06:51 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue/queue.h"
#include "lem_in.h"

void	clean_trash(t_list **trash)
{
	t_arr_struct	*rage;

	while (*trash)
	{
		rage = (t_arr_struct *)(*trash)->content;
		if (rage->arr)
		{
			free(rage->arr);
			rage->arr = NULL;
		}
		*trash = (*trash)->next;
	}
}

void	move_it(t_list **army, t_list **route, t_graph **graph)
{
	char	*graph_str;
	t_list	*death;

	while (*army)
	{
		graph_str = (char *)(*army)->content;
		if (*graph_str)
			write(1, graph_str, ft_strlen(graph_str));
		death = *army;
		*army = forwarding(route, graph);
		ft_lstdelone(death, del_list2);
	}
}

void	data_output(t_graph *graph)
{
	t_list	*info;
	char	*line;

	info = graph->input_data;
	while (info)
	{
		line = (char *)info->content;
		ft_putendl_fd(line, 1);
		info = info->next;
	}
	ft_putchar_fd('\n', 1);
}

int	main(void)
{
	t_graph	*graph;
	t_list	*final[3];

	graph = new_graph();
	data_output(graph);
	ft_lstclear(&graph->input_data, del_list2);
	final[0] = routing(graph);
	final[1] = forwarding(&final[0], &graph);
	move_it(&final[1], &final[0], &graph);
	delete_arrs(&final[0]);
	final[2] = final[0];
	clean_trash(&final[2]);
	ft_lstclear(&final[0], del_list2);
	delete_graph_2(&graph);
	return (0);
}
