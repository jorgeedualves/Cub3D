/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:53:53 by joeduard          #+#    #+#             */
/*   Updated: 2022/09/28 15:04:16 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	**read_map(char *path_to_file)
{
	int		fd;
	char	*line;
	char	*tmp;
	char	*buffer;
	char	**map;

	fd = open(path_to_file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	buffer = ft_strdup ("");
	while (1)
	{
		line = ft_get_next_line(fd);
		if (!line)
			break ;
		tmp = buffer;
		buffer = ft_strjoin(tmp, line);
		ft_super_free ((void *)&tmp);
		ft_super_free ((void *)&line);
	}
	map = ft_split (buffer, '\n');
	ft_super_free ((void *)&buffer);
	close (fd);
	return (map);
}
