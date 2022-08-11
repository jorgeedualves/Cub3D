/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:06:54 by joeduard          #+#    #+#             */
/*   Updated: 2022/08/11 17:38:33 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CUB3D_H
#define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../libraries/mlx_linux/mlx.h"
# include "../libraries/libft/libft.h"


typedef struct s_game
{
	char	**map;

}		t_game;

typedef struct s_map
{
	int	collectible;
	int	exit;
	int	map_row_size;
	int	map_col_size;
	int	player;
	int	space;

}	t_map;


char **read_map(char *path_to_file);
int	is_valid_map(char **map, char *file);


#endif