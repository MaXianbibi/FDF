/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 3022/08/06 14:37:10 by jmorneau          #+#    #+#             */
/*   Updated: 2022/08/08 18:37:23 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FDF.h"

// faire afficher un carré ;)

void square_of_pixelx(t_mlx *fdf, int x, int y, int color)
{
	int cx = x;
	int cy = y;	
	
	int i = 0;
	while (i++ < 30)
		mlx_pixel_put(fdf->basic.mlx, fdf->basic.win, cx++, cy++, color);
}

void square_of_pixely(t_mlx *fdf, int x, int y, int color)
{
	int cx = x;
	int cy = y;	
	
	int i = 0;
	while (i++ <= 30)
		mlx_pixel_put(fdf->basic.mlx, fdf->basic.win, cx++, cy--, color);
}

void square_put_pixel(t_mlx *fdf, int x, int y, int color)
{

	// int cs = x;
	// int cy = y;
	
	square_of_pixelx(fdf, x, y, color);
	square_of_pixely(fdf, x, y, color);
	square_of_pixely(fdf, x + 30, y + 30, color);
	square_of_pixelx(fdf, x + 30, y - 30, color);
}

// regler plusieur nombre int * ex 0 0 0 23 0 0
// void double_infecte(t_mlx *fdf, int i, int j)
// {
// 	int c;
	
// 	c = 0;
// 	if (fdf->map.map[i][j] == '1')
// 		return;
// 	if (i < fdf->map.col - 1 && fdf->map.map[i + 1][j] == 'c' )
// 		c++;
// 	else if (i > 0 && fdf->map.map[i - 1][j] == 'c')
// 		c++;
// 	if (j < fdf->map.raw - 1 && fdf->map.map[i][j + 1] == 'c')
// 		c++;
// 	else if(j > 0 && fdf->map.map[i][j - 1] == 'c')
// 		c++;
// 	if (c >= 2)
// 		fdf->map.map[i][j] = 'r';
		
// }

void infected(t_mlx *fdf, int i, int j)
{
	if (fdf->map.map[i][j - 1] != '1')
		fdf->map.map[i][j - 1] = 'c';
	if (fdf->map.map[i - 1][j] != '1')
		fdf->map.map[i - 1][j] = 'c';
	if (fdf->map.map[i - 1][j - 1] != '1')
		fdf->map.map[i - 1][j - 1] = 'c';

}

void map2print(t_mlx *fdf)
{
	int j = 0;
	int i = 0;

	while (fdf->map.map[i] != NULL)
	{
		j = 0;
		while (fdf->map.map[i][j] != '\0')
		{
			if (fdf->map.map[i][j] == '1')
				infected(fdf, i, j);
			j++;
		}
		i++;
	}
	i = 0;
}

 void square(t_mlx *fdf, int x, int y, int color)
{
	int cx;
	int cy;
	int j;	

	for (int i = 0; i < fdf->map.col; i++)
	{
		j = 0;
		cx = x;
		cy = y;
		if (fdf->map.map[(fdf->map.col - 1) - i][j] != '1' && fdf->map.map[(fdf->map.col - 1) - i][j] != 'c') //  && fdf->map.map[(fdf->map.col - 1) - i][j] != 'r'
			square_put_pixel(fdf, x, y, color);
		while (j < fdf->map.raw)
		{
			if (fdf->map.map[(fdf->map.col - 1) - i][j] != '1' && fdf->map.map[(fdf->map.col - 1) - i][j] != 'c' ) // && fdf->map.map[(fdf->map.col - 1) - i][j] != 'r'
				square_put_pixel(fdf, cx, cy, color);
			cy += 30;
			cx += 30;
			j++;
		}
		x += 30;
		y -= 30;
	}
}


int main()
{
	t_mlx fdf;
	int x = 500;
	int y = (1080 / 2) - 40; // merdic 
	int square_lenght;
	int i = 0;

	map_reader("/Users/jmorneau/Documents/fdf/maps/test.fdf", &fdf);
	map2print(&fdf);
	
	// for (int i = 0; i < fdf.map.col; i++)
	//  	for (int j = 0; j < fdf.map.raw; j++)
	// 		double_infecte(&fdf, i , j);

	while (fdf.map.map[i] != NULL)
		ft_printf("%s \n", fdf.map.map[i++]);

	square_lenght = 1080 / (fdf.map.col * 2) / 2; // a chier 

	fdf.basic.mlx = mlx_init();
	fdf.basic.win = mlx_new_window(fdf.basic.mlx, 1920, 1080, "fdf");
	
	square(&fdf, x, y, 0x2EFF2E);
	relief(&fdf, x, y);
	
	mlx_loop(fdf.basic.mlx);

}