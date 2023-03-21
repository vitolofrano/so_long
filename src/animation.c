/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlofrano <vlofrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 12:04:54 by vitol             #+#    #+#             */
/*   Updated: 2023/03/16 17:25:28 by vlofrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	imgputboss(t_data *data, char *path)
{
	int	img_width;
	int	img_height;

	mlx_put_image_to_window(data->mlx, data->win,
		mlx_xpm_file_to_image(data->mlx, path, &img_width, &img_height),
		(data->b_x * IMG_W), (data->b_y * IMG_H));
	data->img->animation++;
}

int	animation_boss(t_data *data)
{
	if (data->img->animation == 2000)
		imgputboss(data, data->img->boss);
	else if (data->img->animation == 4000)
		imgputboss(data, data->img->boss2);
	else if (data->img->animation == 6000)
		imgputboss(data, data->img->boss3);
	else if (data->img->animation == 8000)
		imgputboss(data, data->img->boss4);
	else
	{
		data->img->animation++;
	}
	if (data->img->animation > 8000)
		data->img->animation = 1;
	return (0);
}
