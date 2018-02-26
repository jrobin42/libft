/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 07:34:05 by jrobin            #+#    #+#             */
/*   Updated: 2018/02/26 16:38:14 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


//# include "libft_str.h"
# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include <stdio.h>

# define MAP map->map
# define H_MAP map->heatmap
# define MAX_X map->max_x
# define MAX_Y map->max_y

typedef struct	s_map
{
	int			max_x;
	int			max_y;
	char		**map;
	int			**heatmap;
}				t_map;

typedef struct	s_piece
{
	char		**piece;
	int			nb_stars;
	int			max_x;
	int			max_y;
	int			*x;
	int			*y;
}				t_piece;

typedef struct	s_filler
{
	int			best_x;
	int			best_y;
	long		best_score;
	int			offset_x;
	int			offset_y;
	int			not_finish;
	char		my_char;
	char		adv_char;
}				t_filler;

t_filler		*parse_piece(t_piece **piece, t_filler *filler);
t_filler		*prepare_heatmap(t_map *map, t_filler *filler);
int				search_best_pos(t_piece *piece, t_map *map, t_filler *filler);

#endif
