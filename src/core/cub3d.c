/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:05:26 by joeduard          #+#    #+#             */
/*   Updated: 2022/10/04 12:07:00 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if(validation(&data, argc, argv) == false)
		return(EXIT_FAILURE);
	init_data(&data);
	event_handler(&data);
	mlx_loop(&data.mlx);
	return (0);
}
