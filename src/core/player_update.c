/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:46:26 by joeduard          #+#    #+#             */
/*   Updated: 2022/09/30 17:24:14 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	player_update(int keycode, t_data *data)
{
    if (keycode == KEY_W || keycode == KEY_UP)
	{
		data->player.x-=5;						//	só um teste
		//game->x += game->player_delta_x;
		//game->y += game->player_delta_y;
		mlx_clear_window(data->mlx.mlx_ptr, data->mlx.win_ptr);
		handle_situation(data, data->player.x - 1, data->player.y);
		data->player.init_pos = 'u';
	}
	if (keycode == KEY_S || keycode == KEY_DOWN)
	{
		data->player.x+=5;
	//	game->x -= game->player_delta_x;
	//	game->y -= game->player_delta_y;
		mlx_clear_window(data->mlx.mlx_ptr, data->mlx.win_ptr);
		handle_situation(data, data->game.x + 1, data->game.y); 
		data->game.player_down = 'd';
	}
	if (keycode == KEY_D || keycode == KEY_RIGHT)
	{
		data->player.x+=5;
	//	game->player_angle+= 0.1;
		// if(game->player_angle > 2 * PI)
		// 	game->player_angle-= 2 * PI;
		// game->player_delta_x = cos(game->player_angle) * 5;
		// game->player_delta_y = sin(game->player_angle) * 5;
		mlx_clear_window(data->mlx.mlx_ptr, data->mlx.win_ptr);
		// handle_angle(game, game->x, game->y);
	 	data->game.player_right = 'r';
	}
	if (keycode == KEY_A || keycode == KEY_LEFT)
	{
		data->game.x-=5;
		// game->player_angle-= 0.1;
		// if(game->player_angle < 0)
		// 	game->player_angle+= 2 *PI;
		// game->player_delta_x = cos(game->player_angle) * 5;
		// game->player_delta_y = sin(game->player_delta_y) * 5;
		mlx_clear_window(data->mlx.mlx_ptr, data->mlx.win_ptr);
		// handle_angle(game, game->x, game->y);
	 	data->game.player_right = 'l';
	}
}