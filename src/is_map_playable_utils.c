/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_playable_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 03:02:25 by azamario          #+#    #+#             */
/*   Updated: 2022/11/28 05:33:00 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

typedef struct s_validation
{
	size_t	total_lines;
	size_t	line;
	size_t	counter;
	size_t	column_limit[2];
}	t_validation;

static int	is_garbage(char **map, t_validation v);
static int	just_walls_and_spaces(char *map_line);
static void	shift_back_matrix(char **ptr);

void	resize_line(t_game *g)
{
	int		line;
	int		counter;

	line = 0;
	counter = 0;
	while (just_walls_and_spaces(g->map.map[line]))
		line++;
	while (counter < line - 1)
	{
		shift_back_matrix(g->map.map);
		counter++;
	}
	line = count_vectors((void **)g->map.map) - 1;
	counter = line;
	while (just_walls_and_spaces(g->map.map[line]))
		line--;
	while (counter > line + 1)
		shift_back_matrix(g->map.map + counter--);
}

void	resize_column(t_game *g)
{
	t_validation	v;
	char			*temp;

	v.line = -1;
	v.total_lines = count_vectors((void **)g->map.map) - 1;
	while (g->map.map[++v.line])
	{
		v.counter = ft_strlen(g->map.map[v.line]) - 1;
		if (v.line)
			v.column_limit[TOP_LINE] = ft_strlen(g->map.map[v.line - 1]) - 1;
		if (v.line < v.total_lines)
			v.column_limit[BOT_LINE] = ft_strlen(g->map.map[v.line + 1]) - 1;
		while (is_garbage(g->map.map, v))
			v.counter--;
		if (v.counter == ft_strlen(g->map.map[v.line]) - 1)
			continue ;
		temp = ft_substr(g->map.map[v.line], 0, v.counter + 1);
		ft_super_free((void *)&g->map.map[v.line]);
		g->map.map[v.line] = temp;
	}
}

static int	is_garbage(char **map, t_validation v)
{
	if (map[v.line][v.counter] == '0' || \
		(!v.counter || ft_strchr("0NEWS", map[v.line][v.counter - 1])))
		return (0);
	if (v.line)
		if (v.counter <= v.column_limit[TOP_LINE])
			if (ft_strchr("0NEWS", map[v.line - 1][v.counter]) || \
				ft_strchr("0NEWS", map[v.line - 1][v.counter - 1]))
				return (0);
	if (v.line < v.total_lines)
		if (v.counter <= v.column_limit[BOT_LINE])
			if (ft_strchr("0NEWS", map[v.line + 1][v.counter]) || \
				ft_strchr("0NEWS", map[v.line + 1][v.counter - 1]))
				return (0);
	return (1);
}

static int	just_walls_and_spaces(char *map_line)
{
	int		i;

	i = 0;
	while (map_line[i])
		if (ft_strchr("0NEWS", map_line[i++]))
			return (0);
	return (1);
}

static void	shift_back_matrix(char **ptr)
{
	int	i;

	i = 0;
	free(ptr[i]);
	while (ptr[i])
	{
		ptr[i] = ptr[i + 1];
		i++;
	}
}
