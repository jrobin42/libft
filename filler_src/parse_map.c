/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 08:29:07 by jrobin            #+#    #+#             */
/*   Updated: 2018/02/26 19:25:07 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			intensity_for_each(t_map *map, int score)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < MAX_Y)
	{
		while (x < MAX_X)
		{
			if ((H_MAP[y][x] == -1 && score == 0) || (H_MAP[y][x] == score && score))
			{
				y > 0 && H_MAP[y - 1][x] == 0 ? H_MAP[y - 1][x] = score + 1 : 0;
				y < MAX_Y - 1 && H_MAP[y + 1][x] == 0 ? H_MAP[y + 1][x] = score + 1 : 0;
				x > 0 && H_MAP[y][x - 1] == 0 ? H_MAP[y][x - 1] = score + 1 : 0;
				x < MAX_X - 1 && H_MAP[y][x + 1] == 0 ? H_MAP[y][x + 1] = score + 1 : 0;
			}
			else if (H_MAP[y][x] == -2)
			{
				y > 0 && H_MAP[y - 1][x] == 0 ? H_MAP[y - 1][x] = score + 1 : 0;
				y < MAX_Y - 1 && H_MAP[y + 1][x] == 0 ? H_MAP[y + 1][x] = score + 1 : 0;
				x > 0 && H_MAP[y][x - 1] == 0 ? H_MAP[y][x - 1] = score + 1 : 0;
				x < MAX_X - 1 && H_MAP[y][x + 1] == 0 ? H_MAP[y][x + 1] = score + 1 : 0;
			}
			++x;
		}
		x = 0;
		++y;
	}
	return (0);
}

int			heatmap_not_ready(t_map *map)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < MAX_Y)
	{
		while (x < MAX_X)
		{
			if (H_MAP[y][x] == 0)
			{
				return (1);
			}
			++x;
		}
		x = 0;
		++y;
	}
	return (0);
}

t_filler	*prepare_heatmap(t_map *map, t_filler *filler)
{
	int			i;
	int			j;
	int			score;

	i = 0;
	j = 0;
	score = 0;
	map->max_x += 1;
	map->max_y += 1;
	map->heatmap = ft_memalloc(map->max_y * sizeof(int*));
	while (i < map->max_y)
	{
		map->heatmap[i] = ft_memalloc(map->max_x * sizeof(int));
		while (j < map->max_x)
		{
			map->heatmap[i][j] = MAP[i][j] == filler->adv_char ? -1 : -2;
			MAP[i][j] == '.' ? map->heatmap[i][j] = 0 : 0;
			++j;
		}
		j = 0;
		++i;
	}
	i = 0;
	while (heatmap_not_ready(map))
	{
		intensity_for_each(map, score);
		++score;




/*
if (i == 0)

//AFFICHAGE DEBUG
	j = 0;
	while (i < MAX_Y)
	{
		while (j < MAX_X)
		{
			dprintf(2, "%3d ", H_MAP[i][j]);
			++j;
		}
		j = 0;
		dprintf(2, "\n");
		++i;
	}
//AFFICHAGE DEBUG fin
*/
	}




	return(filler);
}
