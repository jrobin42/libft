/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 19:17:34 by jrobin            #+#    #+#             */
/*   Updated: 2018/02/01 17:51:05 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_memory.h"
#include "f_string.h"
#include <stdlib.h>

char	*ft_strdup(char *str)
{
	char	*cpy;
	int		i;

	if (!str || !*str)
		return (ft_memalloc(1));
	i = 0;
	if (!(cpy = (char *)malloc((ft_strlen(str) + 1) * sizeof(char))))
		return NULL;
	while (str[i])
	{
		cpy[i] = str[i];
		++i;
	}
	cpy[i] = '\0';
	return (cpy);
}
