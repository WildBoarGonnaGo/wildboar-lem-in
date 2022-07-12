/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bag.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:07:11 by lchantel          #+#    #+#             */
/*   Updated: 2022/07/11 21:20:37 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BAG_H
# define BAG_H
# include "./libft/libft.h"

typedef struct s_data
{
	int	indx;
	int	x;
	int	y;
}	t_data;

typedef struct s_st_bag {
	t_list	*node;
	int		size;
	t_list	*begin;
	t_list	*end;
	int		state;
}	t_st_bag;

typedef struct s_st_bag_iterator
{
	t_list	*it;
}	t_st_bag_iterator;

void				st_bag_ctor(t_st_bag **self);
void				st_bag_dtor(t_st_bag **self, void (*del)(void *));
void				st_bag_copy_assign(t_st_bag **self, const t_st_bag *that);
void				add(t_st_bag **self, void *item);
int					is_empty(const t_st_bag *self);
int					size(const t_st_bag *self);

void				t_st_bag_iterator_ctor(t_st_bag_iterator **self,
						const t_st_bag *src);
void				t_st_bag_iterator_dtor(t_st_bag_iterator **self);
int					has_next(const t_st_bag_iterator *self);
t_list				*next(t_st_bag_iterator **self);
void				del_list(void *item);
void				del_list2(void *item);

#endif
