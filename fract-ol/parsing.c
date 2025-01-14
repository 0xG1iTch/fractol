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

static int	ft_strcmp(char *str1, char *str2)
{
	while (*str1 == *str2 && *str1)
	{
		++str1;
		++str2;
	}
	return (*str1 - *str2);
}

static double	ft_atof(const char *str)
{
	double	result;
	double	fraction;
	int		sign;
	int		divisor;

	(1) && (result = 0.0, fraction = 0.0, sign = 1, divisor = 1);
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str++ == '-')
			sign = -1;
	}
	while (*str >= '0' && *str <= '9')
		result = result * 10 + (*str++ - '0');
	if (*str == '.')
	{
		while (*++str >= '0' && *str <= '9')
		{
			fraction = fraction * 10 + (*str - '0');
			divisor *= 10;
		}
		result += fraction / divisor;
	}
	return (result * sign);
}

int	 parse_arguments(int argc, char **argv, t_data *data)
{
	if (argc < 2)
		return (0);
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
		data->fractal_type = MANDELBROT;
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
