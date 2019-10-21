/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_int.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 19:26:38 by jrobin            #+#    #+#             */
/*   Updated: 2018/03/04 19:06:24 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_INT_H
# define LIBFT_INT_H

size_t			ft_wchar_t(wchar_t *s);
int				ft_sqrt(int nb);
int				ft_toupper(int i);
int				ft_tolower(int i);
char			*ft_itoa(int n);
char			*ft_itoa_base(long n, char *base);
char			*ft_ultoa_base(unsigned long n, char *base);
int				ft_power(int nb, int power);
unsigned		ft_absolute(int n);

#endif
