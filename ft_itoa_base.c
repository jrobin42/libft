/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 15:48:45 by jrobin            #+#    #+#             */
/*   Updated: 2018/01/17 18:45:38 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		count_n(long n, int len)
{
	int		i;

	i = 0;
	while (n)
	{
		n = n / len;
		++i;
	}
	return (i);
}

char	*ft_itoa_base(long n, char *base)
{
	int		i;
	int		mod;
	long	div;
	int		len;
	char	*s;

	len = ft_strlen(base);
	i = count_n(n, len);
	(len == 10 && n < 0) ? ++i: 0;
	s = (char *)malloc((i + 1) * sizeof(char));
	s[i - 1] = (len == 10 && n < 0) ? '-': 1;
	s[i] = 0;
	i = 0;
	while (n)
	{
		div = n / len;
		mod = n % len;
		mod = mod < 0 ? -mod : mod;
		s[i] = base[mod];
		n = div;
		++i;
	}
	s = ft_reverse(s);
	return (s);
}
