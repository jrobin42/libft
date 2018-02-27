/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 09:36:06 by jrobin            #+#    #+#             */
/*   Updated: 2018/02/27 17:58:58 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_coord_piece(t_filler *filler)
{
	int			i;
	int			x;
	int			y;

	i = 0;
	x = 0;
	y = 0;
	P_AXE_X = ft_memalloc(NB_STARS * sizeof(*P_AXE_X));
	P_AXE_Y = ft_memalloc(NB_STARS * sizeof(*P_AXE_Y));
	while (PIECE[y])										//et nb_stars != i (?)
	{
		while (PIECE[y][x])
		{
			if (PIECE[y][x] == '*')
			{
				P_AXE_X[i] = x;
				P_AXE_Y[i] = y;
				++i;
			}
			++x;
		}
		x = 0;
		++y;
	}
}

void	get_offset(t_filler *filler)
{
	int			i;
	int			x;

	i = 0;
	x = P_MAX_X;
	OFF_Y = *P_AXE_Y;
	OFF_X = *P_AXE_X;
	while (x + 1 && OFF_X) 
	{
		P_AXE_X[i] < OFF_X ? OFF_X = P_AXE_X[i] : 0;
		--x;
	}
}

void		count_stars(t_filler *filler)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	NB_STARS = 0;
	while (PIECE[i])
	{
		while (PIECE[i][j])
		{
			if (PIECE[i][j] == '*')
				++NB_STARS;
			++j;
		}
		j = 0;
		++i;
	}
}

void	parse_piece(t_filler *filler)
{
	int			index_line;
	char		*line;

//	*piece = ft_memalloc(sizeof(t_piece));
	index_line = 0;
	get_next_line(0, &line);
	P_MAX_Y = ft_atoi(line + 6);
	PIECE = ft_memalloc((P_MAX_Y + 1) * sizeof(char*));
	while (index_line < P_MAX_Y)
	{
		get_next_line(0, &line);
		*(PIECE + index_line) = ft_strdup(line);
		line = NULL;
		++index_line;
	}
	*(PIECE + index_line) = NULL;
	P_MAX_X = ft_strlen(line);
	count_stars(filler);
	get_coord_piece(filler);
	get_offset(filler);
}
