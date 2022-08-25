/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:34:47 by joeduard          #+#    #+#             */
/*   Updated: 2022/08/25 17:06:59 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_window(t_game *game)
{
	game->win = mlx_new_window (game->mlx, WINDOW_SIZE, WINDOW_HEIGHT, "CUB3D");
}
