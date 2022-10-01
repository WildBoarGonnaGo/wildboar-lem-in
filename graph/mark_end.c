/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 02:22:50 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/19 08:46:45 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph_ctor_in.h"

void	end_fail(t_graph **me, char *line)
{
	free(line);
	line = NULL;
	delete_graph_2(me);
	err_println_str("start point is already marked");
}

void	mark_end(t_graph **me, char *line)
{
	if ((*me)->end >= 0)
		end_fail(me, line);
	else if ((*me)->end == -2)
		(*me)->end = -1;
}
