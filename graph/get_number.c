/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 02:23:59 by lchantel          #+#    #+#             */
/*   Updated: 2022/07/13 02:24:58 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph_ctor_in.h"

void	get_number(t_graph **me, char *line)
{
	int	i;

	i = -1;
	while (line[++i] && ft_isdigit(line[i]))
		;
	if (line[i])
		err_println_str("wrong syntax: invalid number of ants");
	(*me)->ants = ft_atoi(line);
}
