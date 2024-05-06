/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htakayam <htakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:03:27 by htakayam          #+#    #+#             */
/*   Updated: 2024/05/04 23:01:36 by htakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_0x(void)
{
	return (write(1, "0x", 2));
}

int	print_hex(unsigned long n, int *i, int is_upper)
{
	char	c;

	if (n >= 16)
		print_hex(n / 16, i, is_upper);
	if (n % 16 < 10)
		c = '0' + n % 16;
	else
	{
		if (is_upper)
			c = 'A' + (n % 16 - 10);
		else
			c = 'a' + (n % 16 - 10);
	}
	write(1, &c, 1);
	(*i)++;
	return (*i);
}
