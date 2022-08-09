/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:45:35 by jmorneau          #+#    #+#             */
/*   Updated: 2022/04/15 18:36:45 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dest_cpy;
	const char	*src_cpy;

	if (!dest && !src)
		return (0);
	dest_cpy = dest;
	src_cpy = src;
	while (n-- > 0)
		*dest_cpy++ = *src_cpy++;
	return (dest);
}
