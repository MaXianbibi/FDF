/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FDF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:40:03 by jmorneau          #+#    #+#             */
/*   Updated: 2022/08/06 21:54:29 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF
# define FDF

# include "./libft.h"
# include <mlx.h>

typedef struct s_map
{
	char	**map;
	int		col;
	int		raw;
}	t_map;



typedef struct s_basic
{
	void	*mlx;
	void	*win;
}	t_basic;

typedef struct s_mlx
{
	t_basic	basic;
	t_map map;
}	t_mlx;

bool map_reader(char *file, t_mlx *fdf);
void relief(t_mlx *fdf, int x, int y);
void square(t_mlx *fdf, int x, int y, int color);
void square_put_pixel(t_mlx *fdf, int x, int y, int color);


void square_of_pixelx(t_mlx *fdf, int x, int y, int color);

#endif