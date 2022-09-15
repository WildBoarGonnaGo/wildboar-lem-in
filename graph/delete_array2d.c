/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_array2d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 02:27:31 by lchantel          #+#    #+#             */
/*   Updated: 2022/07/13 02:27:32 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph_ctor_in.h"

void	delete_array2d(void **mem)
{
	int	i;

	i = -1;
	while (mem[++i])
	{
		free(mem[i]);
		mem[i] = NULL;
	}
	free(mem);
	mem = NULL;
}
