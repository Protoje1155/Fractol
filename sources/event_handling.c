/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoster <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:50:48 by mkoster           #+#    #+#             */
/*   Updated: 2024/04/25 13:32:56 by mkoster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_close(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}

int	key_handling(int keycode, t_fractal *fractal)
{
	if (keycode == 65307)
		ft_close(fractal);
	if (keycode == 65361)
		fractal->shift_x -= (0.5 * fractal->zoom);
	if (keycode == 65363)
		fractal->shift_x += (0.5 * fractal->zoom);
	if (keycode == 65362 && (fractal->id != 2))
		fractal->shift_y += (0.5 * fractal->zoom);
	if (keycode == 65364 && (fractal->id != 2))
		fractal->shift_y -= (0.5 * fractal->zoom);
	if (keycode == 65362 && (fractal->id == 2))
		fractal->shift_y -= (0.5 * fractal->zoom);
	if (keycode == 65364 && (fractal->id == 2))
		fractal->shift_y += (0.5 * fractal->zoom);
	if (keycode == 65451)
		fractal->iterations += 20;
	if (keycode == 65453)
		fractal->iterations -= 20;
	if (keycode == 99)
	{
		fractal->color_r *= 3;
		fractal->color_l = fractal->color_r + 400;
	}
	render_mandelbrot(fractal);
	return (0);
}

int	mouse_handling(int button, int x, int y, t_fractal *fractal)
{
	t_complex	a;

	a = zoom_calc(fractal, x, y);
	if (button == 4)
	{
		fractal->zoom *= 0.95;
		fractal->shift_x += (a.real * 0.2 * fractal->zoom);
		fractal->shift_y += (a.img * 0.2 * fractal->zoom);
	}
	if (button == 5)
	{
		fractal->zoom *= 1.05;
		fractal->shift_x += (a.real * 0.2 * fractal->zoom);
		fractal->shift_y += (a.img * 0.2 * fractal->zoom);
	}
	render_mandelbrot(fractal);
	return (0);
}

int	close_handling(t_fractal *fractal)
{
	ft_close(fractal);
	return (0);
}

t_complex	zoom_calc(t_fractal *fractal, int x, int y)
{
	t_complex	a;

	if ((fractal->id == 0)
		|| (fractal->id == 1)
		|| (fractal->id == 3)
		|| (fractal->id == 4))
	{
		a.real = scale_func(x, -2, 2, WIDTH);
		a.img = scale_func(y, 2, -2, HEIGHT);
	}
	else if (fractal->id == 2)
	{
		a.real = scale_func(x, -2, 2, WIDTH);
		a.img = scale_func(y, -2, 2, HEIGHT);
	}
	return (a);
}
