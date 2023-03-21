/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlofrano <vlofrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:12:28 by vlofrano          #+#    #+#             */
/*   Updated: 2023/03/16 17:11:10 by vlofrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../so_long.h"

void	parse_map(char **argv, t_data *data)
{
	int		fd;
	int		i;
	int		bytes;
	char	buffer[2];

	i = 0;
	bytes = 1;
	buffer[1] = '\0';
	fd = open(argv[1], O_RDONLY);
	while (bytes == 1)
	{
		bytes = read(fd, buffer, 1);
		if (bytes != 1)
			break ;
		if (buffer[0] != '\n' && buffer[0] != '\0')
		{
			data->map->map[i] = ft_strjoin(data->map->map[i], buffer);
		}
		else
			i++;
	}
	check_border(data);
	check_contents(data);
}

void	ft_map_error(char *error_msg)
/* will print the error message end exit the process */
{
	printf("%s", error_msg);
	exit(EXIT_FAILURE);
}
