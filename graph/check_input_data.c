/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 02:35:31 by lchantel          #+#    #+#             */
/*   Updated: 2022/07/13 02:35:34 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph_ctor_in.h"

void	check_input_data(const t_graph *me)
{
	if (me->v < 1)
		err_println_str("not enough verticies");
	else if (!me->e)
		err_println_str("not enough edges");
	else if (me->start == -2 || me->start == -1)
		err_println_str("no start vertex designated");
	else if (me->end == -2 || me->end == -1)
		err_println_str("no end vertex designated");
	else if (me->start == me->end)
		err_println_str("start and end point can't be the same");
}
