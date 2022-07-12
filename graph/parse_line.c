/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 02:33:11 by lchantel          #+#    #+#             */
/*   Updated: 2022/07/13 02:33:12 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph_ctor_in.h"

void	parse_line(t_graph **me, char *line)
{
	int		i;
	char	**str;
	int		edge[2];

	i = -1;
	while (ft_isalnum(line[++i]))
		;
	if (line[i] == ' ' && !(*me)->state)
		add_vertex(me, line);
	else if (line[i] == '-')
	{
		if (!(*me)->state)
			++(*me)->state;
		str = ft_split(line, '-');
		if (str[0] && str[0][0] && is_number(str[0]))
			edge[0] = ft_atoi(str[0]);
		else
			err_println_str("wrong vertex data input");
		if (str[1] && str[1][0] && is_number(str[1]))
			edge[1] = ft_atoi(str[1]);
		else
			err_println_str("wrong vertex data input");
		if (str[3])
			err_println_str("wrong number of arguments");
		add_edge(me, edge[0], edge[1]);
	}
	else
		err_println_str("wrong input file syntax");
}