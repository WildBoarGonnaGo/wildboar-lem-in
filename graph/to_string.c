/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 20:35:29 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/15 19:48:42 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

void	gc_strjoin(char **src, char *dst)
{
	char	*del;

	if (!src || !*src)
		err_println(EFAULT);
	del = *src;
	*src = ft_strjoin(*src, dst);
	free(del);
	del = NULL;
}

void	gc_strjoin_2(char **src, char **dst)
{
	char	*del;
	char	*del2;

	if (!src || !*src || !dst || !*dst)
		err_println(EFAULT);
	del = *src;
	del2 = *dst;
	*src = ft_strjoin(*src, *dst);
	free(del);
	del = NULL;
	free(del2);
	del2 = NULL;
}

void	push_line(t_graph *me, char **res, int vert)
{
	t_data				*t_data_aux;
	t_st_bag_iterator	*walker;

	gc_strjoin(res, "\n");
	t_data_aux = (t_data *)me->adj[vert]->node->content;
	gc_strjoin(res, t_data_aux->name);
	gc_strjoin(res, ": ");
	walker = new_bag_iterator(me->adj[vert]);
	while (has_next(walker))
	{
		t_data_aux = (t_data *)(next(&walker)->content);
		gc_strjoin(res, t_data_aux->name);
		if (has_next(walker))
			gc_strjoin(res, ", ");
	}
	delete_bag_iterator(&walker);
}

char	*to_string(const t_graph *me)
{
	char				*res;
	int					vert;
	char				*aux;

	res = ft_strdup("Verticies: ");
	aux = ft_itoa(me->v);
	gc_strjoin_2(&res, &aux);
	gc_strjoin(&res, "\nEdges: ");
	aux = ft_itoa(me->e);
	gc_strjoin_2(&res, &aux);
	vert = -1;
	while (++vert < me->v)
		push_line((t_graph *)me, &res, vert);
	return (res);
}
