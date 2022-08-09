/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 20:07:28 by jmorneau          #+#    #+#             */
/*   Updated: 2022/05/08 19:02:24 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hex_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		num /= 16;
		len++;
	}
	return (len);
}

void	ft_put_hex(unsigned int num, const char format)
{
	if (num >= 16)
	{
		ft_put_hex(num / 16, format);
		ft_put_hex(num % 16, format);
	}
	else
	{	
		if (num < 10)
			ft_putchar_fd(num + '0', 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd(num - 10 + 'a', 1);
			else
				ft_putchar_fd(num - 10 + 'A', 1);
		}
	}
}

int	ft_printf_hex(unsigned int num, const char format)
{
	if (num == 0)
		return (write(1, "0", 1));
	ft_put_hex(num, format);
	return (ft_hex_len(num));
}
