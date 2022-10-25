/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:01:49 by joeduard          #+#    #+#             */
/*   Updated: 2022/10/25 12:21:05 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		ft_super_free((void *)&map[i]);
		i++;
	}
	ft_super_free((void *)&map);
}

static void	free_game(t_data *data)
{
	// mlx_destroy_image(game->mlx, game->empty_space);
	// mlx_destroy_image(game->mlx, game->wall);
	// mlx_destroy_image(game->mlx, game->player_right);
	// mlx_destroy_image(game->mlx, game->player_left);
	// mlx_destroy_image(game->mlx, game->player_up);
	// mlx_destroy_image(game->mlx, game->player_down);
	mlx_destroy_window(data->mlx.mlx_ptr, data->mlx.win_ptr);
	mlx_destroy_image(data->mlx.mlx_ptr,data->img.mlx_img);
	mlx_destroy_display(data->mlx.mlx_ptr);
	ft_super_free(&data->mlx.mlx_ptr);
}

int exit_game(t_data *data)
{
	free_map(data->map.file);
	free_game(data);
	exit(0);
	return (0);
}