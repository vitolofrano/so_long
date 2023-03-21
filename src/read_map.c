/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlofrano <vlofrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:05:44 by vitol             #+#    #+#             */
/*   Updated: 2023/03/16 15:59:00 by vlofrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../so_long.h"
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	count_line_len(int fd)
{
	char	buffer[1];
	int		length;
	int		bytes;

	buffer[0] = '\0';
	bytes = 1;
	length = 0;
	while (bytes == 1)
	{
		bytes = read(fd, buffer, 1);
		if (buffer[0] != '\n')
			length++;
		else
			break ;
	}
	return (length);
}

int	count_line(int fd, int x)
{
	char	*line;
	int		linecount;

	linecount = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if ((int)ft_strlen(line) < x / IMG_W || (ft_strlen(line) == 1
				&& *line != '\n'))
		{
			free(line);
			perror("Error\n controlla le righe della mappa");
			exit(EXIT_FAILURE);
			break ;
		}
		else
		{
			free(line);
			linecount++;
		}
	}
	return (linecount);
}

void	window_size(t_data *data, char **argv)
{
	int	fd;
	int	linelen;

	fd = open(argv[1], O_RDONLY);
	linelen = count_line_len(fd);
	data->size_x = (linelen * IMG_W);
	data->size_y = (count_line(fd, data->size_x) * IMG_H);
	if (data->size_x == data->size_y)
	{
		perror("Error\n la mappa deve essere rettangolare");
		exit(EXIT_FAILURE);
	}
}

void	ft_create_map(t_data *data)
/* will fill the map with the corresponding images */
{
	data->map->x = 0;
	data->map->y = 0;
	while (data->map->y < (data->size_y / IMG_H))
	{
		if (data->map->map[data->map->y][data->map->x] == 'P')
			ft_put_player(data);
		else if (data->map->map[data->map->y][data->map->x] == '1')
			ft_put_object(data, "./assets/three.xpm");
		else if (data->map->map[data->map->y][data->map->x] == 'C')
			ft_put_object(data, "./assets/Yakitori.xpm");
		else if (data->map->map[data->map->y][data->map->x] == 'E')
			ft_put_object(data, "./assets/leave.xpm");
		else if (data->map->map[data->map->y][data->map->x] == 'B')
			ft_put_boss(data);
		if (data->map->x < (data->size_x / IMG_W))
			data->map->x++;
		else
		{
			data->map->y++;
			data->map->x = 0;
		}
	}
}
