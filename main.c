/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 21:32:10 by lchantel          #+#    #+#             */
/*   Updated: 2022/07/12 13:17:31 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph/graph.h"

int	check_prog_input(int argc, char **input)
{
	int	len;

	if (argc < 3)
		return (0);
	if (ft_strncmp(input[1], "<", 1))
		return (0);
	len = ft_strlen(input[2]);
	if (len < 5 || ft_strncmp(".map", *(input + 2) + len - 4, 4))
		return (0);
	return (1);
}

int main(int argc, char *argv[]) {
	t_st_bag			*bag;
	t_st_bag_iterator 	*it;
	t_graph 			*graph;
	int					check;
	char				*graph_str;

	check = check_prog_input(argc, argv);
	if (!check)
		err_println_str("wrong argument syntax or wrong input file extension (.map)");
	else
	{

		ft_putendl_fd(argv[1], 1);
		ft_putendl_fd(argv[2], 1);
	}
	bag = new_bag();
	add(&bag, "Kono");
	add(&bag, "Dio");
	add(&bag, "Da!");

	it = new_bag_iterator(bag);
	while (has_next(it))
	{
		ft_putendl_fd(it->it->content, 1);
		next(&it);
	}
	ft_putendl_fd(it->it->content, 1);
	delete_bag(&bag, del_list);
	delete_bag_iterator(&it);

 	graph = new_graph();
	graph_str = to_string(graph);
	ft_putendl_fd(graph_str, 1);
	delete_graph(&graph, del_list2);
	free(graph_str);
	graph_str = NULL;
	return (0);
}