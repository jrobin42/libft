/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 09:36:06 by jrobin            #+#    #+#             */
/*   Updated: 2018/02/26 19:25:45 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_coord_piece(t_piece *piece)
{
	int			i;
	int			x;
	int			y;

	i = 0;
	x = 0;
	y = 0;
	piece->x = ft_memalloc(piece->nb_stars * sizeof(*(piece->x)));
	piece->y = ft_memalloc(piece->nb_stars * sizeof(*(piece->y)));
	while (piece->piece[y])
	{
		while (piece->piece[y][x])
		{
			if (piece->piece[y][x] == '*')
			{
				piece->x[i] = x;
				piece->y[i] = y;
				++i;
			}
			++x;
		}
		x = 0;
		++y;
	}
}

t_filler	*get_offset(t_piece *piece, t_filler *filler)
{
	int			i;
	int			x;

	i = 0;
	x = piece->max_x;
	filler->offset_y = piece->y[0];
	filler->offset_x = *(piece->x);
	while (x + 1 && filler->offset_x)              //filler->offset_x == 0 ! 
	{
		piece->x[i] < filler->offset_x ? filler->offset_x = piece->x[i] : 0;
		--x;
	}
	return (filler);
}

void		count_stars(t_piece *piece)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	piece->nb_stars = 0;
	while (piece->piece[i])
	{
		while (piece->piece[i][j])
		{
			if (piece->piece[i][j] == '*')
				++piece->nb_stars;
			++j;
		}
		j = 0;
		++i;
	}
}

t_filler	*parse_piece(t_piece **piece, t_filler *filler)
{
	int			index_line;
	char		*line;

	*piece = ft_memalloc(sizeof(t_piece));
	index_line = 0;
	get_next_line(0, &line);
	dprintf(2, "Coord piece {%s}\n", line);
	(*piece)->max_y = ft_atoi(line + 6);
	(*piece)->piece = ft_memalloc(((*piece)->max_y + 1) * sizeof(char*));
	while (index_line < (*piece)->max_y)
	{
		get_next_line(0, &line);
		dprintf(2, "piece {%s}\n", line);
		*((*piece)->piece + index_line) = line;
		++index_line;
	}
	*((*piece)->piece + index_line) = NULL;
	(*piece)->max_x = ft_strlen(line);
	count_stars(*piece);
	get_coord_piece(*piece);
	return (get_offset(*piece, filler));
}