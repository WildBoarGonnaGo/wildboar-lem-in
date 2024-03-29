/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   depth_first_search.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 01:07:14 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/15 15:22:00 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEPTH_FIRST_SEARCH_H
# define DEPTH_FIRST_SEARCH_H
# include "graph.h"

typedef struct s_dfs_data
{
	unsigned short	*marked;
	int				*edge_to;
	int				count;
}	t_dfs_data;

void		dfs_ctor(t_dfs_data **self, const t_graph *tgt, int src);
t_dfs_data	*new_dfs_data(const t_graph *tgt, int src);
void		dfs_dtor(t_dfs_data **self);
void		delete_dfs_data(t_dfs_data **self);
int			has_path_to(t_dfs_data *self, int v);

#endif
