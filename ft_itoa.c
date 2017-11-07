/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 15:48:45 by jrobin            #+#    #+#             */
/*   Updated: 2017/06/20 07:27:38 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*nb;
	int		i;
	int		j;
	int		tmp;

	i = 0;
	j = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0 && ++j)
		n = -n;
	tmp = n;
	while (tmp != 0 && ++i)
		tmp = tmp / 10;
	i = n == 0 ? 1 : i;
	if (!(nb = (char *)malloc((i + j + 1) * sizeof(char))))
		return (0);
	nb[0] = j == 1 ? '-' : ' ';
	nb[i + j] = 0;
	while (i-- > 0)
	{
		nb[i + j] = (n % 10) + 48;
		n = n / 10;
	}
	return (nb);
}
