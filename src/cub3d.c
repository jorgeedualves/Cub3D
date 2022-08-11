/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:05:26 by joeduard          #+#    #+#             */
/*   Updated: 2022/08/11 16:52:30 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;


	if(argc == 2)
	{
		game.map = read_map(argv[1]);
		if (is_valid_map(game.map, argv[1]));
		{
			printf("MAP is valid");
			//init_game
			//event_handler
			//mlx_loop
		}
		else
		{
			printf("Error\n This map is not valid!");
			//free_map(game.map)
			exit(0);
		}
	}
	else
	{
		printf("No map especified!");
		exit(0);
	}
}
