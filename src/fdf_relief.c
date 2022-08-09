/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_relief.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 17:44:54 by jmorneau          #+#    #+#             */
/*   Updated: 2022/08/08 22:39:36 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FDF.h"


# define TEST 30

# define ALTITUDE 3.75

# define altitude_max 90

void print_relief_droit(t_mlx *fdf, int x, int y, int i, int j)
{
	float cy = 0;
	float cx = 0;
	
	while (cx < TEST) 
	{
		mlx_pixel_put(fdf->basic.mlx, fdf->basic.win, cx + (x + TEST * j) + ((fdf->map.col - (i + 1)) * TEST), cy + (y + TEST * j) - ((fdf->map.col - 1) - i) * TEST, 0xFFFFFF);
		cy -= (((15 * ALTITUDE) - 15) / 15) / 4.0;
		cx += 0.25;
	}

}

void print_relief_haut(t_mlx *fdf, int x, int y, int i, int j)
{
	float cy = 0;
	float cx = 0;
	
	while (cx < TEST)
	{
		mlx_pixel_put(fdf->basic.mlx, fdf->basic.win, cx + (x + TEST * j) + ((fdf->map.col - (i + 1)) * TEST), cy + (y + TEST * j) - 60 - ((fdf->map.col - 1) - i) * TEST, 0xFFFFFF);
		cy -= ((ALTITUDE * 15) - 45) / 15.0;
		cx += 1;
	}

}

void print_relief_gauche(t_mlx *fdf, int x, int y, int i, int j)
{
	float cy = 0;
	float cx = 0;
	
	while (cx > -TEST)
	{
		mlx_pixel_put(fdf->basic.mlx, fdf->basic.win, cx + (x + TEST * j) + ((fdf->map.col - (i + 1)) * TEST) + 60, cy + (y + TEST * j) - 60 - ((fdf->map.col - 1) - i) * TEST, 0xFFFFFF);
		cy -= ((ALTITUDE * 15) - 45) / 15.0;
		cx -= 1;
	}
	
}

void print_relief_bas(t_mlx *fdf, int x, int y, int i, int j)
{
	float cy = 0;
	float cx = 0;

	while (cx > -TEST) 
	{
		mlx_pixel_put(fdf->basic.mlx, fdf->basic.win, cx + (x + TEST * j) + ((fdf->map.col - (i + 1)) * TEST) + (TEST * 2), cy + (y + TEST * j) - ((fdf->map.col - 1) - i) * TEST, 0xFFFFFF); 
		
		cy -= (((15 * ALTITUDE) - 15) / 15) / 4.0;
		cx -= (0.25); 
	}
}

void print_triangle(t_mlx *fdf, int x, int y, int i, int j)
{
	print_relief_droit(fdf, x, y, i ,j);
	print_relief_bas(fdf, x, y, i, j);
	print_relief_haut(fdf, x, y, i ,j);
	print_relief_gauche(fdf, x, y , i, j);
}

bool test_corner(char **map, int i, int j)
{
	if (map[i + 1][j] == '1')
		return (false);
	if (map[i - 1][j] == '1')
		return (false);
	if (map[i][j + 1] == '1')
		return (false);
	if (map[i][j - 1] == '1')
		return (false);
	return (true);
}

void print_line_in_between_raw(t_mlx *fdf, int x, int y, int i, int j)
{
	float cy = 0;
	float cx = 0;
	
	
	while (cx > -TEST)
	{
		mlx_pixel_put(fdf->basic.mlx, fdf->basic.win, cx + (x + TEST * j) + ((fdf->map.col - (i + 1)) * TEST) + 60, cy + (y + TEST * j) - 60 - ((fdf->map.col - 1) - i) * TEST, 0xFFFFFF);
		cy -= 1;
		cx -= 1;
	}
}

void print_line_in_between_col(t_mlx *fdf, int x, int y, int i, int j)
{
	float cy = 0;
	float cx = 0;
	
	while (cx < TEST)
	{
		mlx_pixel_put(fdf->basic.mlx, fdf->basic.win, cx + (x + TEST * j) + ((fdf->map.col - (i + 1)) * TEST) + 60, cy + (y + TEST * j) - 60 - ((fdf->map.col - 1) - i) * TEST, 0xFFFFFF);
		cy -= 1;
		cx += 1;
	}
}

void print_raw(t_mlx *fdf, int x, int y, int i, int j)
{
	print_relief_droit(fdf, x, y, i ,j);
	print_relief_gauche(fdf, x, y, i ,j);
	
	 if (fdf->map.map[i][j + 1] == '0' || fdf->map.map[i][j + 1] == 'c' )
	 	print_relief_bas(fdf, x, y, i ,j);
	else if (fdf->map.map[i][j - 1] == 'c')
		print_relief_haut(fdf, x, y, i ,j);
		
	if (fdf->map.map[i][j + 1] == '1')
		print_line_in_between_raw(fdf, x, y + ((4.0 - ALTITUDE) * 30.0), i, j);
}

void print_col(t_mlx *fdf, int x, int y, int i, int j)
{
	
	print_relief_bas(fdf, x, y, i ,j);
	print_relief_haut(fdf, x, y, i ,j);

	if (fdf->map.map[i + 1][j] == '0' || fdf->map.map[i + 1][j] == 'c' )
		print_relief_droit(fdf, x, y, i ,j);
	else if (fdf->map.map[i - 1][j] == 'c' || fdf->map.map[i - 1][j] == '0')
		print_relief_gauche(fdf, x, y, i ,j);
		
	if (fdf->map.map[i + 1][j] == '1')
		print_line_in_between_col(fdf, x - 60, y + ((4.0 - ALTITUDE) * 30.0), i, j);

}

void print_relief_corner(t_mlx *fdf, int x, int y, int i, int j)
{
	float cy = 0;
	float cx = 0;
	
	while (cx > -TEST)
	{
		mlx_pixel_put(fdf->basic.mlx, fdf->basic.win, cx + (x + TEST * j) + ((fdf->map.col - (i + 1)) * TEST) + 60, cy + (y + TEST * j) - 60 - ((fdf->map.col - 1) - i) * TEST, 0xFFFFFF);
		cy += ((ALTITUDE * 15) - 45) / 15.0;
		cx -= 1;
	}
	
	cx = 0;
	cy = 0;
	
	while (cx < TEST + 1)
	{
		mlx_pixel_put(fdf->basic.mlx, fdf->basic.win, cx + (x + TEST * j) + ((fdf->map.col - (i + 1)) * TEST), cy + (y + TEST * j) - 60 - ((fdf->map.col - 1) - i) * TEST, 0xFFFFFF);
		cy += ((ALTITUDE * 15) - 45) / 15.0;
		cx += 1;
	}
	
}


void print_cube(t_mlx *fdf, int x, int y, int i, int j)
{
			print_relief_corner(fdf, x, y + 10, i ,j);

}

void relief(t_mlx *fdf, int x, int y)
{
	int i = 0;
	int j;


	while (fdf->map.map[i] != NULL)
	{
		j = 0;
		while (fdf->map.map[i][j] != '\0')
		{
			if (fdf->map.map[i][j] != '0' && fdf->map.map[i][j] != 'c' && fdf->map.map[i][j] != '\n' && fdf->map.map[i][j] != 'r') // nul nul nul
			{
				if (test_corner(fdf->map.map, i, j))
					print_triangle(fdf, x, y, i, j);
				else if ((fdf->map.map[i][j + 1] == '1' || fdf->map.map[i][j - 1] == '1') && fdf->map.map[i + 1][j] != '1' && fdf->map.map[i - 1][j] != '1')
					print_raw(fdf, x, y, i, j);
				else if ((fdf->map.map[i + 1][j] == '1' || fdf->map.map[i - 1][j] == '1') && fdf->map.map[i][j + 1] != '1' && fdf->map.map[i][j - 1] != '1')
					print_col(fdf, x, y, i, j);
				else
					print_cube(fdf, x, y, i, j);
				
			}
			j++;
		}
		i++;
	}
	
	// print_relief(fdf, x , y);
				//square_put_pixel(fdf, (x + TEST * j) + ((fdf->map.col - (i + 1)) * TEST), (y + TEST * j) - (TEST * ALTITUDE) - ((fdf->map.col - 1) - i) * TEST, 0xFFFFFF);
}