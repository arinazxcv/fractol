/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minell <minell@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 23:11:25 by minell            #+#    #+#             */
/*   Updated: 2022/03/18 02:55:50 by minell           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_color	color_lerp(t_color col1, t_color col2, double p)
{
	t_color	col;

	if (col1.value == col2.value)
		return (col1);
	col.rgba.r = lerp((int)col1.rgba.r, (int)col2.rgba.r, p);
	col.rgba.g = lerp((int)col1.rgba.g, (int)col2.rgba.g, p);
	col.rgba.b = lerp((int)col1.rgba.b, (int)col2.rgba.b, p);
	col.rgba.a = 0x00;
	return (col);
}

t_color	linear_color(double i, int max, t_pal *pal)
{
	double		index;
	double		p;
	int			c;

	index = i / max;
	c = pal->count - 1;
	p = fmod(index, 1.0f / c) * c;
	return (color_lerp((t_color)(pal->colors[(int)(index * c) + 1]),
						(t_color)(pal->colors[(int)(index * c)]), 1.0f - p));
}

t_color	smooth(t_data *d, int iter)
{
	double	new_i;
	double	smooth;

	smooth = log(d->i * d->i + d->j * d->j) / 2.0f;
	new_i = (double) iter + (1 - (log(smooth / log(2)) / log(2)));
	if (new_i < 0)
		new_i = 0;
	return (linear_color(new_i, d->depthmax, d->pal));
}

void	ft_color(t_data *v, int x, int y, int iter)
{
	double	k;
	int		color;

	k = iter;
	if (iter != v->depthmax)
		color = smooth(v, iter).value;
	else
	{
		color = v->color_f;
	}
	my_mlx_pixel_put(v, x, y, color);
}
