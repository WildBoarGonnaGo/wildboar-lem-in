/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 02:35:31 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/18 20:49:06 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph_ctor_in.h"

void	check_input_data(t_graph **me)
{
	check_verticies(me, NULL);
	if (!(*me)->e)
	{
		delete_graph_2(me);
		err_println_str("There are no adjacent verticies");
	}
}
