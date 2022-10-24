/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:01:52 by joeduard          #+#    #+#             */
/*   Updated: 2022/10/24 18:03:00 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	initialize_mlx(t_data *data)
{
	data->mlx.mlx_ptr = mlx_init();
	if (data->mlx.mlx_ptr == NULL)
	{
		print_error(E_MLX);
		free(data->mlx.mlx_ptr);
	}
	printf("INICIALIZOU MLX\n"); // tirar este print depois
	init_window(data);
}

static void	initialize_data(t_data *data)
{
	data->player.pos_x = 0;
	data->player.pos_y = 0;
	map_counter(data);	

}

static void	initialize_rendering(t_data *data)
{
		
	printf("Chegou aqui no initialize_rendering\n");
	initialize_image(data);
	//mlx_pixel_put(game->mlx, game->win, game->x, game->y, 110);
	//mlx_string_put(game->mlx, game->win, game->x, game->y, 255, "X");
	//mlx_put_image_to_window(game->mlx, game->win, game->player_down, game->x , game->y);
	//map_render(data->map, data);
	//event_handler(data);
}

void	init_data(t_data *data)
{
	initialize_mlx(data);
	initialize_data(data);
	initialize_rendering(data);
}
