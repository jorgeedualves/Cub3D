/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:46:26 by joeduard          #+#    #+#             */
/*   Updated: 2022/09/29 23:53:14 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	player_update(int keycode, t_data *data)
{
    if (keycode == KEY_W || keycode == KEY_UP)
	{
		game->y-=5;
		//game->x += game->player_delta_x;
		//game->y += game->player_delta_y;
		mlx_clear_window(game->mlx, game->win);
		handle_situation(game, game->x - 1, game->y);
		game.player_direction = 'u';
	}
	if (keycode == KEY_S || keycode == KEY_DOWN)
	{
		game->y+=5;
	//	game->x -= game->player_delta_x;
	//	game->y -= game->player_delta_y;
		mlx_clear_window(game->mlx, game->win);
		handle_situation(game, game->x + 1, game->y); 
		game->player_direction = 'd';
	}
	if (keycode == KEY_D || keycode == KEY_RIGHT)
	{
		game->x+=5;
	//	game->player_angle+= 0.1;
		// if(game->player_angle > 2 * PI)
		// 	game->player_angle-= 2 * PI;
		// game->player_delta_x = cos(game->player_angle) * 5;
		// game->player_delta_y = sin(game->player_angle) * 5;
		mlx_clear_window(game->mlx, game->win);
		// handle_angle(game, game->x, game->y);
	 	game->player_direction = 'r';
	}
	if (keycode == KEY_A || keycode == KEY_LEFT)
	{
		game->x-=5;
		// game->player_angle-= 0.1;
		// if(game->player_angle < 0)
		// 	game->player_angle+= 2 *PI;
		// game->player_delta_x = cos(game->player_angle) * 5;
		// game->player_delta_y = sin(game->player_delta_y) * 5;
		mlx_clear_window(game->mlx, game->win);
		// handle_angle(game, game->x, game->y);
	 	game->player_direction = 'l';
	}
}