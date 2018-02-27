/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 08:29:07 by jrobin            #+#    #+#             */
/*   Updated: 2018/02/27 17:18:47 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		intensity_for_each(t_filler *filler, int n)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < M_MAX_Y)
	{
		while (x < M_MAX_X)
		{
			if ((H_MAP[y][x] == -1 && !n) ||
				(H_MAP[y][x] == n && n) || H_MAP[y][x] == -2)
			{
				y > 0 && H_MAP[y - 1][x] == 0 ? H_MAP[y - 1][x] = n + 1 : 0;
				y < M_MAX_Y - 1 && H_MAP[y + 1][x] == 0 ?
					H_MAP[y + 1][x] = n + 1 : 0;
				x > 0 && H_MAP[y][x - 1] == 0 ? H_MAP[y][x - 1] = n + 1 : 0;
				x < M_MAX_X - 1 && H_MAP[y][x + 1] == 0 ?
					H_MAP[y][x + 1] = n + 1 : 0;
			}
			++x;
		}
		x = 0;
		++y;
	}
}

static int		heatmap_not_ready(t_filler *filler)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < M_MAX_Y)
	{
		while (x < M_MAX_X)
		{
			if (H_MAP[y][x] == 0)
				return (1);
			++x;
		}
		x = 0;
		++y;
	}
	return (0);
}

void		prepare_heatmap(t_filler *filler)
{
	int			i;
	int			j;
	int			score;

	i = 0;
	j = 0;
	score = 0;
	M_MAX_X += 1;
	M_MAX_Y += 1;
	H_MAP = ft_memalloc(M_MAX_Y * sizeof(int*));
	while (i < M_MAX_Y)
	{
		H_MAP[i] = ft_memalloc(M_MAX_X * sizeof(int));
		while (j < M_MAX_X)
		{
			H_MAP[i][j] = MAP[i][j] == ADV ? -1 : -2;
			MAP[i][j] == '.' ? H_MAP[i][j] = 0 : 0;
			++j;
		}
		j = 0;
		++i;
	}
	while (heatmap_not_ready(filler))
	{
		intensity_for_each(filler, score);
		++score;
	}

/*
//AFFICHAGE DEBUG
	i = 0;
	j = 0;
	while (i < MAX_Y)
	{
		dprintf(2, "l%d\t{", i);
		while (j < MAX_X)
		{
			dprintf(2, "%2d ", H_MAP[i][j]);
			++j;
		}
		j = 0;
		dprintf(2, "}\n");
		++i;
	}
//AFFICHAGE DEBUG fin
*/
}
