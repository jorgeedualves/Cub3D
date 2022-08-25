/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:01:52 by joeduard          #+#    #+#             */
/*   Updated: 2022/08/25 17:32:18 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	initialize_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
	{
		printf("MLX_INIT FAILURE\n");
		exit(EXIT_FAILURE);
	}
	printf("INICIALIZOU MLX\n");
}

static void	initialize_data(t_game *game)
{
	map_counter(game->map, game);
	game->moves = 0;
	game->end_game = 0;
	game->player_direction = 'r';
}

static void	initialize_rendering( t_game *game)
{
	init_window(game);
	printf("Chegou aqui no initialize_rendering\n");
	initialize_image(game);
}

void	init_game(t_game *game)
{
	initialize_mlx(game);
	initialize_data(game);
	initialize_rendering(game);
}
