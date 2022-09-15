/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs_dtor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 23:59:59 by lchantel          #+#    #+#             */
/*   Updated: 2022/07/15 00:00:00 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "depth_first_search.h"

void	dfs_dtor(t_dfs_data **self)
{
	free((*self)->marked);
	free((*self)->edge_to);
	(*self)->marked = NULL;
	(*self)->edge_to = NULL;
	(*self)->count = 0;
}
