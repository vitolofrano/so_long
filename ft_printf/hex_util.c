/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlofrano <vlofrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:54:45 by vlofrano          #+#    #+#             */
/*   Updated: 2023/02/07 11:37:00 by vlofrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	len_hex(unsigned int a)
{
	int	i;

	i = 0;
	while (a >= 16)
	{
		i++;
		a /= 16;
	}
	return (i + 1);
}

void	ft_put_hex(unsigned int a, char s)
{
	if (a >= 16)
	{
		ft_put_hex(a / 16, s);
		ft_put_hex(a % 16, s);
	}
	else
	{
		if (a <= 9)
			ft_putchar((a + '0'));
		else
		{
			if (s == 'x')
				ft_putchar(a - 10 + 'a');
			if (s == 'X')
				ft_putchar((a - 10 + 'A'));
		}
	}
}

int	ft_print_hex(unsigned int a, const char s)
{
	int	i;

	i = 0;
	if (a == 0)
	{
		return (write(1, "0", 1));
		i++;
	}
	ft_put_hex(a, s);
	return (len_hex(a) + i);
}
