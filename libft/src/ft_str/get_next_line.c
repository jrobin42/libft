/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 06:39:25 by jrobin            #+#    #+#             */
/*   Updated: 2018/02/27 12:29:10 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"
#include "libft_put.h"
#include "libft_mem.h"

#include <fcntl.h>
#include <stdio.h>

int		add_stock(char *stock, char **line)
{
	char	*tmp;

	tmp = *line;
	if (!(ft_strlen(*line)))
		*line = ft_strdup(stock);
	else
		*line = ft_strjoin(*line, stock);
	free(tmp);
	return (*line == NULL ? -1 : 1);
}

int		is_nl(char *stock, int i, char **line, int ret)
{
	stock[i] = 0;
	ret = add_stock(stock, line);
	ft_strcpy(stock, &(stock[i + 1]));	//utile ?
	return (ret > 0 ? 1 : -1);
}

int		read_fd(int fd, char *stock, int *ret, char *line)
{
	int		ret_tmp;

	ret_tmp = 0;
	if ((*ret = read(fd, stock, BUFF_SIZE_GNL)) == -1)
		return (-1);
/*
	//VALEUR RETOUR READ
	write(2, "ret = [", 7);
	ft_putnbr_fd(*ret, 2);
	write(2, "]\n", 2);


	//STOCK AFTER READ
	write(2, "AFTER READ = {", 14);
	write(2, stock, *ret);
	write(2, "} ENDOFSTOCK\n", 13);


*/	stock[*ret] = 0;
	if (!(*ret) && !ft_strlen(line)/* && !ft_strlen(stock)*/) //ajout !ft_strlen(stock)
	{
		free(line);
		line = NULL;
		return (0);
	}
	return (1);
}

int		no_nl(char *stock, char ***line, int ret, int j)
{
	(void)ret;
	if (add_stock(stock, *line) == -1)
		return (-1);
	while (++j < BUFF_SIZE_GNL)
		stock[j] = 0;
	if ((**line - ft_strchr(**line, '\n')/* - **line*/) < 0)
		return (1);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	int				i;
	int				j;
	int				ret;
	static char		stock[BUFF_SIZE_GNL];

	if (fd < 0 || line == NULL || BUFF_SIZE_GNL < 1)
		return (-1);
	ret = BUFF_SIZE_GNL;
	*line = ft_strnew(0);
	while (ret)
	{
		if ((i = (!ft_strlen(stock) ? read_fd(fd, stock, &ret, *line) : 1)) < 1 /*|| */)
		{
//			dprintf(2, "Areturn (%d)\n", i);
			return (i);
		}
		if ((i = (ft_strchr(stock, '\n') - stock)) < 0)
			if ((j = no_nl(stock, &line, ret, -1)) != 0)
			{
//			dprintf(2, "Jreturn (%d) line = {%s} stock = {%s}\n", j, *line, stock);
				return (j);
			}
		if ((i = (i >= 0 ? is_nl(stock, i, line, 1) : 0)))
		{
//			dprintf(2, "Creturn (%d) line = {%s} stock = {%s}\n", i, *line, stock);
			return (i);
		}
	}
//	dprintf(2, "Dreturn (0)\n");
	return (0);
}
