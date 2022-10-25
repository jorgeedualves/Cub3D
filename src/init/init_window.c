/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:34:47 by joeduard          #+#    #+#             */
/*   Updated: 2022/10/25 12:14:32 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_window(t_data *data)
{	
	data->mlx.win_ptr = mlx_new_window (data->mlx.mlx_ptr, WIN_WIDTH , WIN_HEIGHT , "CUB3D");
	if (data->mlx.win_ptr == NULL)
	{
		print_error(E_MLXWIN);
		exit_game(data);
	}
}
