/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamm <mel-hamm@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-12 22:14:53 by mel-hamm          #+#    #+#             */
/*   Updated: 2025-01-12 22:14:53 by mel-hamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

static int	ft_strcmp(char *str1, char *str2)
{
	while (*str1 == *str2 && *str1)
	{
		++str1;
		++str2;
	}
	return (*str1 - *str2);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	is_float(char *str)
{
	int	i;
	int	float_flag;

	(1) && (i = 0, float_flag = 0);
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '.')
		return (0);
	while (str[i])
	{
		if ((str[i] == '+' || str [i] == '-')
			|| (str[i] == '.' && float_flag == 1))
			return (0);
		if (str[i] == '.')
			float_flag = 1;
		if (!ft_isdigit(str[i]) && str[i] != '.')
			return (0);
		i++;
	}
	return (1);
}

static double	ft_atof(char *str)
{
	double	result;
	double	fraction;
	int		sign;
	int		divisor;
	int		i;

	if (!is_float(str))
		print_usage();
	(1) && (result = 0.0, fraction = 0.0, sign = 1, divisor = 1, i = 0);
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + (str[i++] - '0');
	if (str[i] == '.')
	{
		while (str[++i] >= '0' && str[i] <= '9')
			(1) && (fraction = fraction * 10 + (str[i] - '0'), divisor *= 10);
		result += fraction / divisor;
	}
	return (result * sign);
}

int	parse_arguments(int argc, char **argv, t_data *data)
{
	if (argc < 2)
		return (0);
	if (ft_strcmp(argv[1], "mandelbrot") == 0 && argc == 2)
		data->fractal_type = MANDELBROT;
	else if (ft_strcmp(argv[1], "burning_ship") == 0 && argc == 2)
		data->fractal_type = BURNING_SHIP;
	else if (ft_strcmp(argv[1], "julia") == 0 && argc == 4)
	{
		data->fractal_type = JULIA;
		data->julia_param.real = ft_atof(argv[2]);
		data->julia_param.imag = ft_atof(argv[3]);
	}
	else
		return (0);
	data->zoom = 0.005;
	data->center.real = 0;
	data->center.imag = 0;
	data->max_iter = 100;
	return (1);
}
