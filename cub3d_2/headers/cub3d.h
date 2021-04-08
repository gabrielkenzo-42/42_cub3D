/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkenzo-s <gkenzo-s@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 04:50:26 by gkenzo-s          #+#    #+#             */
/*   Updated: 2021/02/24 04:50:28 by gkenzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define BUFFER_SIZE 128
# define ESC 65307
# define OK 1
# define ERROR 0

# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100

# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <stdio.h>

# include <fcntl.h>

typedef struct	s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}				t_image;

typedef struct	s_map
{
	char	**map;
	int		rows;
	int		columns;
}				t_map;

typedef struct	s_texture
{
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	char	*sprite;
}				t_texture;

typedef struct	s_player
{
	double	x;
	double	y;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
}				t_player;


typedef struct	s_game
{
	int			index;
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	int			floor_color;
	int			ceilling_color;
	t_image		*img;
	t_image		*next_img;
	t_map		*map;
	t_texture	*tex;
	t_player	*player;
}				t_game;


/*
** get_next_line
*/
int				get_next_line(int fd, char **line);


/*
** general
*/
int				create_trgb(int t, int r, int g, int b);

#endif
