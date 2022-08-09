/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:03:42 by jmorneau          #+#    #+#             */
/*   Updated: 2022/04/14 15:17:40 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	signe;
	int	res;

	res = 0;
	signe = 1;
	i = 0;
	while ((str[i] > 8 && 14 > str[i]) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] > 47 && 58 > str[i])
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res * signe);
}
