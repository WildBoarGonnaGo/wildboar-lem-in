/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_path_to.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 07:15:56 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/08 18:55:44 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "depth_first_search.h"

void		validate_vertex(t_dfs_data *self, int v)
{
	if (v < 0 || v > self->count)
		err_println("")
}

int			has_path_to(t_dfs_data *self, int v)
{

}