/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 10:32:43 by jrobin            #+#    #+#             */
/*   Updated: 2018/02/26 19:24:40 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	parse_map(t_map *map)
{
	int		index_line;
	char	*line;
	int 	ret;

	index_line = 0;
	ret = 1;
	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		dprintf(2, "Taille plateau {%s}\n", line);
		if (ft_strstr(line, "Plateau"))
		{
			map->max_y = ft_atoi(line + 8);
			break;
		}
	}
	MAP = ft_memalloc((map->max_y + 1) * sizeof(char*));
	get_next_line(0, &line);
	dprintf(2, "ordonnes {%s}\n", line);
	while (index_line < map->max_y)
	{
		if (get_next_line(0, &line) == 0)
		{
			break;
		}
		dprintf(2, "map {%s}\n", line);
		*(MAP + index_line) = line + 4;
		++index_line;
	}
	*(MAP + index_line) = NULL;
	map->max_x = ft_strlen(*MAP) - 1;
	map->max_y = map->max_y - 1;
}

void	get_char_player(t_filler *filler)
{
	char	*line;

	get_next_line(0, &line);
	dprintf(2, "Char player {%s}\n", line);
	filler->my_char = *(line + 10) == '1' ? 'O' : 'X';
	filler->adv_char = filler->my_char == 'X' ? 'O' : 'X';
}

void	free_map(char **map)
{
	int		i;

	i = 0;
	if (map)
	{
		if (*map)
		{
			while (map[i] && map[i] - 4)
			{
				free(map[i] - 4);
				++i;
			}
		}
		free(map);
	}
}

void	free_all(t_piece *piece, t_map *map)
{
	free_map((map->map));
	ft_free_tab((void***)&(map->heatmap));
	ft_free_tab((void***)&(piece->piece));
	free(piece->x);
	free(piece->y);
	free(piece);
}

int		main(void)
{
/*	t_piece		*piece;
	t_map		map;
	t_filler	*filler;

	filler = ft_memalloc(sizeof(*filler));
	get_char_player(filler);
//	while (1)
//	{
		parse_map(&map);
		filler = parse_piece(&piece, filler);
		prepare_heatmap(&map, filler);
		if (!search_best_pos(piece, &map, filler)) //attention virer le !
//			break ;
//		else
			ft_printf("%d %d\n", filler->best_y, filler->best_x);
//		free_all(piece, &map);
		sleep(5);
//	}
		parse_map(&map);
		filler = parse_piece(&piece, filler);
		prepare_heatmap(&map, filler);
		if (!search_best_pos(piece, &map, filler))
	//		break ;
//		else
			ft_printf("%d %d\n", filler->best_y, filler->best_x);
		free_all(piece, &map);
		sleep(5);

	free_all(piece, &map);
	free(filler);*/
//	ft_printf("3 3\n");
	return (0);
}
