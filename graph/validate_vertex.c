/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_vertex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 18:45:43 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/15 17:05:14 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

void	validate_vertex(const t_graph *me, int v)
{
	char	*err_msg;
	char	*num;
	char	*del;

	if (v < 0 || v >= me->v)
	{
		if (v < 0)
			err_println_str("number of vertex can't be less than 0");
		else
		{
			num = ft_itoa(v);
			err_msg = ft_strdup("number of vertex can't be greater than ");
			del = err_msg;
			err_msg = ft_strjoin(err_msg, num);
			free(del);
			del = NULL;
			err_println_str(err_msg);
		}
	}
}
