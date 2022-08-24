/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:43:06 by joeduard          #+#    #+#             */
/*   Updated: 2022/08/24 17:04:06 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub3d.h"

static void	*convert_image(char *img, t_game *game)
{
	game->img = mlx_xpm_file_to_image
		(game->mlx, img, &game->img_width, &game->img_height);
	return (game->img);
}

void	initialize_image(t_game *game)
{
	game->wall = convert_image(FILE_WALL, game);
	game->empty_space = convert_image(FILE_SPACE, game);
	game->player_up = convert_image(FILE_PLAYER_U, game);
	game->player_down = convert_image(FILE_PLAYER_D, game);
	game->player_left = convert_image(FILE_PLAYER_L, game);
	game->player_right = convert_image(FILE_PLAYER_R, game);
	printf("Chegou em initialize_image\n");
}