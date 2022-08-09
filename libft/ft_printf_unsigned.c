/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:35:04 by jmorneau          #+#    #+#             */
/*   Updated: 2022/05/08 19:02:34 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	unsigned_lennbr(unsigned int n)
{
	int	count;

	count = 0;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count + 1);
}

void	ft_unsigned_putnbr_fd(unsigned int n, int fd)
{
	if (n > 9)
		ft_unsigned_putnbr_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + 48, fd);
}

int	ft_print_unsigned(unsigned int n)
{	
	if (0 >= n)
		return (ft_printf_nbr(n));
	ft_unsigned_putnbr_fd(4294967295 + (n + 1), 1);
	return (unsigned_lennbr(4294967295 + (n + 1)) - 1);
}
