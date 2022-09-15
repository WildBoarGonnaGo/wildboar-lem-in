/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 11:43:32 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/15 16:56:24 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_H
# define GRAPH_H
# include "../bag.h"

typedef struct s_graph
{
	int			v;
	int			e;
	int			start;
	int			end;
	int			*ants;
	int			size;
	int			state;
	int			ants_num;
	t_list		*input_data;
	t_st_bag	**adj;
}	t_graph;

void		graph_ctor_in(t_graph **me);
void		graph_dtor(t_graph **me, void (*del)(void *));
void		validate_vertex(const t_graph *me, int v);
void		add_edge(t_graph **me, char *v, char *w);
t_st_bag	*adj(const t_graph *me, int v);
char		*to_string(const t_graph *me);
t_graph		*new_graph(void);
void		delete_graph(t_graph **self, void (*del)(void *));
void		delete_graph_2(t_graph **self);
void		graph_dtor_2(t_graph **self);

#endif