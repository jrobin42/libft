/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 22:30:32 by jrobin            #+#    #+#             */
/*   Updated: 2017/06/20 11:13:55 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int				len_dest;
	unsigned long	j;

	len_dest = ft_strlen(dest);
	j = 0;
	while (src[j])
		dest[len_dest++] = src[j++];
	dest[len_dest] = '\0';
	return (dest);
}
