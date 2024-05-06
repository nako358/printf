/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htakayam <htakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 19:34:40 by htakayam          #+#    #+#             */
/*   Updated: 2024/05/06 12:24:41 by htakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_decimal(int i)
{
	char	*str;
	int		n;

	str = ft_itoa(i);
	n = print_str(str);
	free(str);
	return (n);
}

int	print_uint(unsigned int n)
{
	char			str;
	unsigned int	temp;
	size_t			t;

	temp = n;
	t = 0;
	while (9 < temp)
	{
		temp = temp / 10;
		t++;
	}
	if (9 < n)
		print_uint(n / 10);
	str = '0' + n % 10;
	write(1, &str, 1);
	t++;
	return (t);
}
