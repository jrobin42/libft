/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 21:22:43 by jrobin            #+#    #+#             */
/*   Updated: 2018/03/09 05:23:40 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *str, int c)
{
	int		i;

	if (str)
    {
	    i = 0;
	    while (str[i])
        {
	        if (str[i] == c)
                return ((char *) str + i);
	        i++;
        }
    }
	return (char *)((str && !c) ? str + i : NULL);
}
