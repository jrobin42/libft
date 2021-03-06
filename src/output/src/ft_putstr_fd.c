/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 18:12:20 by jrobin            #+#    #+#             */
/*   Updated: 2018/03/09 04:34:06 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_string.h"
#include <unistd.h>

void	ft_putstr_fd(char const *str, int fd)
{
	write(fd, str, ft_strlen(str));
}
