/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 22:10:14 by joeduard          #+#    #+#             */
/*   Updated: 2022/10/24 19:27:14 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../includes/cub3d.h"

// static void	swap_positions(char *current_pos, char *next_pos,
// 							char current_value, char next_value)
// {
// 	*current_pos = next_value;
// 	*next_pos = current_value;
// }

// static void	handle_0(t_data *data, int x, int y)	// lidar com zero
// {
// 	int	i;			
// 	int	j;

// 	i = data->game.x;
// 	j = data->game.y;
// 	swap_positions(&data->map.file[i][j], &data->map.file[x][y], 'N', '0');
// 	data->game.moves++;
// 	data->game.x = x;
// 	data->game.y = y;
// }

// void	handle_situation(t_data *data, int x, int y)
// {
//     if (data->map.file[x][y] != '1')			// Se a posicao do map for diferente de '1' (wall)
// 	    {
// 		    if (data->map.file[x][y] == '0')		// Se a posicao do map for igual a '0' (space)
// 		    	handle_0(data, x, y);	
//         }
// }


// void	handle_angle(t_game *game, int x, int y)
// {

// }
