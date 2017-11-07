/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 23:51:20 by jrobin            #+#    #+#             */
/*   Updated: 2017/06/21 03:20:03 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*s2;

	i = 0;
	if (s && f)
	{
		if (!(s2 = (char *)malloc((ft_strlen(s) + 1) * sizeof(char))))
			return (0);
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
