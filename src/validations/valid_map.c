/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 17:33:53 by joeduard          #+#    #+#             */
/*   Updated: 2022/10/24 17:18:11 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	map_check_init(t_map *map)
{
	map->collectible = 0;
	map->row = 0;
	map->col = 0;
	map->player = 0;
}

int	is_valid_map(char **map, char *file)
{
	t_map	mp;

	if (!map)
		return (0);
	map_check_init (&mp);
	if (has_valid_walls (map, &mp) && has_valid_chars (map)
		&&has_minimum_chars (map, &mp) && has_valid_extension (file))
		return (1);
	return (0);
}
