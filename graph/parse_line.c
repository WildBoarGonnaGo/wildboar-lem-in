/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 02:33:11 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/18 20:25:35 by                  ###   ########.fr       */
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

void	wrong_vertex_edge(char **str, t_graph **me, char *line,
						  char *msg)
{
	if (str && *str)
		delete_str_2d(str);
	delete_graph_2(me);
	if (line)
	{
		free(line);
		line = NULL;
	}
	err_println_str(msg);
}

void	gen_error(t_graph **me, char *line, char *msg)
{
	free(line);
	line = NULL;
	delete_graph_2(me);
	err_println_str(msg);
}

void	parse_line(t_graph **me, char *line)
{
	int			i;
	char		**str;

	i = -1;
	str = NULL;
	if (line && !*line)
		return ;
	if (line && *line == 'L')
		gen_error(me, line, "leading L character is unacceptable");
	while (ft_isalnum(line[++i]))
		;
	if (line[i] == ' ' && !(*me)->state)
		add_vertex(me, line);
	else if (line[i] == '-')
	{
		check_verticies(me, line);
		if (!(*me)->state)
			++(*me)->state;
		str = ft_split(line, '-');
		if (!str[0] && !str[0][0])
			wrong_vertex_edge(str, me, line, "wrong vertex data input");
		if (!str[1] && !str[1][0])
			wrong_vertex_edge(str, me, line, "wrong vertex data input");
		i = ft_strlen(str[0]) + ft_strlen(str[1]) + 1;
		if (str[3] && i != (int)ft_strlen(line))
			wrong_vertex_edge(str, me, line, "wrong number of arguments");
		add_edge(me, str, line);
		delete_str_2d(str);
	}
	else
		gen_error(me, line, "wrong input file syntax");
}
