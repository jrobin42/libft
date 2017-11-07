/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 07:19:15 by jrobin            #+#    #+#             */
/*   Updated: 2017/07/29 09:03:18 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	int	len;

	len = (int)ft_strlen(dst);
	((int)size - (len + 1)) > 0 ? ft_strncat(dst, src, size - (len + 1))  : 0;
	return (ft_strlen(src) + (((len >= (int)ft_strlen(dst)) ? size : len)));
}

int			main(void)
{
	char	dst[10] = "1234";
	char	dst2[10] = "1234567890";
	printf("strlcat = %s\t\t%lu \t%s\n", dst, strlcat(dst, "ii", 8), dst);
	printf("ft_strlcat =\t\t%lu\n", ft_strlcat(dst2, "ii", 10));
	return (0);
}
