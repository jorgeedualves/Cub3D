/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 12:49:31 by joeduard          #+#    #+#             */
/*   Updated: 2022/10/24 17:42:57 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	event_handler(t_data *data)
{
    mlx_hook(data->mlx.mlx_ptr, X_EVENT_KEY_PRESS, 1L << 0, &key_press, data);
    mlx_hook (data->mlx.win_ptr, X_EVENT_KEY_EXIT, 0, &click_close, data);
}