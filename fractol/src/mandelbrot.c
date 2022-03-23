/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minell <minell@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 23:11:25 by minell            #+#    #+#             */
/*   Updated: 2022/03/18 02:59:24 by minell           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	norm(t_data *data, int x, int y)
{
	double	xx;
	double	yy;
	double	p1;
	double	p2;

	xx = (x * 0.005 * data->zoom - 2 * data->updown * data->zoomx);
	yy = (-y * 0.005 * data->zoom + 1.5 * data->leftright * data->zoomy);
	if (xx * xx + yy * yy <= 0.25 && xx <= 0)
		return (1);
	if (yy >= 2 * xx - 0.5 && yy <= -2 * xx + 0. && xx >= 0)
		return (1);
	if ((xx + 1) * (xx + 1) + yy * yy <= 0.0625)
		return (1);
	p1 = (xx - 0.25) * (xx - 0.25) + yy * yy;
	p2 = 0.5 - 0.5 * cos(atan2(yy, xx - 0.25));
	if (p1 <= p2 * p2)
		return (1);
	return (0);
}

int	mandelbrot2(t_data *data, int px, int py)
{
	double	x;
	double	y;
	double	tmp;
	int		i;

	x = 0;
	y = 0;
	i = 0;
	while (x * x + y * y <= 4 && i < data->depthmax)
	{
		tmp = x * x * x - 3 * x * y * y + (px * 0.005 * data->zoom
				- 1.5 * data->updown * data->zoomx);
		y = 3 * x * x * y - y * y * y + (py * 0.005 * data->zoom
				- 1.5 * data->leftright * data->zoomy);
		x = tmp;
		data->i = x;
		data->j = y;
		i++;
	}
	return (i);
}

int	mandelbrot(t_data *data, int px, int py)
{
	double	x;
	double	y;
	double	temp;
	int		i;

	x = 0;
	y = 0;
	i = 0;
	if (norm(data, px, py))
		return (data->depthmax);
	while (x * x + y * y <= 4 && i < data->depthmax)
	{
		temp = x * x - y * y + (px * 0.005 * data->zoom
				- 2 * data->zoomx * data->updown);
		y = 2 * x * y + (py * 0.005 * data->zoom
				- 1.5 * data->zoomy * data->leftright);
		x = temp;
		data->i = x;
		data->j = y;
		i++;
	}
	return (i);
}

int	mandelbrot_naoborot(t_data *data, int px, int py)
{
	double	x;
	double	y;
	double	temp;
	int		i;

	x = 0;
	y = 0;
	i = 0;
	while (x * x + y * y <= 4 && i < data->depthmax)
	{
		temp = x * x - y * y - (px * 0.005 * data->zoom
				- 1 * data->zoomx * data->updown);
		y = 2 * x * y + (py * 0.005 * data->zoom
				- 1.5 * data->zoomy * data->leftright);
		x = temp;
		data->i = x;
		data->j = y;
		i++;
	}
	return (i);
}

int	mandelbrot1(t_data *data, int px, int py)
{
	double	x;
	double	y;
	double	temp;
	int		i;

	x = 0;
	y = 0;
	i = 0;
	while (x * x + y * y <= 4 && i < data->depthmax)
	{
		temp = x * x * x * x - 6 * y * y * x * x + \
				y * y * y * y + (px * 0.005 * data->zoom
				- 1.6 * data->zoomx * data->updown);
		y = 4 * x * x * x * y - 4 * y * y * y * x + (py * 0.005 * data->zoom
				- 1.5 * data->zoomy * data->leftright);
		x = temp;
		data->i = x;
		data->j = y;
		i++;
	}
	return (i);
}
