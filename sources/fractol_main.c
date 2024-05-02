/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoster <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:50:20 by mkoster           #+#    #+#             */
/*   Updated: 2024/04/24 18:34:39 by mkoster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	int	off;

	off = (y * data->line_len) + (x * (data->bpp / 8));
	*(unsigned int *)(data->pixels_ptr + off) = color;
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
		|| (argc == 4 && !ft_strncmp(argv[1], "julia", 5))
		|| (argc == 2 && !ft_strncmp(argv[1], "burning_ship", 12))
		|| (argc == 2 && !ft_strncmp(argv[1], "cubic", 5))
		|| (argc == 2 && !ft_strncmp(argv[1], "nova", 4)))
	{
		if (argc == 4 && !ft_strncmp(argv[1], "julia", 5))
			check_error_julia(argv);
		ft_init_mandelbrot(&fractal);
		init_fractal(&fractal, argv, argc);
		render_mandelbrot(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, 2);
		return (1);
	}
	return (0);
}
