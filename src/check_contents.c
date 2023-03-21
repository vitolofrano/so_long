/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_contents.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlofrano <vlofrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:12:02 by vitol             #+#    #+#             */
/*   Updated: 2023/03/16 17:10:38 by vlofrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	countobj(char *s, char obj)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] && s)
	{
		if (s[i] == obj)
		{
			count++;
		}
		i++;
	}
	return (count);
}

void	help_check_3(t_data *data, int line_len, char **map)
{
	int	i;

	i = 1;
	while (i < (data->size_y / IMG_H) - 2)
	{
		if (map[i][0] != '1')
		{
			perror("Error\nControlla i bordi della mappa");
			exit(EXIT_FAILURE);
		}
		if (map[i][line_len - 1] != '1')
		{
			perror("Error\nControlla i bordi della mappa");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	help_check_border(t_data *data, int line_len, char **map)
{
	int	i;
	int	j;

	i = (data->size_y / IMG_H) - 1;
	j = 0;
	while (j < line_len)
	{
		if (map[i][j] != '1')
		{
			perror("Error\nControlla i bordi della mappa");
			exit(EXIT_FAILURE);
		}
		j++;
	}
}

void	check_border(t_data *data)
{
	char	**map;
	int		i;
	int		j;
	int		line_len;

	map = data->map->map;
	i = 0;
	j = 0;
	line_len = (data->size_x) / IMG_W;
	while (j < line_len)
	{
		if (map[i][j] != '1')
		{
			perror("Error\nControlla i bordi della mappa");
			exit(EXIT_FAILURE);
		}
		j++;
	}
	help_check_border(data, line_len, map);
}

void	check_contents(t_data *data)
{
	int	exit;
	int	player;
	int	y;

	exit = 0;
	player = 0;
	data->map->diamonds = 0;
	y = 0;
	while (data->map->map && data->map->map[y])
	{
		exit += countobj(data->map->map[y], 'E');
		player += countobj(data->map->map[y], 'P');
		data->map->diamonds += countobj(data->map->map[y], 'C');
		y++;
	}
	if (player != 1)
		ft_map_error("Error\nDeve esserci almeno un giocatore\n");
	if (exit == 0)
		ft_map_error("Error\nDeve esserci almeno un uscita\n");
	if (data->map->diamonds == 0)
		ft_map_error("Error\nDeve esserci almeno un coin\n");
}
