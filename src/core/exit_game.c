/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:01:49 by joeduard          #+#    #+#             */
/*   Updated: 2022/10/24 13:15:14 by joeduard         ###   ########.fr       */
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

//static void	free_game(t_game *game)
//{
	// mlx_destroy_image(game->mlx, game->empty_space);
	// mlx_destroy_image(game->mlx, game->wall);
	// mlx_destroy_image(game->mlx, game->player_right);
	// mlx_destroy_image(game->mlx, game->player_left);
	// mlx_destroy_image(game->mlx, game->player_up);
	// mlx_destroy_image(game->mlx, game->player_down);
	// mlx_destroy_window(game->mlx, game->win);
	// mlx_destroy_display(game->mlx);
	// ft_super_free(&game->mlx);
//}

int exit_game(t_data *data)
{
	free_map(data->game.map);
//	free_game(game);
	exit(0);
	return (0);
}