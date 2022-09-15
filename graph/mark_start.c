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

void	mark_start(t_graph **me)
{
	if ((*me)->end == -1)
		err_println_str("start and end point can't be the same");
	if ((*me)->start >= 0)
		err_println_str("start point is already marked");
	else if ((*me)->start == -2)
		(*me)->start = -1;
}
