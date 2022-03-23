/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minell <minell@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 23:11:25 by minell            #+#    #+#             */
/*   Updated: 2022/03/18 02:56:49 by minell           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	vardef(t_data *data)
{
	data->winwidth = 600;
	data->winhight = 600;
	data->depthmax = 50;
	data->zoom = 1;
	data->zoomx = 1;
	data->zoomy = 1;
	data->updown = 1;
	data->leftright = 1;
	data->mousex = 1;
	data->mousey = 1;
	data->moovepls = 1;
	data->color_f = 0xFFFFFF;
}

int	locmouse(int x, int y, t_data *data)
{
	if (x > 0 && x < data->winwidth && y > 0 && y < data->winhight
		&& data->moovepls == 1)
	{
		data->mousex = x;
		data->mousey = y;
		ft_draw(data);
	}
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	julia(t_data *data, int px, int py)
{
	double	x;
	double	y;
	double	temp;
	int		i;

	x = px * 0.0065 * data->zoom - 2 * data->zoomx * data->updown;
	y = py * 0.0065 * data->zoom - 2 * data->zoomy * data->leftright;
	i = 0;
	while (x * x + y * y <= 4 && i < data->depthmax)
	{
		temp = x * x - y * y - (0.5 * data->mousex / 300);
		y = 2 * x * y + (0.5 * data->mousey / 300);
		x = temp;
		data->i = x;
		data->j = y;
		i++;
	}
	return (i);
}

int	julia2(t_data *data, double xx, double yy)
{
	double	x;
	double	y;
	double	tmp;
	int		i;
	double	k;

	x = xx * 0.0065 * data->zoom - 2 * data->zoomx * data->updown;
	y = yy * 0.0065 * data->zoom - 2 * data->zoomy * data->leftright;
	i = 0;
	k = data->winwidth / 2;
	while (x * x + y * y <= 4 && i < data->depthmax)
	{
		tmp = x * x * x - 3 * x * y * y - (0.5 * data->mousex / k);
		y = 3 * x * x * y - y * y * y + (0.5 * data->mousey / k);
		x = tmp;
		data->i = x;
		data->j = y;
		i++;
	}
	return (i);
}
