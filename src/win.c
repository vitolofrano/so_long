/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlofrano <vlofrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:06:11 by vitol             #+#    #+#             */
/*   Updated: 2023/03/16 16:14:47 by vlofrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../so_long.h"

void	win(t_data *data)
{
	ft_printf("HAI VINTO");
	ft_printf("%d", data->counter);
	exit(EXIT_SUCCESS);
}

void	ft_collect(t_data *data)
{
	data->collected++;
	data->map->map[data->p_y][data->p_x] = '0';
}

void	lose(void)
{
	write(1, "Amico hai perso!", 16);
	exit(EXIT_FAILURE);
}
