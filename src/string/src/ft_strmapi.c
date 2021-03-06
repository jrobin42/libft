/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 23:51:20 by jrobin            #+#    #+#             */
/*   Updated: 2018/01/30 02:26:41 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_string.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*s2;

	i = 0;
	if (s && f)
	{
		if (!(s2 = (char *)malloc((ft_strlen(s) + 1) * sizeof(char))))
			return NULL;
		while (s[i])
		{
			s2[i] = f(i, s[i]);
			i++;
		}
		s2[i] = 0;
		return (s2);
	}
	return (NULL);
}
