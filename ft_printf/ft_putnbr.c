/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlofrano <vlofrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:01:10 by vlofrano          #+#    #+#             */
/*   Updated: 2023/03/16 17:22:28 by vlofrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	len(int a)
{
	int	i;

	i = 0;
	if (a < 0)
	{
		if (a == -2147483648)
			a = -2147483647;
		i++;
		a = -a;
	}
	while (a > 9)
	{
		i++;
		a = a / 10;
	}
	return (i + 1);
}

int	ft_putnbr(int a)
{
	if (a == -2147483648)
	{
		ft_putnbr(a / 10);
		ft_putchar('8');
	}
	else if (a < 0)
	{
		ft_putchar('-');
		ft_putnbr(-a);
	}
	else
	{
		if (a > 9)
		{
			ft_putnbr(a / 10);
		}
		ft_putchar(48 + a % 10);
	}
	return (len(a));
}

int	unlen(long long nb, int base)
{
	int	count;

	count = 0;
	if (nb <= 0)
		++count;
	while (nb && ++count)
		nb /= base;
	return (count);
}

int	ft_put_unsigned_nbr(unsigned int nb)
{
	if (nb == 4294967295)
	{
		ft_putnbr(nb / 10);
		ft_putchar('5');
	}
	else
	{
		if (nb > 9)
		{
			ft_putnbr(nb / 10);
		}
		ft_putchar(48 + nb % 10);
	}
	return (unlen(nb, 10));
}
