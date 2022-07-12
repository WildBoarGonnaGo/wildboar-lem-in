/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_graph.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:37:38 by lchantel          #+#    #+#             */
/*   Updated: 2022/07/11 16:24:25 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./graph.h"

t_graph	*new_graph()
{
	t_graph	*res;

	res = (t_graph *)malloc(sizeof(t_graph));
	if (!res)
		err_println(ENOMEM);
	graph_ctor_in(&res);
	return (res);
}