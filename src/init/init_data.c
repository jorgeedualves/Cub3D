/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:01:52 by joeduard          #+#    #+#             */
/*   Updated: 2022/10/25 18:21:29 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	initialize_data(t_data *data)
{
	ft_bzero(&data->mlx, sizeof(t_mlx));
	ft_bzero(&data->img, sizeof(t_img));
	ft_bzero(&data->player, sizeof(t_player));
	ft_bzero(&data->game, sizeof(t_game));
	map_counter(data);	

}

static void	initialize_mlx(t_data *data)
{
	data->mlx.mlx_ptr = mlx_init();
	if (data->mlx.mlx_ptr == NULL)
	{
		print_error(E_MLX);
		exit_game(data);
	}
	init_window(data);
}


static void	initialize_rendering(t_data *data)
{
		
	printf("Chegou aqui no initialize_rendering\n");
	initialize_image(data);
}

void	init_data(t_data *data)
{
	initialize_data(data);
	initialize_mlx(data);
	initialize_rendering(data);
}
