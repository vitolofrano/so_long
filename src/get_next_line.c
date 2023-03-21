/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlofrano <vlofrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:32:45 by vlofrano          #+#    #+#             */
/*   Updated: 2023/03/16 16:33:27 by vlofrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	helper(char *new_a, int i)
{
	if (new_a[i - 1] == '\n')
		new_a[i - 1] = '\0';
	new_a[i] = '\0';
}

char	*get_next_line(int fd)
{
	char	a[999999];
	char	buffer[1];
	char	*new_a;
	int		i;

	i = 0;
	a[i] = 0;
	while (read(fd, buffer, 1) == 1)
	{
		a[i] = buffer[0];
		a[i + 1] = '\0';
		if (a[i] == '\n' || !a[i])
			break ;
		i++;
	}
	if (a[0] == '\n' || !a[0])
		return (NULL);
	new_a = malloc(i + 1);
	if (!new_a)
		return (NULL);
	i = -1;
	while (a[++i])
		new_a[i] = a[i];
	helper(new_a, i);
	return (new_a);
}
