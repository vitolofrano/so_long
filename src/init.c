/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlofrano <vlofrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:31:45 by vlofrano          #+#    #+#             */
/*   Updated: 2023/03/16 16:32:21 by vlofrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_init(t_data *data, t_map *map)
/* initialises most of my used data inside the structs */
{
	t_img	*img;

	data->map = map;
	img = malloc(sizeof(t_img));
	if (!img)
	{
		perror("Error\nmalloc failed\n");
		exit(EXIT_FAILURE);
	}
	data->img = img;
	data->img->player_up = "./assets/ninja-up.xpm";
	data->img->player_left = "./assets/ninja-left.xpm";
	data->img->boss = "./assets/boss.xpm";
	data->img->boss2 = "./assets/boss2.xpm";
	data->img->boss3 = "./assets/boss3.xpm";
	data->img->boss4 = "./assets/boss4.xpm";
	data->img->player_down = "./assets/ninja-low.xpm";
	data->img->player_right = "./assets/ninja-right.xpm";
	data->img->animation = 1;
	data->img->background = "./assets/floor.xpm";
	data->counter = 0;
	data->collected = 0;
}
