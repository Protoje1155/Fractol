/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoster <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:50:41 by mkoster           #+#    #+#             */
/*   Updated: 2024/04/24 18:33:56 by mkoster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_init_mandelbrot(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (fractal->mlx_connection == NULL)
		exit(EXIT_FAILURE);
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection,
			WIDTH, HEIGHT, "Fractol");
	if (fractal->mlx_window == NULL)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		exit(EXIT_FAILURE);
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection,
			WIDTH, HEIGHT);
	if (fractal->img.img_ptr == NULL)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		exit(EXIT_FAILURE);
	}
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
	mlx_hook(fractal->mlx_window, 2, 1L << 0, key_handling, fractal);
	mlx_hook(fractal->mlx_window, 17, 0L, close_handling, fractal);
	mlx_hook(fractal->mlx_window, 4, 1L << 2, mouse_handling, fractal);
}

void	init_fractal(t_fractal *fractal, char **argv, int argc)
{
	fractal->iterations = 30;
	fractal->shift_x = 0;
	fractal->shift_y = 0;
	fractal->zoom = 1;
	fractal->color_l = 500;
	fractal->color_r = 100;
	if (!ft_strncmp(argv[1], "julia", 5))
	{
		fractal->julia_x = str_to_double(argv[2]);
		fractal->julia_y = str_to_double(argv[3]);
		fractal->id = 1;
	}
	else if (!ft_strncmp(argv[1], "mandelbrot", 10))
		fractal->id = 0;
	else if (!ft_strncmp(argv[1], "burning_ship", 12))
		fractal->id = 2;
	else if (!ft_strncmp(argv[1], "cubic", 5))
		fractal->id = 3;
	else if (!ft_strncmp(argv[1], "nova", 4))
		fractal->id = 4;
}

void	init_complex_c(t_fractal *fractal, t_complex *c, int y, int i)
{
	if (fractal->id == 1)
	{
		c->real = fractal->julia_x;
		c->img = fractal->julia_y;
	}
	else if ((fractal->id == 0)
		|| (fractal->id == 3)
			|| (fractal->id == 4))
	{
		c->real = scale_func(y, -2, 2, WIDTH)
			* fractal->zoom + fractal->shift_x;
		c->img = scale_func(i, 2, -2, HEIGHT)
			* fractal->zoom + fractal->shift_y;
	}
	else if (fractal->id == 2)
	{
		c->real = scale_func(y, -2, 2, WIDTH)
			* fractal->zoom + fractal->shift_x;
		c->img = scale_func(i, -2, 2, HEIGHT)
			* fractal->zoom + fractal->shift_y;
	}
}

void	init_complex_z(t_fractal *fractal, t_complex *z, int y, int i)
{
	if ((fractal->id == 1)
		|| (fractal->id == 4))
	{
		z->real = scale_func(y, -2, 2, WIDTH)
			* fractal->zoom + fractal->shift_x;
		z->img = scale_func(i, 2, -2, HEIGHT)
			* fractal->zoom + fractal->shift_y;
	}
	else if ((fractal->id == 0)
		|| (fractal->id == 2)
		|| (fractal->id == 3))
	{
		z->real = 0;
		z->img = 0;
	}
}
