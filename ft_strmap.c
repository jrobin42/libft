/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 23:51:20 by jrobin            #+#    #+#             */
/*   Updated: 2017/06/15 11:42:00 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*s2;

	i = -1;
	if (s && f)
	{
		if (!(s2 = (char *)malloc((ft_strlen(s) + 1) * sizeof(char))))
			return (0);
		while (s[++i])
			s2[i] = f(s[i]);
		s2[i] = 0;
		return (s2);
	}
	return (NULL);
}
