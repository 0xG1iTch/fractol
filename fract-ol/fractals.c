/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamm <mel-hamm@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-14 00:49:39 by mel-hamm          #+#    #+#             */
/*   Updated: 2025-01-14 00:49:39 by mel-hamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_complex c, int max_iter)
{
	t_complex	z;
	int			iter;
	double		temp;

	(1) && (iter = 0, z.imag = 0, z.real = 0);
	while (z.real * z.real + z.imag * z.imag <= 4 && iter < max_iter)
	{
		temp = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2 * z.real * z.imag + c.imag;
		z.real = temp;
		iter++;
	}
	return (iter);
}

int	julia(t_complex z, t_complex c, int max_iter)
{
	int		iter;
	double	temp;

	iter = 0;
	while (z.real * z.real + z.imag * z.imag <= 4 && iter < max_iter)
	{
		temp = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2 * z.real * z.imag + c.imag;
		z.real = temp;
		iter++;
	}
	return (iter);
}
