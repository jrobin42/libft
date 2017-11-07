/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 19:17:34 by jrobin            #+#    #+#             */
/*   Updated: 2017/06/20 11:39:31 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *str)
{
	char	*cpy;
	int		i;

	i = -1;
	if (!(cpy = (char *)malloc((ft_strlen(str) + 1) * sizeof(char))))
		return (0);
	while (str[++i])
		cpy[i] = str[i];
	cpy[i] = '\0';
	return (cpy);
}
