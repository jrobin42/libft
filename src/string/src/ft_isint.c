/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 18:28:22 by jrobin            #+#    #+#             */
/*   Updated: 2018/04/29 00:00:33 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_string.h"
#include "f_string.h"

int		between_min_max(char *s, int sign)
{
	int		i;

	if (ft_strlen(s) >= 10)
	{
		i = 0;
		while (*(s + i) && ft_isdigit(*(s + i)))
			++i;
		if (s[i])
			s[i] = 0;
		if (ft_strlen(s) == 10)
		{
			if (sign == 1)
			{
				if (ft_strcmp(s, "2147483647") > 0)
					return (0);
			}
			else if (ft_strcmp(s, "2147483648") > 0)
				return (0);
		}
		else
			return (0);
	}
	return (1);
}

int		ft_isint(char *s)
{
	int		i;
	int		j;
	int		sign;

	if (!s)
		return (0);
	i = 0;
	sign = 1;
	while (s[i] && ft_isspace(s[i]))
		++i;
	if (s[i] && (s[i] == '+' || s[i] == '-'))
		s[i++] == '-' ? sign = -1 : 0;
	while (s[i] == '0')
		++i;
	if (!s[i] && i > 0 && s[i - 1] == '0')
		return (1);
	j = i;
	while (s[i] && ft_isdigit(s[i]))
		++i;
	while (s[i] && ft_isspace(s[i]))
		++i;
	if (s[i])
		return (0);
	return ((s[j] && between_min_max((s + j), sign)));
}
