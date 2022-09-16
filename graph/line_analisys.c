/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_analisys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 02:37:12 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/16 00:42:21 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph_ctor_in.h"

void	line_analisys(t_graph **me, char **line, int *num)
{
	t_list	*unit;

	if (!(*num)++)
		get_number(me, *line);
	else if (!ft_strncmp(*line, "##start", 7))
		mark_start(me);
	else if (!ft_strncmp(*line, "##end", 5))
		mark_end(me);
	else if (*line[0] != '#')
		parse_line(me, *line);
	unit = ft_lstnew(ft_strdup(*line));
	ft_lstadd_back(&(*me)->input_data, unit);
	delete_line(line);
}
