/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_dfs_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 23:55:09 by lchantel          #+#    #+#             */
/*   Updated: 2022/07/14 23:59:44 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "depth_first_search.h"

t_dfs_data	*new_dfs_data(const t_graph *tgt, int src)
{
	t_dfs_data	*res;

	res = (t_dfs_data *)malloc(sizeof(t_dfs_data));
	if (!res)
		err_println(ENOMEM);
	dfs_ctor(&res, tgt, src);
	return (res);
}
