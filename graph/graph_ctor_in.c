/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_ctor_in.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 22:38:38 by lchantel          #+#    #+#             */
/*   Updated: 2022/07/13 02:53:32 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnl/get_next_line.h"
#include "graph_ctor_in.h"

void	 graph_ctor_in(t_graph **me)
{
	char	*line;
	int		num;

	graph_init(me, &num);
	while (get_next_line(0, &line) > 0)
		line_analisys(me, &line, &num);
	if (line)
		line_analisys(me, &line, &num);
	check_input_data(*me);
}