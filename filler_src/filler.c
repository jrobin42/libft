/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 10:32:43 by jrobin            #+#    #+#             */
/*   Updated: 2018/02/27 17:21:13 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	*parse_map(t_filler *filler)
{
	int		index_line;
	char	*line;
	int ret = 0;

	index_line = 0;
	line = NULL;
	ret = get_next_line(0, &line); 
	M_MAX_Y = ft_atoi(line + 8);
	MAP = ft_memalloc((M_MAX_Y + 1) * sizeof(char*));
	get_next_line(0, &line);
	while (index_line < M_MAX_Y)
	{
		ret = get_next_line(0, &line);
		*(MAP + index_line) = ft_strdup(line + 4);	//attention leaks, je perd l'adresse initiale de line
		++index_line;
	}
	*(MAP + index_line) = NULL;
	M_MAX_X = ft_strlen(*MAP) - 1;
	M_MAX_Y = M_MAX_Y - 1;
	return (line);
}

void	get_char_player(t_filler *filler)
{
	char	*line;

	line = NULL;
	get_next_line(0, &line);
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

void	free_all(t_filler *filler)
{
	(void)filler;
	//	free_map((map->map));
	//free(map->map);
//	ft_free_tab((void***)&(map->heatmap));
//	ft_free_tab((void***)&(piece->piece));
//	free(piece->x);
//	free(piece->y);
//	free(piece);
}

#define RED "\e[31m"
#define EOC "\e[0m"

int		main(void)
{
	t_filler	filler;
	char		*line;

	get_char_player(&filler);
	while (1)
	{
		line = parse_map(&filler);
		parse_piece(&filler);
		prepare_heatmap(&filler);
		if (search_best_pos(&filler))
		{
			dprintf(2, "\t\tBREAK\n");
			break ;
		}
		ft_printf("%d %d\n", filler.best_y, filler.best_x);
		free_all(&filler);
	}
	/*	ft_printf("3 3\n");
		char *line;
		int i = 30;
		while (i)
		{
		get_next_line(0, &line);
		dprintf(2, "LINE {%s}\n", line);
		--i;
		}*/
	ft_printf("0, 0\n");
	return (0);
}
