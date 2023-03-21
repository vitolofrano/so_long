/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlofrano <vlofrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:16:40 by vlofrano          #+#    #+#             */
/*   Updated: 2023/03/16 16:26:00 by vlofrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_background(t_data *data)
/* will fill the whole screen with background */
{
	int		y;
	int		x;
	int		img_width;
	int		img_height;

	y = 0;
	while (y < data->size_y)
	{
		x = 0;
		while (x < data->size_x)
		{
			mlx_put_image_to_window(data->mlx, data->win,
				mlx_xpm_file_to_image(data->mlx, data->img->background,
					&img_width, &img_height), x, y);
			x += IMG_W;
		}
		y += IMG_H;
	}
}

void	ft_put_object(t_data *data, char *relative_path)
/* puts the given object to the current position */
{
	int		img_width;
	int		img_height;

	data->map->object = mlx_xpm_file_to_image(data->mlx, relative_path,
			&img_width, &img_height);
	mlx_put_image_to_window(data->mlx, data->win, data->map->object,
		(data->map->x * IMG_W), (data->map->y * IMG_H));
}

void	ft_put_player(t_data *data)
/* puts the player in the starting position */
{
	int		img_width;
	int		img_height;

	data->p_x = data->map->x;
	data->p_y = data->map->y;
	mlx_put_image_to_window(data->mlx, data->win,
		mlx_xpm_file_to_image(data->mlx, data->img->player_left,
			&img_width, &img_height),
		(data->p_x * IMG_W), (data->p_y * IMG_H));
}

void	ft_put_boss(t_data *data)
/* puts the player in the starting position */
{
	int		img_width;
	int		img_height;

	data->b_x = data->map->x;
	data->b_y = data->map->y;
	mlx_put_image_to_window(data->mlx, data->win,
		mlx_xpm_file_to_image(data->mlx, data->img->boss,
			&img_width, &img_height),
		(data->b_x * IMG_W), (data->b_y * IMG_H));
}
