/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 21:35:07 by jmorneau          #+#    #+#             */
/*   Updated: 2022/05/08 18:59:47 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_next_line(char *stach)
{
	char	*new_stach;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (stach[i] != '\0' && stach[i] != '\n')
		i++;
	if (stach[i] == '\0')
	{
		free(stach);
		return (NULL);
	}
	new_stach = malloc(ft_strlen(stach) - i + 1 * sizeof(char));
	if (!new_stach)
		return (NULL);
	i++;
	while (stach[i] != '\0')
		new_stach[j++] = stach[i++];
	new_stach[j] = '\0';
	free(stach);
	return (new_stach);
}

char	*ft_line(char *stach)
{
	int		i;
	char	*line;

	i = 0;
	if (!*stach)
		return (NULL);
	while (stach[i] && stach[i] != '\n')
		i++;
	line = malloc(i + 2 * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (stach[i] && stach[i] != '\n')
	{
		line[i] = stach[i];
		i++;
	}
	if (stach[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_free(char *stach, char *buffer)
{
	char	*join;

	join = ft_strjoin(stach, buffer);
	free (stach);
	return (join);
}

char	*read_file(int fd, char *stach)
{
	char	*buffer;
	int		bytes_read;

	if (!stach)
		stach = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		stach = ft_free(stach, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free (buffer);
	return (stach);
}

char	*get_next_line(int fd)
{
	static char	*stach;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	stach = read_file(fd, stach);
	if (!stach)
		return (NULL);
	line = ft_line(stach);
	stach = ft_next_line(stach);
	return (line);
}
