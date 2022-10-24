/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 18:06:00 by joeduard          #+#    #+#             */
/*   Updated: 2022/10/24 17:18:11 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	has_valid_walls(char **map, t_map *mp)
{
	int	i;
	int	j;

	while (map[mp->col])
		mp->col++;
	mp->col--;
	mp->row = ft_strlen(*map) - 1;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[0][j] != '1' || map[i][0] != '1' ||
					map[i][mp->row] != '1' ||
					map[mp->col][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	has_valid_chars(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'N')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	has_minimum_chars(char **map, t_map *mp)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N')
				mp->player++;
			if (map[i][j] == '0')
				mp->space++;
			if (mp->player && mp->space)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	has_valid_extension(char *file)
{
	char	*ext;

	if (!file)
		return (0);
	ext = ft_strrchr(file, '.');
	if (ft_strncmp(ext, ".cub", 5))
		return (0);
	return (1);
}
