/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htakayam <htakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 17:55:17 by htakayam          #+#    #+#             */
/*   Updated: 2024/05/06 12:18:19 by htakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>

int		ft_printf(const char *fmt, ...);
int		print_char(int c);
int		print_decimal(int n);
int		print_str(char *s);
int		print_uint(unsigned int un);
int		print_hex(unsigned long n, int *i, int is_upper);
int		print_0x(void);
int		ft_check_type(char c, va_list args, unsigned int cnt);

int		ft_atoi(const char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);

#endif