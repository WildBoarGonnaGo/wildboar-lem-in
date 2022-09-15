/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 20:43:13 by lchantel          #+#    #+#             */
/*   Updated: 2022/09/15 20:09:13 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEW_H
# define NEW_H
# include <sys/errno.h>
# include <string.h>
# include "libft/libft.h"

void				err_println(int errnum);
void				err_println_str(char *msg);

#endif