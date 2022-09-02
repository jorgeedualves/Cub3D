/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 22:10:14 by joeduard          #+#    #+#             */
/*   Updated: 2022/09/01 16:51:03 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	swap_positions(char *current_pos, char *next_pos,
							char current_value, char next_value)
{
	*current_pos = next_value;
	*next_pos = current_value;
}

static void	handle_0(t_game *game, int x, int y)	// lidar com zero
{
	int	i;			
	int	j;

	i = game->x;
	j = game->y;
	swap_positions(&game->map[i][j], &game->map[x][y], 'N', '0');
	game->moves++;
	game->x = x;
	game->y = y;
}

void	handle_situation(t_game *game, int x, int y)
{
    if (game->map[x][y] != '1')			// Se a posicao do map for diferente de '1' (wall)
	    {
		    if (game->map[x][y] == '0')		// Se a posicao do map for igual a '0' (space)
		    	handle_0(game, x, y);	
        }
}


// void	handle_angle(t_game *game, int x, int y)
// {

// }
