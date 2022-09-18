/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_verticies_messages.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 19:36:41 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/18 19:38:32 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

void	purge_line(void *line)
{
	if (line)
	{
		free(line);
		line = NULL;
	}
}

void	check_verticies_messages(t_graph **me, char *line, char *msg)
{
	delete_graph_2(me);
	purge_line(line);
	err_println_str(msg);
}