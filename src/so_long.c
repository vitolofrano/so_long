/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlofrano <vlofrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:52:20 by vlofrano          #+#    #+#             */
/*   Updated: 2023/03/16 17:41:11 by vlofrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <errno.h>
#include <fcntl.h>
#include <mlx.h>
#include <stdio.h>

int	ft_exit(t_data *data)
/* will show a message in the terminal and exit the process */
{
	mlx_destroy_window(data->mlx, data->win);
	ft_printf("Hai abbandonato :(\n");
	ft_printf("Troppo difficile?\n");
	exit(EXIT_FAILURE);
}

static int	ft_render_next_frame(t_data *data)
/* checks for keyboard or mouse input */
{
	put_background(data);
	ft_create_map(data);
	mlx_loop_hook(data->mlx, animation_boss, data);
	mlx_hook(data->win, 17, 1L << 2, ft_exit, data);
	mlx_hook(data->win, 2, 1L << 0, my_key_hook, data);
	return (0);
}

void	bercheck(char **argv, int argc)
{
	char	*file;
	int		len;

	if (argc < 2)
	{
		perror("Error\n Non scordare la mappa");
		exit(EXIT_FAILURE);
	}
	file = argv[1];
	len = ft_strlen(file);
	if (!(file[len - 1] == 'r' && file[len - 2] == 'e' && file[len - 3] == 'b'
			&& file[len - 4] == '.'))
	{
		perror("Error\n il file deve terminare con .ber");
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_map	map;

	bercheck(argv, argc);
	argc++;
	window_size(&data, argv);
	map.map = malloc(data.size_y + 1 * sizeof(char *));
	if (!map.map)
	{
		perror("Error\nmalloc failed\n");
		exit(EXIT_FAILURE);
	}
	ft_init(&data, &map);
	parse_map(argv, &data);
	if (!data.mlx)
	{
		perror("Error\nprogramm init failed\n");
		exit(EXIT_FAILURE);
	}
	data.img->animation = 1;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, data.size_x, data.size_y, "./so_long");
	ft_render_next_frame(&data);
	mlx_loop(data.mlx);
}
