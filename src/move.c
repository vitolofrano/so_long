/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlofrano <vlofrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:48:58 by vlofrano          #+#    #+#             */
/*   Updated: 2023/03/16 16:27:38 by vlofrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	help_player_move(t_data *data, char position, int direction)
{
	int	img_width;
	int	img_height;

	if (position == 'y' && direction == DOWN)
	{
		mlx_put_image_to_window(data->mlx, data->win,
			mlx_xpm_file_to_image(data->mlx, data->img->player_down,
				&img_width, &img_height), (data->p_x * IMG_W), (data->p_y
				* IMG_H));
	}
	if (position == 'x' && direction == RIGHT)
	{
		mlx_put_image_to_window(data->mlx, data->win,
			mlx_xpm_file_to_image(data->mlx, data->img->player_right,
				&img_width, &img_height), (data->p_x * IMG_W), (data->p_y
				* IMG_H));
	}
}

static void	ft_player_move(t_data *data, char position, int direction)
/* will put the correct orientation of the spaceship on the screen */
{
	int	img_width;
	int	img_height;

	if (position == 'y' && direction == UP)
	{
		mlx_put_image_to_window(data->mlx, data->win,
			mlx_xpm_file_to_image(data->mlx, data->img->player_up,
				&img_width, &img_height), (data->p_x * IMG_W), (data->p_y
				* IMG_H));
	}
	if (position == 'x' && direction == LEFT)
	{
		mlx_put_image_to_window(data->mlx, data->win,
			mlx_xpm_file_to_image(data->mlx, data->img->player_left,
				&img_width, &img_height), (data->p_x * IMG_W), (data->p_y
				* IMG_H));
	}
	help_player_move(data, position, direction);
}

void	help_move3(t_data *data)
{
	int		img_width;
	int		img_height;

	mlx_put_image_to_window(data->mlx, data->win,
		mlx_xpm_file_to_image(data->mlx, data->img->background, &img_width,
			&img_height), (data->p_x * IMG_W), (data->p_y * IMG_H));
}

void	help_move(t_data *data, char pos, int dir)
{
	help_move3(data);
	if (pos == 'y' && data->map->map[data->p_y + 1 * dir][data->p_x] != '1'
	&& (data->map->map[data->p_y + 1 * dir][data->p_x] != 'E'
	|| data->collected == data->map->diamonds)
	&& (data->map->map[data->p_y + 1 * dir][data->p_x] != 'B'))
		data->p_y = data->p_y + 1 * dir;
	else if (pos == 'x' && data->map->map[data->p_y][data->p_x + 1 * dir] != '1'
	&&
	(data->map->map[data->p_y][data->p_x + 1 * dir] != 'E'
	|| data->collected == data->map->diamonds)
	&& data->map->map[data->p_y][data->p_x + 1 * dir] != 'B')
		data->p_x = data->p_x + 1 * dir;
	else if (pos == 'y' && data->map->map[data->p_y + 1 * dir][data->p_x] == 'E'
	&& data->collected != data->map->diamonds)
		ft_printf("Colleziona tutti i coin per uscire\n");
	else if (pos == 'x' && data->map->map[data->p_y][data->p_x + 1 * dir] == 'E'
	&& data->collected != data->map->diamonds)
		ft_printf("Colleziona tutti i coin per uscire\n");
	else if (data->map->map[data->p_y][data->p_x + 1 * dir] == 'B'
	|| data->map->map[data->p_y + 1 * dir][data->p_x] == 'B')
		lose();
}

void	move(t_data *data, char pos, int dir)
{
	int		img_width;
	int		img_height;
	char	*var;

	help_move(data, pos, dir);
	ft_player_move(data, pos, dir);
	if (data->map->map[data->p_y][data->p_x] == 'C')
		ft_collect(data);
	mlx_do_sync(data->mlx);
	mlx_put_image_to_window(data->mlx, data->win,
		mlx_xpm_file_to_image(data->mlx, "./assets/three.xpm", &img_width,
			&img_height), 100, 0);
	mlx_string_put(data->mlx, data->win, 50, 20, 255 * 65536 + 255 * 256 + 255,
		"Mosse : ");
	var = ft_itoa(++data->counter);
	mlx_string_put(data->mlx, data->win, 100, 20, 255 * 65536 + 255 * 256 + 255,
		var);
	free(var);
	ft_printf("You moved %d times.\n", data->counter);
}
