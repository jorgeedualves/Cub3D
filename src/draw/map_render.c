/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:35:41 by joeduard          #+#    #+#             */
/*   Updated: 2022/09/28 15:05:44 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

 static void	my_mlx_pixel_put(t_img img, int x, int y, int color)
{
    char	*dst;

	dst = img.addr + (y * img.line_len + x * (img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;

}

void draw_image(t_game *game, int x, int y, int tileColor)
{
     t_img   img;
    int offset;

    img.mlx_img = mlx_new_image(game->mlx, game->win_width, game->win_height);
    img.addr = mlx_get_data_addr(game->img, &img.bits_per_pixel, &img.line_len, &img.endian);
    offset = (y * img.line_len + x * (img.bits_per_pixel));
    my_mlx_pixel_put(img, x, y, tileColor);
}

void map_render(char **map, t_game *game)
{

    int i;
    int j;
    int tileColor;
    int tile_x;
  //  int tile_y;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            tile_x = j * TILE_SIZE;
            tile_x = i * TILE_SIZE;
            if (map[i][j] == '1')
                tileColor = 0x00FF0000;
            else
                tileColor = 0x009999CC;
            // CHAMAR AS 3 FUNÇÕES 
            draw_image(game, i, j, tileColor);
            //  draw_image(game, game->wall, i, j); // trocar para get color
            //mlx_string_put(game->mlx, game->win, game->x, game->y, 250, "1");
          //  if (map[i][j] == '0')
               // draw_image(game, game->empty_space, i, j);
            // if (map[i][j] == 'N')
            // {
            //     hook_player(game, i, j);
            //     mlx_clear_window(game->mlx, game->win);
            // }
               
            j++;
        }
        i++;
        
    }
}
