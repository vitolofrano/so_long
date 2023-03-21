/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlofrano <vlofrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:51:27 by vlofrano          #+#    #+#             */
/*   Updated: 2023/03/16 17:22:45 by vlofrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ptr_len(unsigned long long n)
{
	int	cont;

	cont = 0;
	while (n != 0)
	{
		n = n / 16;
		cont++;
	}
	return (cont);
}

int	ptr_print(unsigned long long num)
{
	write(1, "0x", 2);
	if (num == 0)
		return (write(1, "0", 1) + 2);
	else
		ptr_conv(num);
	return (ptr_len(num) + 2);
}

void	ptr_conv(unsigned long long num)
{
	if (num >= 16)
	{
		ptr_conv(num / 16);
		ptr_conv(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar(num + '0');
		else
			ft_putchar(num - 10 + 'a');
	}
}
