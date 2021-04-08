/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkenzo-s <gkenzo-s@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 20:12:07 by gkenzo-s          #+#    #+#             */
/*   Updated: 2021/03/11 20:12:09 by gkenzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

//TODO         fazer ou nao checagem intensa de erros?

int	num_words_check(char **words, int n)
{
	int	i;

	i = 0;
	while (words[i])
		i++;
	if (i != n)
		return ERROR;
	return OK;
}

int	get_color(t_game *game, char **words)
{
	int	i;
	int	last;
	int	*rgb;

	if (num_words_check(words, 2) == ERROR)
		return (ERROR);
	rgb = ft_calloc(3, sizeof(int));
	i = -1;
	last = 0;
	while (ft_isdigit(words[1][++i]))
	rgb[0] = ft_atoi(ft_substr(words[1], last, i - last));
	last = i;
	if (words[1][i] != ',')
		return ERROR;
	while (ft_isdigit(words[1][++i]))
	rgb[1] = ft_atoi(ft_substr(words[1], last, i - last));
	last = i;
	if (words[1][i] != ',')
		return ERROR;
	while (ft_isdigit(words[1][++i]))
	rgb[2] = ft_atoi(ft_substr(words[1], last, i - last));
	game->floor_color = create_trgb(1, rgb[0], rgb[1], rgb[2]);
	free(rgb);
	return (OK);
}


int	interpret_line(t_game *game, char **words)
{
	if (words[0] == "R")
	{
		game->width = ft_atoi(words[1]);
		game->height = ft_atoi(words[2]);
	}
	else if (words[0] == "NO")
		game->tex->NO = words[1];
	else if (words[0] == "SO")
		game->tex->SO = words[1];
	else if (words[0] == "WE")
		game->tex->WE = words[1];
	else if (words[0] == "EA")
		game->tex->EA = words[1];
	else if (words[0] == "S")
		game->tex->sprite = words[1];
	else if (words[0] == "F")
		get_color(game, words);
	else if (words[0] == "C")
}

int	get_input(t_game *game)
{
	int		ret;
	int		fd;
	char	*line;
	char	**words;

	ret = 1;
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		interpret_line(game, words);
	}
	return (0);
}
