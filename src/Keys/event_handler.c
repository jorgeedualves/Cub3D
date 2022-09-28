/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 12:49:31 by joeduard          #+#    #+#             */
/*   Updated: 2022/09/28 15:04:06 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	event_handler(t_game *game)
{
    mlx_hook(game->win, X_EVENT_KEY_PRESS, 1L << 0, &key_press, game);
}