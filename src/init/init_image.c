/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:43:06 by joeduard          #+#    #+#             */
/*   Updated: 2022/09/30 16:38:25 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/* static void	*convert_image(char *img, t_data *data)
{
	// game->img = mlx_xpm_file_to_image
	// 	(game->mlx, img, &game->img_width, &game->img_height);
	// return (game->img);
}
*/
void	initialize_image(t_data *data)
{
	data->img.mlx_img = mlx_new_image(data->mlx.mlx_ptr,
			data->map_attributes.map_col_size * TILE_SIZE,
				data->map_attributes.map_row_size * TILE_SIZE);
	if (data->img.mlx_img == NULL)
		print_erro(E_MLXIMG);
	data->img.addr = (int *)mlx_get_data_addr(data->img.mlx_img,
			&data->img.bits_per_pixel,
				&data->img.line_len, &data->img.endian);
	if(data->img.addr == NULL)		// Verificar de retorna null ou zero
		print_erro(E_MLX_ADDR);
	printf("Chegou em initialize_image\n");
}
