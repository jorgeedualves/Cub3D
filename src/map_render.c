/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:35:41 by joeduard          #+#    #+#             */
/*   Updated: 2022/08/30 14:58:22 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void draw_image(t_game *game, void *img, int x, int y)
{
    mlx_put_image_to_window (game->mlx, game->win, img, y * SPRITE_SIZE, x * SPRITE_SIZE);
}

void map_render(char **map, t_game *game)
{

    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == '1')
                draw_image(game, game->wall, i, j);
            if (map[i][j] == '0')
                draw_image(game, game->empty_space, i, j);
            if (map[i][j] == 'N')
                hook_player(game, i, j);
            j++;
        }
        i++;
    }
}
