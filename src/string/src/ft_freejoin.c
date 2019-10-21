/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 19:57:36 by jrobin            #+#    #+#             */
/*   Updated: 2018/01/30 03:47:27 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_string.h"
#include <stdlib.h>

char	*ft_freejoin(char *s1, char *s2, int sfr)
{
	char	*s3;

	s3 = ft_strjoin(s1, s2);
	if (s1 && (sfr == 1 || sfr == 3))
		free(s1);
	if (s2 && (sfr == 2 || sfr == 3))
		free(s2);
	return (s3);
}
