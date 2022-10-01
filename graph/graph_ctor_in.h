/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_ctor_in.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 02:14:27 by lchantel          #+#    #+#             */
/*   Updated: 2022/07/13 02:14:29 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_CTOR_IN_H
# define GRAPH_CTOR_IN_H
# include "graph.h"

void	graph_init(t_graph **me, int *num);
void	mark_start(t_graph **me, char *line);
void	mark_end(t_graph **me, char *line);
void	get_number(t_graph **me, char *line);
int		is_number(char *line);
void	delete_array2d(void **mem);
void	alloc_array(t_graph **me);
void	add_vertex(t_graph **me, char *line);
void	delete_line(char **line);
void	parse_line(t_graph **me, char *line);
void	check_input_data(t_graph **me);
void	line_analisys(t_graph **me, char **line, int *num);

#endif