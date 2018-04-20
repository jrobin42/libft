/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 18:28:22 by jrobin            #+#    #+#             */
/*   Updated: 2018/03/06 09:39:54 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_type.h"
#include "libft_str.h"
#include "libft_int.h"
#include "ft_printf.h"

int		between_min_max(char *s, int sign)
{
	int		i;

	if (ft_strlen(s) >= 10)
	{
		i = 0;
		while (ft_isdigit(*(s + i)))
			++i;
		*(s + i) = 0;
		if (ft_strlen(s) == 10)
		{
			if (sign == 1)
			{
				if (ft_strcmp(s, "2147483647") > 0)
					return (0);
			}
			else
				if (ft_strcmp(s, "2147483648") > 0)
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
	int		sign;

	if (s)
	{
		i = 0;
		sign = 1;
		while (*s && ft_isspace(*s))
			++s;
		if (*s && (*s == '+' || *s == '-') && s++)
			*s == '-' ? sign = -1 : 0;
		while (*s == '0')
			++s;
		if (!*s && *(s - 1) == '0')
			return (1);
		while (*(s + i) && ft_isdigit(*(s + i)))
			++i;
		while (*(s + i) && ft_isspace(*(s + i)))
			++i;
		if (*(s + i))
			return (0);
		return ((*(s + 1) && between_min_max((s + 1), sign)) ||
				(*s && !*(s + 1) && ft_isdigit(*s)) ? 1 : 0);
	}
	return (0);
}
