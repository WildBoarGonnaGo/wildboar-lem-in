/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_verticies.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 18:52:43 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/18 20:47:50 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

void	check_verticies(t_graph **me, char *line)
{
	if (!(*me)->v)
		check_verticies_messages(me, line, "no vertex is presented");
	else if ((*me)->start < 0 && ((*me)->end) < 0)
		check_verticies_messages(me, line, "no endpoints are set");
	else if ((*me)->start < 0)
		check_verticies_messages(me, line, "no start vertex is presented");
	else if ((*me)->end < 0)
		check_verticies_messages(me, line, "no end vertex is presented");
	else if ((*me)->start == (*me)->end)
		check_verticies_messages(me, line, "start and end verticies can't be equal");
}