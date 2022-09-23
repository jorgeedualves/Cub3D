/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:27:17 by joeduard          #+#    #+#             */
/*   Updated: 2022/09/22 15:22:24 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	map_counter(char **map, t_game *game)
{
	int	i;

	i = 0;
	game->win_height = 0;
	while (map[i])
	{
		game->win_height++;
		i++;
	}
	game->win_width = ft_strlen(*map);
	printf("Largura: %d\nAltura: %d \n", game->win_width, game->win_height);
}

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
	printf("\n");
}
