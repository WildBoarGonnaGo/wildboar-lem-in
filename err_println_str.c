/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_println_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 18:53:00 by lchantel          #+#    #+#             */
/*   Updated: 2022/07/03 18:53:09 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "new.h"

void	err_println_str(char *msg)
{
	ft_putstr_fd("lem-in: error: ", 2);
	ft_putendl_fd(msg, 2);
	exit (-1);
}
