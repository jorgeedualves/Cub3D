/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:06:54 by joeduard          #+#    #+#             */
/*   Updated: 2022/08/15 17:03:16 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CUB3D_H
#define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include "../libraries/mlx_linux/mlx.h"
# include "../libraries/libft/libft.h"
typedef struct s_game
{
	char	**map;

}		t_game;

typedef struct s_map
{
	int	collectible;
	int	map_row_size;
	int	map_col_size;
	int	player;
	int	space;

}	t_map;

//read_map.c
char **read_map(char *path_to_file);

//valid_map.c
int	is_valid_map(char **map, char *file);

//map_check.c
int	has_valid_walls(char **map, t_map *mp);
int	has_valid_chars(char **map);
int	has_minimum_chars(char **map, t_map *mp);
int has_valid_extension(char *file); 

//get_next_line
char	*get_next_line(int fd);

// exit_game.c
void	free_map(char **map);

#endif