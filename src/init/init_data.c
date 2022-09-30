/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:01:52 by joeduard          #+#    #+#             */
/*   Updated: 2022/09/30 16:26:42 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	initialize_mlx(t_data *data)
{
	data->mlx.mlx_ptr = mlx_init();
	if (data->mlx.mlx_ptr == NULL)
	{
		print_error(E_MLX);
		exit(EXIT_FAILURE);
	}
	printf("INICIALIZOU MLX\n"); // tirar este print depois
	init_window(&data);
}

static void	initialize_data(t_data *data)
{
	map_counter(data->map, *data);	

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
