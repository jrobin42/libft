/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 19:57:36 by jrobin            #+#    #+#             */
/*   Updated: 2017/06/21 07:12:35 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;

	if (!s1 || !s2 || !(s3 = (char *)ft_memalloc((ft_strlen(s1)
						+ ft_strlen(s2) + 1) * sizeof(char))))
		return (0);
	return (ft_strcat(ft_strcat(s3, s1), s2));
}
