/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlofrano <vlofrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:30:25 by vlofrano          #+#    #+#             */
/*   Updated: 2023/03/16 17:21:34 by vlofrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	lenght(int nb, int base)
{
	int	count;

	count = 0;
	if (nb <= 0)
		count++;
	while (nb)
	{
		nb /= base;
		count++;
	}
	return (count);
}

char	*ft_itoa(int nb)
{
	int			len;
	char		*s;

	len = lenght(nb, 10);
	s = malloc(sizeof(char) * (len + 1));
	if (!s)
		return (0);
	s[len] = 0;
	if (nb == 0)
		s[0] = '0';
	if (nb < 0)
		s[0] = '-';
	while (nb)
	{
		if (nb > 0)
			s[--len] = (nb % 10) + 48;
		else
			s[--len] = (nb % 10 * -1) + 48;
		nb /= 10;
	}
	return (s);
}
