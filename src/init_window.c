/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:34:47 by joeduard          #+#    #+#             */
/*   Updated: 2022/08/24 16:52:17 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub3d.h"

void	init_window(t_game *game)
{
    game->win = mlx_new_window (game->mlx, game->win_width * SPRITE_SIZE,
        game->win_height * SPRITE_SIZE, "CUB3D");
}
