/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_println.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 20:58:24 by lchantel          #+#    #+#             */
/*   Updated: 2022/06/27 09:43:27 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "new.h"

void	err_println(int errnum)
{
	ft_putstr_fd("lem-in: error: ", 2);
	ft_putendl_fd(strerror(errnum), 2);
	exit (-1);
}
