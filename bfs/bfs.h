/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:23:48 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/16 12:22:16 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BFS_H
# define BFS_H
# include "../new.h"
# include "../graph/graph.h"
# include "../stack/stack.h"

typedef struct s_marked
{
	t_list	*node;
	t_list	*end;
}	t_marked;

typedef struct s_bfs
{
	int			*marked;
	int			*edge_to;
	int			*dist_to;
	int			len;
	int			src;
	t_marked	*v_mark;
	t_graph		*graph;
}	t_bfs;

t_bfs	*new_bfs(t_graph *graph, int s);
t_bfs	*new_bfs_multi(t_graph *graph, t_st_bag *bag);
void	bfs_ctor(t_bfs **self, t_graph *graph, int s);
void	bfs_ctor_multi(t_bfs **self, t_graph *graph, t_st_bag *bag);
void	delete_bfs(t_bfs **self);
void	bfs_dtor(t_bfs **self);
t_stack	*bfs_path_to(t_bfs *self, int *v);
int		bfs_has_path_to(t_bfs *self, int v);
int		bfs_dist_to(t_bfs *self, int v);
void	bfs_validate_vertex(t_bfs *self, int v);
void	bfs_data_init(t_bfs **self);
void	bfs(t_bfs **self, t_graph *graph, int s);

#endif
