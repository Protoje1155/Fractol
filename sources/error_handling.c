/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoster <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:50:14 by mkoster           #+#    #+#             */
/*   Updated: 2024/04/24 15:50:15 by mkoster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	check_error_julia(char **argv)
{
	int	error;

	error = 1;
	error *= check_arg(argv[2]);
	error *= check_arg(argv[3]);
	if (error == 0)
	{
		ft_putstr_fd(ERROR_MESSAGE, 2);
		exit(EXIT_FAILURE);
	}
}

int	check_arg(char *s)
{
	int	i;

	i = 0;
	if (s[i] && (s[i] == '+' || s[i] == '-'))
		i++;
	while (s[i] && (s[i] >= '0' && s[i] <= '9'))
		i++;
	if (s[i] == '.')
		i++;
	while (s[i] && (s[i] >= '0' && s[i] <= '9'))
		i++;
	if (s[i] == '\0')
		return (1);
	else
		return (0);
}

double	str_to_double(char *s)
{
	double	res;
	double	power;
	int		sign;

	res = 0;
	power = 1;
	sign = 1;
	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	else if (*s == '+')
		s++;
	while (*s && *s != '.')
		res = res * 10 + (*s++ - '0');
	if (*s == '.')
		s++;
	while (*s)
	{
		res = res * 10 + (*s++ - '0');
		power *= 0.1;
	}
	return (res * sign * power);
}
