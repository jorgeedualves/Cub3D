/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:06:54 by joeduard          #+#    #+#             */
/*   Updated: 2022/10/24 18:18:12 by joeduard         ###   ########.fr       */
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
# include <X11/keysym.h>
# include <X11/X.h>

# include "../libraries/mlx_linux/mlx.h"
# include "../libraries/libft/libft.h"

# include "defines.h"
# include "erros.h"
# include "structs.h"

//core
    // exit_game.c
    void	free_map(char **map);
    int	    exit_game(t_data *data);

    //move_player.c
    void	handle_situation(t_data *data, int x, int y);

    //player_update.c
 //   void	player_update(int keycode, t_data *data);

//draw
    //map_render.c
    void	draw_line(t_data *data, double x1, double y1, double x2, double y2);
    void 	draw_lines(t_data *data);
    void	draw_rectangle(t_data *data, int x, int y, int color);
    void	draw_rectangles(t_data *data);
    int     map_render(t_data *data);

    //map_utils.c
    void	map_counter(t_data *data);
    void	print_map(char **map);

//init
    //init_data.c
    void	init_data(t_data *data);

    //init_image.c
    void	initialize_image(t_data *data);

    //init_window.c
    void	init_window(t_data *data);

//keys
    // event_handler.c
    void	event_handler(t_data *data);

    //game_utils.c
    int click_close(t_data *data);
    void	player_update(int keycode, t_data *data);
    int key_press(int keycode, t_data *data);

    //  hook_player.c
    //void    hook_player(t_game *game, int i, int j);

//validation
    //map_check.c
    int	has_valid_walls(char **map, t_map *mp);
    int	has_valid_chars(char **map);
    int	has_minimum_chars(char **map, t_map *mp);
    int	has_valid_extension(char *file);
    
    //read_map.c
    char	**read_map(char *path_to_file);

    //valid_map.c
    void	map_check_init(t_map *map);
    int	is_valid_map(char **map, char *file);

    //validation.c
    t_bool	print_error(char *error);
    t_bool	validation(t_data *data, int argc, char **argv);

#endif