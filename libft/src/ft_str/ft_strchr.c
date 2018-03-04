/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 21:22:43 by jrobin            #+#    #+#             */
/*   Updated: 2018/03/04 17:04:49 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			return ((char *)&str[i]);
	return (c == 0 ? (char *)&str[i] : 0);
}
