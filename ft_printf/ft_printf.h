/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlofrano <vlofrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:20:02 by vlofrano          #+#    #+#             */
/*   Updated: 2023/02/07 13:41:40 by vlofrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define TYPES "cspdiuxX"

void	ft_putchar(char c);
int		ft_putstr(char *str);

int		ft_switch(char type, va_list curr_param);
int		ft_printf(const char *a, ...);
int		ptr_len(unsigned long long n);
int		print_char(va_list param);
void	ptr_conv(unsigned long long num);
int		len_hex(unsigned int num);
void	ft_put_hex(unsigned int num, const char format);
int		ft_print_hex(unsigned int num, const char format);

int		ft_putnbr(int nb);

int		len(int n);
int		ptr_print(unsigned long long num);
int		unlen(long long nb, int base);
int		ft_put_unsigned_nbr(unsigned int nb);

#endif