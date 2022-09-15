/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 02:33:11 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/16 00:42:32 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph_ctor_in.h"

void	delete_str_2d(char **str)
{
	int	i;

	i = -1;
	if (!str || !*str)
		return ;
	while (str[++i])
	{
		free(str[i]);
		str[i] = NULL;
	}
	free(str);
	str = NULL;
}

void	parse_line(t_graph **me, char *line)
{
	int		i;
	char	**str;

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
		if (!str[0] && !str[0][0])
			err_println_str("wrong vertex data input");
		if (!str[1] && !str[1][0])
			err_println_str("wrong vertex data input");
		i = ft_strlen(str[0]) + ft_strlen(str[1]) + 1;
		if (str[3] && i != (int)ft_strlen(line))
			err_println_str("wrong number of arguments");
		add_edge(me, str[0], str[1]);
		delete_str_2d(str);
	}
	else
		err_println_str("wrong input file syntax");
}
