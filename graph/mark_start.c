/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 02:22:11 by lchantel          #+#    #+#             */
/*   Updated: 2022/07/13 02:22:12 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph_ctor_in.h"

void	start_fail(t_graph **me, char *line)
{
	free(line);
	line = NULL;
	delete_graph_2(me);
	err_println_str("start point is already marked");
}

void	mark_start(t_graph **me, char *line)
{
	if ((*me)->start >= 0)
		start_fail(me, line);
	else if ((*me)->start == -2)
		(*me)->start = -1;
}
