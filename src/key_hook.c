/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlofrano <vlofrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 23:16:03 by vitol             #+#    #+#             */
/*   Updated: 2023/03/16 16:29:59 by vlofrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	my_key_hook(int keycode, t_data *data)
{
	if (keycode == W)
		move(data, 'y', UP);
	else if (keycode == ESC)
		ft_exit(data);
	else if (keycode == A)
		move(data, 'x', LEFT);
	else if (keycode == S)
		move(data, 'y', DOWN);
	else if (keycode == D)
		move(data, 'x', RIGHT);
	if (data->map->map[data->p_y][data->p_x] == 'E')
		win(data);
	mlx_string_put(data->mlx, data->win, 150, 150, 255 * 65536 + 255 * 256
		+ 255, "");
	return (0);
}
