/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 12:59:33 by joeduard          #+#    #+#             */
/*   Updated: 2022/10/24 18:05:39 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int click_close(t_data *data)
{
    exit_game(data);
    return (0);
}

void    swap_positions(char *curr_p, char *next_p, char curr_value, char next_value)
{
    *curr_p = next_value;
    *next_p = curr_value;
}

void    handle_0(t_data *data, int x, int y)
{
    int i;
    int j;

    i = data->player.pos_x;
    j = data->player.pos_y;
    swap_positions(&data->map.file[i][j], &data->map.file[x][y], 'N', '0');
    data->player.pos_x = x;
    data->player.pos_y = y;
}

void    handle_situation(t_data *data, int x, int y)
{
    printf("handle situation x: %d, y: %d\n", x, y);
    if (data->map.file[x][y] != '1')
    {
        if (data->map.file[x][y] == '0')
            handle_0(data, x, y);
    }
}

void	player_update(int keycode, t_data *data)
{
	if (keycode == KEY_W || keycode == KEY_UP)
        handle_situation(data, data->player.pos_x - 1, data->player.pos_y);
	if (keycode == KEY_S || keycode == KEY_DOWN)
    	handle_situation(data, data->player.pos_x + 1, data->player.pos_y);
	if (keycode == KEY_A || keycode == KEY_LEFT)
		handle_situation(data, data->player.pos_x, data->player.pos_y - 1);
	if (keycode == KEY_D || keycode == KEY_RIGHT)
    	handle_situation(data, data->player.pos_x, data->player.pos_y + 1);
}


int	key_press(int keycode, t_data *data)
{
    if (keycode == KEY_UP || keycode == KEY_DOWN || keycode == KEY_LEFT || keycode == KEY_RIGHT)
	    player_update(keycode, data);
	if (keycode == XK_Escape)
        exit_game(data);
	if (data->game.end_game)
		return (0);
//	mlx_loop_hook(game->mlx, &render_map, &game); MOSTRAR PARA O ALEXANDRE.
	return (0);
}
