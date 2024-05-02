/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton_calc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoster <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:32:11 by mkoster           #+#    #+#             */
/*   Updated: 2024/04/24 18:24:38 by mkoster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_complex	complex_div(t_complex z1, t_complex z2)
{
	t_complex	res;
	t_complex	num;
	t_complex	den;

	num.real = z1.real * z2.real + z1.img * z2.img;
	num.img = z1.img * z2.real - z1.real * z2.img;
	den.real = z2.real * z2.real + z2.img * z2.img;
	den.img = 0;
	res.real = num.real / den.real;
	res.img = num.img / den.real;
	return (res);
}

t_complex	complex_cubic(t_complex a)
{
	t_complex	res;

	res.real = pow(a.real, 3) - 3 * a.real * pow(a.img, 2);
	res.img = -(pow(a.img, 3)) + 3 * pow(a.real, 2) * a.img;
	return (res);
}

t_complex	complex_mult(t_complex a, double b)
{
	a.real = a.real * b;
	a.img = a.img * b;
	return (a);
}

t_complex	complex_minus(t_complex a)
{
	t_complex	b;

	b.real = -a.real;
	b.img = -a.img;
	return (b);
}
