/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:06:54 by joeduard          #+#    #+#             */
/*   Updated: 2022/09/28 13:58:19 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CUB3D_H
#define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include "../libraries/mlx_linux/mlx.h"
# include "../libraries/libft/libft.h"
# define XK_MISCELLANY
# include <X11/keysymdef.h>
# include <X11/X.h>

# include "structs.h"

# define WINDOW_RIGHT	1024
# define WINDOW_HEIGHT	510

# define FILE_WALL	"textures/1.xpm"
# define FILE_SPACE	"textures/0.xpm"
# define FILE_PLAYER_U	"textures/P_U.xpm"
# define FILE_PLAYER_D	"textures/P_D.xpm"
# define FILE_PLAYER_L	"textures/P_L.xpm"
# define FILE_PLAYER_R	"textures/P_R.xpm"

# define TILE_SIZE	32
# define SPRITE_SIZE	32
# define PI 3.1415926535

# define X_EVENT_KEY_PRESS	2
# define X_EVENT_DESTROY_NOTIFY	17
# define KEY_W	119
# define KEY_A	97
# define KEY_S	115
# define KEY_D	100

# define KEY_UP		65362
# define KEY_LEFT	65361
# define KEY_DOWN	65364
# define KEY_RIGHT	65363



// event_handler.c
void	event_handler(t_game *game);

// exit_game.c
void	free_map(char **map);
int	exit_game(t_game *game);

//game_utils
int key_press(int keycode, t_game *game);

//init_game.c
void	init_game(t_game *game);

//init_image.c
void	initialize_image(t_game *game);

//init_window.c
void    init_window(t_game *game);

//map_check.c
int	has_valid_walls(char **map, t_map *mp);
int	has_valid_chars(char **map);
int	has_minimum_chars(char **map, t_map *mp);
int has_valid_extension(char *file);

//map_render.c
void map_render(char **map, t_game *game);
//void draw_image(t_game *game, void *img, int x, int y);
void draw_image(t_game *game, int x, int y, int tileColor);

//map_utils.c
void	map_counter(char **map, t_game *game);
void	print_map(char **map);

//move_player.c
void	handle_situation(t_game *game, int x, int y);

//player_update.c
void	player_update(int keycode, t_game *game);

//read_map.c
char **read_map(char *path_to_file);

//valid_map.c
int	is_valid_map(char **map, char *file);

//hook_player.c
void	hook_player(t_game *game, int i, int j);

#endif