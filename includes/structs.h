# ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win;
}				t_mlx;

typedef struct s_game
{
	void	*mlx;
	void	*img;
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
	int 	player_direction;
	float	player_delta_x;
	float	player_delta_y;
	float	player_angle;
	int 	end_game;
	char	string;
}		t_game;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bits_per_pixel; /* bits per pixel */
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_map
{
	int	collectible;
	int	map_row_size;
	int	map_col_size;
	int	player;
	int	space;

}	t_map;





#endif