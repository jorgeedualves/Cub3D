/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:35:41 by joeduard          #+#    #+#             */
/*   Updated: 2022/09/22 22:04:27 by joeduard         ###   ########.fr       */
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
    int tileColor;
    int tile_x;
    int tile_y;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            tile_x = j * TILE_SIZE;
            tile_x = i * TILE_SIZE;
            if (map[i][j] == '1')
                tileColor = "#222";
            else
                tileColor = "#fff";
            //  draw_image(game, game->wall, i, j); // trocar para get color
            //mlx_string_put(game->mlx, game->win, game->x, game->y, 250, "1");
          //  if (map[i][j] == '0')
               // draw_image(game, game->empty_space, i, j);
            if (map[i][j] == 'N')
            {
                hook_player(game, i, j);
                mlx_clear_window(game->mlx, game->win);
            }
               
            j++;
        }
        i++;
        
    }
}
