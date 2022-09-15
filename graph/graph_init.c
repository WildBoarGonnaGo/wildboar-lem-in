/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:58:26 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/15 16:59:32 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph_ctor_in.h"

void	graph_init(t_graph **me, int *num)
{
	(*me)->v = 0;
	(*me)->e = 0;
	(*me)->start = -2;
	(*me)->end = -2;
	(*me)->ants = 0;
	(*me)->adj = NULL;
	(*me)->size = 0;
	*num = 0;
	(*me)->state = 0;
	(*me)->input_data = NULL;
}
