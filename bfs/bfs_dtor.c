/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_dtor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 08:43:57 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/13 08:53:35 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bfs.h"

void	bfs_dtor(t_bfs **self)
{
    if ((*self)->v_mark)
    {
        free((*self)->v_mark);
        (*self)->v_mark = NULL;
    }
	free((*self)->marked);
	(*self)->marked = NULL;
	free((*self)->edge_to);
	(*self)->edge_to = NULL;
	free((*self)->dist_to);
	(*self)->dist_to = NULL;
	(*self)->len = 0;
}
