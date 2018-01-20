/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 14:03:44 by jrobin            #+#    #+#             */
/*   Updated: 2018/01/16 14:30:00 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_reverse(char *s)
{
	int		i;
	int		len;
	char	*rev;

	i = 0;
	len = ft_strlen(s);
	rev = (char*)malloc((len + 1) * sizeof(char));
	while (len)
	{
		rev[i] = s[len - 1];
		--len;
		++i;
	}
	rev[i] = 0;
	return (rev);
}
