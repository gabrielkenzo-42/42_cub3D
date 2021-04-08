/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkenzo-s <gkenzo-s@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 22:03:18 by gkenzo-s          #+#    #+#             */
/*   Updated: 2021/02/23 22:58:00 by gkenzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	add_shade(double distance, int color)
{
	if (distance > 1 || distance < 0)
	{
		printf("wrong distance");
		return (0);
	}
	return (color + 255 * (int)(distance * pow(2, 24)));
}

int	get_opposite(int color)
{
	return (~color);
}

int	make_rainbow(int i, int width)
{
	int	r;
	int	g;
	int	b;

	if (i <= 2 * width / 6)
		r = 255;
	else if (i <= 3 * width / 6)
		r = -255 * 6 * i / width + 255 * 3;
	else if (i <= 4 * width / 6)
		r = 0;
	else
		r = 63 * 6 * i / width - 4 * 63;

	if (i <= 2 * width / 6)
		g = 127 * 6 * i / width;
	else if (i <= 3 * width / 6)
		g = 255;
	else if (i <= 4 * width / 6)
		g = -255 * 6 * i / width + 255 * 4;
	else
		g = 0;

	if (i <= 3 * width / 6)
		b = 0;
	else if (i <= 4 * width / 6)
		b = 255 * 6 * i / width - 255 * 3;
	else if (i <= 5 * width / 6)
		b = -127 * 6 * i / width + 127 * 6;
	else
		b = 63 * 6 * i / width - 63 * 3;
	return (create_trgb(128, r, g, b));
}





void	my_mlx_pixel_put(t_game *game, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x <= game->width && y >= 0 && y <= game->height)
	{
		dst = game->img->addr + (y * game->img->line_len + x * (game->img->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
		//*(unsigned int *)dst = pow(x, 2) + pow(y, 2);
	}
}

void	draw_rectangle(t_game *game, int width, int height, int a, int b, int color, int rainbow)
{
	int x;
	int y;

	x = 0;
	while (x <= game->width)
	{
		y = 0;
		while (y <= game->height)
		{
			if (x < width && y < height)
			{
				my_mlx_pixel_put(game, x + a, y + b, color);
				if (rainbow == 1)
					my_mlx_pixel_put(game, x + a, y + b, make_rainbow(x, width));
			}
			y++;
		}
		x++;
	}
}

void	draw_circle(t_game *game, int radius, int a, int b, int color, int rainbow)
{
	int x;
	int y;

	x = 0;
	while (x <= game->width)
	{
		y = 0;
		while (y <= game->height)
		{
			if (pow(x - a, 2) + pow(y - b, 2) <= pow(radius, 2))
			{
				my_mlx_pixel_put(game, x, y, color);
				if (rainbow == 1)
					my_mlx_pixel_put(game, x, y, make_rainbow(x - (a - radius), 2 * radius));
			}
			y++;
		}
		x++;
	}
}




void	ultimate_free(t_game *game)
{
	free(game->mlx);
	free(game->win);
	free(game->img);
}

int		close_window(t_game *game)
{
	ultimate_free(game);
	exit(0);
}

int		key_pressed(int keycode, t_game *game)
{
	printf("key code: %d\n", keycode);
	if (keycode == ESC)
		close_window(game);
	if (keycode == W_KEY)
		game->player->y -=10;
	if (keycode == A_KEY)
		game->player->x -=10;
	if (keycode == S_KEY)
		game->player->y += 10;
	if (keycode == D_KEY)
		game->player->x += 10;

	if (keycode == 32) //delete this part
		game->index = 100;
}

t_image	*init_image(t_game *game)
{
	t_image	*img;

	if (!(img = (t_image *)ft_calloc(1, sizeof(t_image))))
		return ((void *)0);

	if (!(img->img = mlx_new_image(game->mlx, game->width, game->height)))
		return ((void *)0);

	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_len, &img->endian);

	return (img);
}

t_map	*init_map()
{
	t_map	*map;

	if (!(map = (t_map *)ft_calloc(1, sizeof(t_map))))
		return ((void *)0);

	char	sla[6][5] =
	{
		{'1', '1', '1', '1', '1'},
		{'1', '0', '0', '0', '1'},
		{'1', '0', '0', '0', '1'},
		{'1', '0', '0', '0', '1'},
		{'1', '0', 'N', '0', '1'},
		{'1', '1', '1', '1', '1'}
	};
	map->map = (char **)sla;

	map->rows = 6;//get the input from file
	map->columns = 5;
	//if (!(map->map = (int **)ft_calloc(game->map->rows, sizeof(char *))))
	return (map);
}

t_player	*init_player()
{
	t_player	*player;

	if (!(player = (t_player *)ft_calloc(1, sizeof(t_player))))
		return ((void *)0);
	player->x = 2.0;
	player->y = 4.0;
	player->dirX = 0.0;
	player->dirY = -1.0;
	player->planeX = 0.66;
	player->planeY = 0.0;
	return (player);
}

void	print_wrong_usage(void)
{
	printf("Wrong utilization.\n\nCub3d proper usage:\n");
	printf("./cub3D <\"name\".cub>\n");
	printf("./cub3D <\"name\".cub> <--save>\n");
	exit(-1);
}

t_game	*init_game(void)
{
	t_game	*game;

	game = (t_game *)ft_calloc(1, sizeof(t_game));
	if (!(game->mlx = mlx_init()))
		return (ERROR);

	game->width = 800;
	game->height = 400;
	return (game);
}

void	clear_img(t_game *game)
{
	int x;
	int y;

	x = game->width;
	while (x >= 0)
	{
		y = game->height;
		while (y >= 0)
		{
			my_mlx_pixel_put(game, x, y, 0);
			y--;
		}
		x--;
	}
}

int	draw_idk(t_game *game)
{
	//game->next_img = init_image(game);
	draw_circle(game, game->index, game->player->x, game->player->y, 0x00FF0000, 1);
	game->index--;
	if (game->index == 5)
	{
		clear_img(game);
		game->index = 100;
	}
	//free(game->img);
	//game->img = game->next_img;
	mlx_put_image_to_window(game->mlx, game->win, game->img->img, 0, 0);
}



int		main(int argc, char *argv)
{
	t_game	*game;

	if (argc != 2 && argc != 3)
		print_wrong_usage();
	game = init_game();
	game->map = init_map();
	game->player = init_player();




	//game->next_img = init_image(game);
	game->img = init_image(game);
	game->win = mlx_new_window(game->mlx, game->width ,game->height, "cub3D");
	game->index = 50;
	game->player->x = 400;
	game->player->y = 200;

	draw_rectangle(game, 600, 400, 100, 0, 0x00FF0000, 1);
	draw_circle(game, 100, 400, 200, 0x00FF0000, 1);


	mlx_hook(game->win, 2, 1L << 0, key_pressed, game);
	mlx_hook(game->win, 33, 1L << 17, close_window, game);
	mlx_loop_hook(game->mlx, draw_idk, game);
	mlx_loop(game->mlx);

	return (0);
}
