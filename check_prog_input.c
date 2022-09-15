/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_prog_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 09:07:15 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/16 00:35:03 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	check_prog_input(int argc, char **input)
{
	int	len;

	if (argc < 3)
		return (0);
	if (ft_strncmp(input[1], "<", 1))
	{
		ft_putendl_fd("no arrow", 1);
		return (0);
	}
	len = ft_strlen(input[2]);
	if (len < 5 || ft_strncmp(".map", *(input + 2) + len - 4, 4))
		return (0);
	return (1);
}
