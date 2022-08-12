/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 18:06:00 by joeduard          #+#    #+#             */
/*   Updated: 2022/08/11 22:34:58 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub3d.h"

int	has_valid_walls(char **map, t_map *mp)
{
	int i;
	int j;

	while(map[mp->map_col_size])
		mp->map_col_size++;
	mp->map_col_size--;
	mp->map_row_size = ft_strlen(*map) - 1;
	i = 0;
	while (map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if (map[0][j] != '1' || map[i][0] != '1' ||
					map[i][mp->map_row_size] != '1' ||
					map[mp->map_col_size][j] != '1')
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
			if (map[i][j] !='1' && map[i][j] != '0'
				&& map[i][j] != 'P' && map[i][j] != 'C'
				&& map[i][j] != 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	has_minimum_chars(char **map, t_map *mp)
{
	int i;
	int j;

	i = 0;
	while(map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				mp->player++;
			if (map[i][j] == 'C')
				mp->collectible++;
			if(map[i][j] == '0')
				mp->space++;
			if(mp->collectible && mp->exit && mp->player && mp->space)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int has_valid_extension(char *file)
{
	char *ext;

	if (!file)
		return (0);
	ext = ft_strrchr(file, '.');
	if (ft_strncmp(ext, ".ber", 5))
		return (0);
	return (1);
}