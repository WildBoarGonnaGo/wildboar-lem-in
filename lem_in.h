/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 09:02:04 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/16 14:55:35 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "bfs/bfs.h"

typedef struct s_arr_struct
{
	int	*arr;
	int	size;
	int	stp;
	int	main_path;
	int	indx;
	int	ogate;
}	t_arr_struct;

t_arr_struct	*arr_path(t_bfs **bfs, int *end);
int				check_prog_input(int argc, char **input);
void			list_priority_push(t_list **list, t_bfs **bfs);
t_list			*routing(t_graph *graph);
void			ft_stack_itoa(char **str, long n, int *r);
t_list			*forwarding(t_list **list_path, t_graph **graph);
void			delete_arrs(t_list **list_path);

#endif
