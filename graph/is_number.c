/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 02:25:18 by lchantel          #+#    #+#             */
/*   Updated: 2022/07/13 02:25:19 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph_ctor_in.h"

int		is_number(char *line)
{
	int	i;

	i = -1;
	while(ft_isdigit(line[++i]))
		;
	if (!line[i])
		return (1);
	else
		return (0);
}