/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 12:59:33 by joeduard          #+#    #+#             */
/*   Updated: 2022/08/30 15:43:34 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int key_press(int keycode, t_game *game)
{
    if (keycode == XK_Escape)
        exit_game(game);
    if (game->end_game)
        return (0);
    player_update(keycode, game);
    map_render(game->map, game);
    return(0);
}
