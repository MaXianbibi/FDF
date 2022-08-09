/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:14:29 by jmorneau          #+#    #+#             */
/*   Updated: 2022/04/02 17:15:28 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*cs;
	unsigned int	i;
	int				len;

	if (s == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen((char *)s);
	cs = malloc(sizeof(char) * len + 1);
	if (cs == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		cs[i] = f(i, s[i]);
		i++;
	}
	cs[i] = '\0';
	return (cs);
}
