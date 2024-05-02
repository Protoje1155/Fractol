/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mandelbrot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoster <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:50:34 by mkoster           #+#    #+#             */
/*   Updated: 2024/04/24 18:34:27 by mkoster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	render_mandelbrot(t_fractal *fractal)
{
	int	y;
	int	x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mandelbrot(fractal, y, x);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx_connection,
		fractal->mlx_window, fractal->img.img_ptr, 0, 0);
}

void	mandelbrot(t_fractal *fractal, int i, int y)
{
	t_complex	z;
	t_complex	c;
	int			x;

	init_complex_c(fractal, &c, y, i);
	init_complex_z(fractal, &z, y, i);
	x = -1;
	while (++x < fractal->iterations)
	{
		z = calc_z(fractal, z, c);
		if (calc_hypotenuse(z) > 2)
		{
			color_calc(fractal, x);
			my_mlx_pixel_put(&fractal->img, y, i, fractal->color);
			return ;
		}
	}
	my_mlx_pixel_put(&fractal->img, y, i, BLACK);
}

t_complex	calc_z(t_fractal *fractal, t_complex z, t_complex c)
{
	int	i;

	i = -1;
	if ((fractal->id == 1)
		|| (fractal->id == 0))
		z = complex_sum(complex_sqr(z), c);
	else if (fractal->id == 2)
		z = complex_sum(complex_sqr_abs(z), c);
	else if (fractal->id == 3)
		z = complex_sum(complex_cubic(z), c);
	else if (fractal->id == 4)
		z = complex_sum(complex_sum(complex_div(c, z), complex_cubic(z)), c);
	return (z);
}
