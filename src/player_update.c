/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:46:26 by joeduard          #+#    #+#             */
/*   Updated: 2022/09/02 15:40:15 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	player_update(int keycode, t_game *game)
{
    if (keycode == KEY_W || keycode == KEY_UP)
	{
		game->y-=5;
		mlx_clear_window(game->mlx, game->win);
		// handle_situation(game, game->x - 1, game->y);
		// game->player_direction = 'u';
	}
	if (keycode == KEY_S || keycode == KEY_DOWN)
	{
		game->y+=5;
		mlx_clear_window(game->mlx, game->win);
		// handle_situation(game, game->x + 1, game->y); 
		// game->player_direction = 'd';
	}
	if (keycode == KEY_D || keycode == KEY_RIGHT)
	{
		game->x+=5;
		mlx_clear_window(game->mlx, game->win);
	// 	handle_angle(game, game->x, game->y);
	// 	game->player_direction = 'r';
	}
	if (keycode == KEY_A || keycode == KEY_LEFT)
	{
		game->x-=5;
		mlx_clear_window(game->mlx, game->win);
	// 	handle_angle(game, game->x, game->y);
	// 	game->player_direction = 'l';
	}
}