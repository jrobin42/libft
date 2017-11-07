/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 07:19:15 by jrobin            #+#    #+#             */
/*   Updated: 2017/07/10 18:47:10 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	int		len;

	len = ft_strlen(dst);
	((int)size - (len + 1) > 0) ? ft_strncat(dst, src, size - (len + 1)) : 0;
	return (ft_strlen(src) + (((len >= (int)ft_strlen(dst)) ? size : len)));
}
