/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 20:35:29 by lchantel          #+#    #+#             */
/*   Updated: 2022/07/13 00:47:53 by                  ###   ########.fr       */
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

char	*to_string(const t_graph *me)
{
	char				*res;
	int					vert;
	t_st_bag_iterator	*walker;
	char				*aux;
	t_data				*t_data_aux;

	res = ft_strdup("Verticies: ");
	aux = ft_itoa(me->v);
	gc_strjoin_2(&res, &aux);
	gc_strjoin(&res, "\nEdges: ");
	aux = ft_itoa(me->e);
	gc_strjoin_2(&res, &aux);
	vert = -1;
	while (++vert < me->v)
	{
		gc_strjoin(&res, "\n");
		aux = ft_itoa(vert);
		gc_strjoin_2(&res, &aux);
		gc_strjoin(&res, ": ");
		walker = new_bag_iterator(me->adj[vert]);
		while (has_next(walker))
		{
			t_data_aux = (t_data *)(next(&walker)->content);
			aux = ft_itoa(t_data_aux->indx);
			gc_strjoin_2(&res, &aux);
			if (has_next(walker))
				gc_strjoin(&res, ", ");
		}
	}
	return (res);
}
