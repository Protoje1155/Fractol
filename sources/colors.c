/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoster <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:06:13 by mkoster           #+#    #+#             */
/*   Updated: 2024/04/24 16:59:26 by mkoster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	color_calc(t_fractal *fractal, int x)
{
	int hue;
	int	conv = 10;
	hue = 255 * x / fractal->iterations;
	if (x <= conv)
	{
		fractal->color = scale_func(x, fractal->color_l,
			fractal->color_r, fractal->iterations);
	}
	else if (x > conv && x <= conv * 2)
	{
		fractal->color = scale_func(x, 2 * fractal->color_r,
			fractal->color_l * 2 , fractal->iterations);
	}
	else if (x > conv * 2 && x <= conv *3)
	{
	 	fractal->color = scale_func(x,  2.5 * fractal->color_r,
			fractal->color_l * 2.5 , fractal->iterations);
	}
	else if (x > conv * 3 && x <= conv * 4)
	{
		fractal->color = scale_func(x,  fractal->color_r/3,
                        fractal->color_l/3 , fractal->iterations);
	}
	else
	{
		fractal->color = scale_func(x, fractal->color_l,
			fractal->color_r, fractal->iterations);
	}

}
