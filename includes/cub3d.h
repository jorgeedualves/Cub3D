/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:06:54 by joeduard          #+#    #+#             */
/*   Updated: 2022/09/30 19:00:38 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CUB3D_H
#define CUB3D_H

# define XK_MISCELLANY

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <X11/keysymdef.h>
# include <X11/X.h>

# include "../libraries/mlx_linux/mlx.h"
# include "../libraries/libft/libft.h"

# include "defines.h"
# include "erros.h"
# include "structs.h"

//init
// event_handler.c
void	event_handler(t_data *data);
void    draw_image(t_data *data, int x, int y, int tileColor);

//map_utils.c
void	map_counter(char **map, t_data data);
void	print_map(char **map);

//keys
// exit_game.c
void	free_map(char **map);
int	exit_game(t_game *game);

//game_utils
int key_press(int keycode, t_data *data);

//init_data.c
void	init_data(t_data *data);

//init_image.c
void	initialize_image(t_data *data);

//init_window.c
void	init_window(t_data *data);

//map_check.c
int	has_valid_walls(char **map, t_map *mp);
int	has_valid_chars(char **map);
int	has_minimum_chars(char **map, t_map *mp);
int has_valid_extension(char *file);

//map_render.c
void map_render(char **map, t_data *data);
//void draw_image(t_game *game, void *img, int x, int y);




//move_player.c
void	handle_situation(t_data *data, int x, int y);

//player_update.c
void	player_update(int keycode, t_data *data);

//read_map.c
char **read_map(char *path_to_file);

//valid_map.c
int	is_valid_map(char **map, char *file);

//validation.c
t_bool	validation(t_data *data, int argc, char **argv);

//hook_player.c
void	hook_player(t_game *game, int i, int j);

#endif