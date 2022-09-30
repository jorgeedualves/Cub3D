/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:37:50 by joeduard          #+#    #+#             */
/*   Updated: 2022/09/29 23:34:03 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
}				t_mlx;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}	t_img;

/*typedef struct s_params
{
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	int		ceilcolor;
	int		floorcolor;
}	t_params;
*/

typedef struct s_menu
{
	int		game;
	int		main;
	int		options;
	int		opt_moves;
	int		opt_rots;
	int		opt_mouses;
	//t_bool	sound;
}	t_menu;
typedef struct s_game
{
	t_mlx	mlx;
	t_menu	menu;
	t_img	img;
	void	*win;
	void	*wall;
	void	*empty_space;
	void	*player_right;
	void	*player_left;
	void	*player_up;
	void	*player_down;
	char	**map;
	int		img_width;
	int		img_height;
	int		win_width;
	int		win_height;
	int		x;
	int		y;
	int 	moves;
	int 	end_game;
	char	string;
}		t_game;

typedef struct s_player
{
	float	x;
	float	y;
	float	width;
	float	height;
	int		turn_dir;
	int		walk_dir;
	int		side_dir;
	int		look_dir;
	int		init_pos;
	float	view_angle;
	float	rot_angle;
	float	walk_speed;
	float	turn_speed;
	int		turn_speed_var;
	float	look_speed;
}	t_player;
typedef struct s_map
{
	int	collectible;
	int	map_row_size;
	int	map_col_size;
	int	player;
	int	space;

}	t_map;

typedef struct s_data
{
	int			state;
//	t_bool		game_running;
	char		**map;
	char		**devmap;
	t_mlx		mlx;
	t_menu		menu;
//	t_params	params;
	t_player	player;
	t_game		game;
}	t_data;

typedef enum e_bool
{
	false,
	true
}	t_bool;

#endif