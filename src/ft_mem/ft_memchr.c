/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 21:37:34 by jrobin            #+#    #+#             */
/*   Updated: 2018/03/04 18:03:40 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_mem.h"

void	*ft_memchr(const void *s, int c, unsigned long n)
{
	const char		*str;
	unsigned long	i;

	str = (const char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (char)c)
			return ((void *)(str + i));
		i++;
	}
	return (NULL);
}
