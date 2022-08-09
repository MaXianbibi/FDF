/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:03:49 by jmorneau          #+#    #+#             */
/*   Updated: 2022/05/08 19:02:36 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	format(const char *fmt, va_list ap)
{
	int	count;

	count = 0;
	if (*fmt == 's')
		count += ft_printf_string(va_arg(ap, char *));
	else if (*fmt == 'd' || *fmt == 'i')
		count += ft_printf_nbr(va_arg(ap, int));
	else if (*fmt == 'c')
		count += ft_print_char(va_arg(ap, int));
	else if (*fmt == 'p')
		count += ft_printf_ptr(va_arg(ap, unsigned long long));
	else if (*fmt == 'u')
		count += ft_print_unsigned(va_arg(ap, unsigned int));
	else if (*fmt == 'x' || *fmt == 'X')
		count += ft_printf_hex(va_arg(ap, unsigned int), *fmt);
	else if (*fmt == '%')
		count += ft_print_char('%');
	else
		return (0);
	return (count);
}

int	ft_printf(const char *fmt, ...)
{
	int		count;
	va_list	ap;

	va_start(ap, fmt);
	count = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			count += format(++fmt, ap);
		}
		else
		{
			ft_putchar_fd(*fmt, 1);
			count++;
		}
		fmt++;
	}
	va_end(ap);
	return (count);
}
