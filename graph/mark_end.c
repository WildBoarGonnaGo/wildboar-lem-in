/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 02:22:50 by lchantel          #+#    #+#             */
/*   Updated: 2022/07/13 02:22:52 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph_ctor_in.h"

void	mark_end(t_graph **me)
{
	if ((*me)->start == -1)
		err_println_str("start and end point can't be the same");
	if ((*me)->end >= 0)
		err_println_str("end point is already marked");
	else if ((*me)->end == -2)
		(*me)->end = -1;
}
