/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkenzo-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 13:21:22 by gkenzo-s          #+#    #+#             */
/*   Updated: 2020/03/04 16:27:00 by gkenzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	words_number(char const *str, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i] && str[i] == c)
		i++;
	if (str[i])
	{
		i++;
		count++;
	}
	while (str[i] != 0)
	{
		if (str[i] != c && str[i - 1] == c)
		{
			count++;
			while (str[i] == c)
				i++;
		}
		i++;
	}
	return (count);
}

static int	word_size(char const *str, char c)
{
	int i;
	int size;

	i = 0;
	size = 0;
	while (str[i] && str[i] != c)
	{
		i++;
		size++;
	}
	return (size);
}

static int	put_and_null_next(char **arr, int i, int j, char c)
{
	arr[i][j] = c;
	arr[i][j + 1] = 0;
	return (j + 1);
}

char		**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		j;
	int		index;

	if (!s)
		return (0);
	if (!(arr = (char**)malloc(sizeof(char*) * (words_number(s, c) + 1))))
		return (0);
	i = -1;
	index = -1;
	while (s[++index])
		if (s[index] != c)
		{
			if (i == -1 || s[index - 1] == c)
			{
				if (!(arr[++i] = (char*)malloc(sizeof(char) *
								(word_size(s + index, c) + 1))))
					return (0);
				j = 0;
			}
			j = put_and_null_next(arr, i, j, s[index]);
		}
	arr[++i] = 0;
	return (arr);
}
