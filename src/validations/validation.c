/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:26:37 by joeduard          #+#    #+#             */
/*   Updated: 2022/10/25 23:14:49 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_bool	print_error(char *error)
{
	ft_putstr_fd(error, 2);
	return (false);
}

t_bool	validation(t_data *data, int argc, char **argv)
{
	if (WIN_WIDTH < 1024 || WIN_HEIGHT < 768)
		return (print_error(E_RESINVAL));
	if (argc < 2)
		return (print_error(E_NOMAP));
	if (argc > 2)
		return (print_error(E_MANYARG));
	ft_bzero(&data->map, sizeof(t_map));
	data->map.file = read_map(argv[1]);
	//	print_map(data->map.file);
	if (!is_valid_map(data->map.file, argv[1]))
	{
		exit_game(data);
		return (print_error(E_MAPINVAL));
	}
	return(true);
}