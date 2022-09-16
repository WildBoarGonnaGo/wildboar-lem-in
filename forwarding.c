/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forwarding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 11:01:31 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/16 15:45:29 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "queue/queue.h"

void	aux_build_frame(t_data **data_send, t_data **data_rec,
						int *num, char *str)
{
	char	*aux_str;

	num[3] = *(int *)queue_peek((*data_send)->ants);
	if (!(*data_rec)->ants)
		(*data_rec)->ants = new_queue();
	enqueue(&(*data_rec)->ants, dequeue(&(*data_send)->ants));
	if (num[4])
		str[num[4]++] = ' ';
	str[num[4]++] = 'L';
	aux_str = str + num[4];
	ft_stack_itoa(&aux_str, num[3], &num[4]);
	str[num[4]++] = '-';
	num[3] = -1;
	num[5] = ft_strlen((*data_rec)->name);
	while (++num[3] < num[5])
		str[num[4]++] = (*data_rec)->name[num[3]];
	if (queue_is_empty((*data_send)->ants))
		delete_queue(&(*data_send)->ants);
}

int	build_frame(int *num, t_graph **graph,
			t_arr_struct *aux, char *str)
{
	t_data		*data[2];
	t_st_bag	**adj;

	adj = (*graph)->adj;
	data[0] = (t_data *)adj[aux->arr[num[0]]]->node->content;
	data[1] = (t_data *)adj[aux->arr[num[0] + 1]]->node->content;
	if (!data[1]->ants || queue_is_empty(data[1]->ants))
		num[2] = 0;
	if (!num[0])
		++num[6];
	if (data[0]->ants && !queue_is_empty(data[0]->ants))
		aux_build_frame(&data[0], &data[1], num, str);
	if (!num[2])
		return (0);
	++num[0];
	return (1);
}

int	roll_it(t_list **roll, t_graph **graph,
			int *num, char *str)
{
	t_st_bag		**adj;
	t_arr_struct	*aux;
	t_data			*data[2];

	aux = (t_arr_struct *)(*roll)->content;
	adj = (*graph)->adj;
	num[0] = aux->stp;
	num[1] = aux->size;
	if (!aux->main_path && aux->size - 2 > (*graph)->ants_num && !aux->ogate)
		return (0);
	else
		if (!aux->main_path && aux->size - 2 <= (*graph)->ants_num)
			aux->ogate = 1;
	data[0] = (t_data *)adj[aux->arr[num[0]]]->node->content;
	while (!data[0]->ants)
		data[0] = (t_data *)adj[aux->arr[++num[0]]]->node->content;
	aux->stp = num[0];
	num[2] = 1;
	while (num[0] < aux->size - 1)
	{
		if (!build_frame(num, graph, aux, str))
			return (1);
	}
	(*graph)->ants_num -= num[6];
	return (1);
}

t_list	*forwarding(t_list **list_path, t_graph **graph)
{
	int		num[7];
	t_list	*roll;
	char	str[512];

	if (!list_path || !*list_path)
		err_println_str("routes can't be established");
	ft_bzero(str, 512);
	roll = *list_path;
	num[4] = 0;
	while (roll)
	{
		num[6] = 0;
		if (!roll_it(&roll, graph, num, str))
			break ;
		roll = roll->next;
	}
	if (!str[0])
		return (NULL);
	str[num[4]] = '\n';
	return (ft_lstnew(ft_strdup(str)));
}
