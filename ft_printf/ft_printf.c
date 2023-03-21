/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlofrano <vlofrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:06:10 by vlofrano          #+#    #+#             */
/*   Updated: 2023/02/07 12:21:50 by vlofrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_switch(char s, va_list param)
{
	if (s == 'c')
		return (print_char(param));
	else if (s == 's')
		return (ft_putstr(va_arg(param, char *)));
	else if (s == 'p')
		return (ptr_print(va_arg(param, unsigned long long)));
	else if (s == 'd')
		return (ft_putnbr(va_arg(param, long int)));
	else if (s == 'i')
		return (ft_putnbr(va_arg(param, int)));
	else if (s == 'u')
		return (ft_put_unsigned_nbr(va_arg(param, unsigned int)));
	else if (s == 'x' || s == 'X')
		return (ft_print_hex(va_arg(param, unsigned int), s));
	else if (s == '%')
		ft_putchar('%');
	else
		ft_putchar(s);
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list	param;
	int		i;
	int		counter;

	va_start(param, format);
	i = 0;
	counter = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			counter += ft_switch(format[i], param);
			i++;
		}
		if (!format[i])
			return (counter);
		if (format[i] != '%')
		{
			counter++;
			ft_putchar(format[i]);
			i++;
		}
	}
	return (counter);
}
