/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:05:26 by joeduard          #+#    #+#             */
/*   Updated: 2022/10/25 11:53:20 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if(validation(&data, argc, argv) == false)
		return(EXIT_FAILURE);
	init_data(&data);
	mlx_loop_hook(data.mlx.mlx_ptr, &map_render, &data);
	event_handler(&data);
	mlx_loop(data.mlx.mlx_ptr);
	return (0);
}
