/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 12:59:33 by joeduard          #+#    #+#             */
/*   Updated: 2022/09/29 23:53:16 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int key_press(int keycode, t_data *data)
{
    if (keycode == XK_Escape)
        exit_game(data);
    if (data->game.end_game)
        return (0);
    player_update(keycode, data);
    mlx_string_put(data->mlx.mlx_ptr, data->mlx.win_ptr, game->x, game->y, 255, "X");
    //mlx_pixel_put(game->mlx, game->win, game->x, game->y, 255);
    map_render(data->map, data);
    
    return(0);
}
