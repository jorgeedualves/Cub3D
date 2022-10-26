/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:35:41 by joeduard          #+#    #+#             */
/*   Updated: 2022/10/25 18:24:56 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

//Draw the line by DDA algorithm
void	draw_line(t_data *data, double x1, double y1, double x2, double y2)
{
	double	deltaX;
	double	deltaY;
	double	step;

	deltaX = x2 - x1;
	deltaY = y2 - y1;
	step = (fabs(deltaX) > fabs(deltaY)) ? fabs(deltaX) : fabs(deltaY);
	deltaX /= step;
	deltaY /= step;
	while (fabs(x2 - x1) > 0.01 || fabs(y2 - y1) > 0.01)
	{
		data->img.data[((int)floor(y1) * data->map.col * TILE_SIZE + (int)floor(x1))] = PURPLE;
		x1 += deltaX;
		y1 += deltaY;
	}
}

void 	draw_lines(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (i < data->map.col)
	{
		draw_line(data, i * TILE_SIZE, 0, i * TILE_SIZE, data->map.row * TILE_SIZE);
		i++;
	}
	draw_line(data, data->map.col * TILE_SIZE - 1, 0, data->map.col * TILE_SIZE - 1, data->map.row * TILE_SIZE);
	j = 0;
	while (j < data->map.row)
	{
		draw_line(data, 0, j * TILE_SIZE, data->map.col * TILE_SIZE, j * TILE_SIZE);
		j++;
	}
	draw_line(data, 0, data->map.row * TILE_SIZE - 1, data->map.col * TILE_SIZE, data->map.row * TILE_SIZE - 1);
}

void	draw_rectangle(t_data *data, int x, int y, int color)
{
	int i;
	int j;

	x *= TILE_SIZE;
	y *= TILE_SIZE;
	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			data->img.data[(y + i) * data->map.col * TILE_SIZE + x + j] = color;
			j++;
		}
		i++;
	}
}

void	draw_rectangles(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (i < data->map.row)
	{
		j = 0;
		while (j < data->map.col)
		{
			if (data->map.file[i][j] == '1')
				draw_rectangle(data, j, i, PURPLE);
			if (data->map.file[i][j] == '0')
				draw_rectangle(data, j, i, BLUE);
			if (data->map.file[i][j] == 'N')
				draw_rectangle(data, j, i, YELLOW);
			j++;
		}
		i++;
	}
}

int		map_render(t_data *data)
{
	draw_rectangles(data);
	draw_lines(data);
	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr, data->img.data, 0, 0);
	if(&mlx_put_image_to_window == NULL)
	{
		print_error(E_MLXIMG);
		exit_game(data);
	}
	return (0);
}