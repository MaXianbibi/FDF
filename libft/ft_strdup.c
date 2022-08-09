/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 18:17:32 by jmorneau          #+#    #+#             */
/*   Updated: 2022/04/02 18:19:17 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*cs;
	int		i;

	i = 0;
	cs = (char *)malloc(sizeof(char) * ft_strlen((char *)s) + 1);
	if (!cs)
		return (NULL);
	while (s[i] != '\0')
	{
		cs[i] = s[i];
		i++;
	}
	cs[i] = '\0';
	return (cs);
}
