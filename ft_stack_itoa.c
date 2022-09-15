/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_itoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 10:54:33 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/15 11:00:46 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	getnumsize(long n)
{
	int	size;

	size = 0;
	if (!n)
		return (1);
	if (n < 0)
	{
		n *= -1;
		++size;
	}
	n /= 10;
	while (n)
	{
		++size;
		n /= 10;
	}
	return (++size);
}

void	ft_stack_itoa(char **str, long n, int *r)
{
	long	val;
	int		size;

	val = n;
	size = getnumsize(val);
	*r += size;
	if (n < 0)
		val *= -1;
	*(*str + size--) = '\0';
	while (size >= 0)
	{
		if (!size && n < 0)
		{
			*(*str + size) = '-';
			break ;
		}
		*(*str + size) = val % 10 + 48;
		val /= 10;
		--size;
	}
}
