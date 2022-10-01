/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_analisys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 02:37:12 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/18 22:15:00 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph_ctor_in.h"

void	line_analisys(t_graph **me, char **line, int *num)
{
	t_list	*unit;

	if (!(*num)++)
		get_number(me, *line);
	else if (!ft_strncmp(*line, "##start", 7))
		mark_start(me, *line);
	else if (!ft_strncmp(*line, "##end", 5))
		mark_end(me, *line);
	else if (*line[0] != '#')
		parse_line(me, *line);
	if (line && !*line)
	{
		delete_line(line);
		return ;
	}
	if (**line)
	{
		unit = ft_lstnew(ft_strdup(*line));
		ft_lstadd_back(&(*me)->input_data, unit);
	}
	delete_line(line);
}
