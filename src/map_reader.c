/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 16:19:36 by jmorneau          #+#    #+#             */
/*   Updated: 2022/08/06 21:51:40 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FDF.h"

static int	file_linecount(char *file)
{
	int		linecount;
	int		fd;
	int		readcount;
	char	c;

	fd = open(file, O_RDONLY);
	if (!fd)
		return (-1);
	linecount = 1;
	while (1)
	{
		readcount = read(fd, &c, 1);
		if (readcount == 0)
			break ;
		if (readcount < 0)
			return (-1);
		if (c == '\n')
			linecount++;
	}
	close(fd);
	return (linecount);
}

char *remove_space(char *str) // a optimiser prend de la place innu
{
	int i;
	char *new_str;
	int j = 0;

	i = 0;
	new_str = ft_calloc(ft_strlen(str), 1);
	while(str[i])
	{
		if (str[i] != ' ')
			new_str[j++] = str[i];
		i++;
	}
	new_str[j] = '\0';
	free (str);
	return (new_str);
}


bool	map_reader(char *file, t_mlx *fdf)
{
	int	fd;
	int	i;

	i = 0;
	fdf->map.raw = 0;
	fdf->map.col = file_linecount(file);
	fdf->map.map = malloc(sizeof(char *) * fdf->map.col + 1);
	fd = open(file, O_RDONLY);
	while (i < fdf->map.col)
		fdf->map.map[i++] = remove_space(get_next_line(fd));
	i = 0;
	while (fdf->map.map[0][++i])
		fdf->map.raw++;
	fdf->map.map[fdf->map.col] = NULL;
	return (true);
}
