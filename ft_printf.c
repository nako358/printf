/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htakayam <htakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 12:58:21 by htakayam          #+#    #+#             */
/*   Updated: 2024/05/06 12:17:57 by htakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_type(char c, va_list args, unsigned int cnt)
{
	int	i;

	i = 0;
	if (c == 'c')
		cnt += print_char((int)va_arg(args, int));
	else if (c == 's')
		cnt += print_str((char *)va_arg(args, char *));
	else if (c == 'p')
		cnt += print_0x() + print_hex(va_arg(args, unsigned long long), &i, 0);
	else if (c == 'd')
		cnt += print_decimal((int)va_arg(args, int));
	else if (c == 'i')
		cnt += print_decimal((int)va_arg(args, int));
	else if (c == 'u')
		cnt += print_uint((unsigned long long)va_arg(args, unsigned long long));
	else if (c == 'x')
		cnt += print_hex((unsigned long)va_arg(args, unsigned int), &i, 0);
	else if (c == 'X')
		cnt += print_hex((unsigned long)va_arg(args, unsigned int), &i, 1);
	else if (c == '%')
		cnt += print_char('%');
	else
		cnt += print_char(c);
	return (cnt);
}

int	ft_printf(const char *fmt, ...)
{
	va_list			args;
	unsigned int	cnt;

	va_start(args, fmt);
	cnt = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			cnt += ft_check_type(*fmt, args, 0);
		}
		else
		{
			ft_putchar_fd(*fmt, 1);
			cnt++;
		}
		fmt++;
	}
	va_end(args);
	return ((int)cnt);
}
