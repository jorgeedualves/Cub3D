/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:27:17 by joeduard          #+#    #+#             */
/*   Updated: 2022/10/24 18:02:40 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	map_counter(t_data *data)
{
	int	i;

	i = 0;
	
	data->map.row = 0;
	data->map.col = 0;
	while (data->map.file[i])
	{
		data->map.row++;
		i++;
	}
	data->map.col = ft_strlen(*data->map.file);
	printf("Largura: %d\nAltura: %d \n", data->map.row, data->map.col);
	i = 0;
	int j;
	while (i < data->map.row)
	{
		j = 0;
		while (j < data->map.col)
		{
			if (data->map.file[i][j] == 'N')
			{
				data->player.pos_x = i;
				data->player.pos_y = j;
			}
			j++;
		}
		i++;
	}
}

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
	printf("\n");
}
