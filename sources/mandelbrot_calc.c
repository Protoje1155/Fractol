/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_calc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoster <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:50:27 by mkoster           #+#    #+#             */
/*   Updated: 2024/04/24 15:50:28 by mkoster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_complex	complex_sum(t_complex a, t_complex b)
{
	t_complex	sum;

	sum.real = a.real + b.real;
	sum.img = a.img + b.img;
	return (sum);
}

t_complex	complex_sqr(t_complex a)
{
	t_complex	sum;

	sum.real = (a.real * a.real) - (a.img * a.img);
	sum.img = 2 * a.real * a.img;
	return (sum);
}

double	calc_hypotenuse(t_complex a)
{
	return (sqrt((pow(a.real, 2) + pow(a.img, 2))));
}

double	scale_func(double num, double new_mn, double new_mx, double old_mx)
{
	return ((new_mx - new_mn) * num / old_mx + new_mn);
}

t_complex	complex_sqr_abs(t_complex z)
{
	t_complex	res;
	t_complex	temp;

	temp.real = fabs(z.real);
	temp.img = fabs(z.img);
	res.real = (temp.real * temp.real) - (temp.img * temp.img);
	res.img = 2 * temp.real * temp.img;
	return (res);
}
