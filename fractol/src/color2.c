/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minell <minell@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 23:11:25 by minell            #+#    #+#             */
/*   Updated: 2022/03/18 02:56:23 by minell           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_pal	*get_pal(void)
{
	static t_pal	tab[10];

	tab[0] = (t_pal){4, {0x000000, 0x5800FF, 0xE900FF, \
						0xFFC600,}};
	tab[1] = (t_pal){5, {0x000000, 0x4A308C, 0x00ffa6, 0x7C50EB, \
						0xD49D8E}};
	tab[2] = (t_pal){5, {0x7F1637, 0x047878, 0xFFB733, 0xF57336, \
						0xC22121, 0x334756}};
	tab[3] = (t_pal){5, {0x0107F5, 0xF7BB05, 0xFAE76E, \
						0xFADE9E, 0xE4F5F7,}};
	tab[4] = (t_pal){5, {0x490085, 0x720D8F, 0xFF6590, \
						0xFF9590, 0xFFCFED, 0x6A2448}};
	tab[5] = (t_pal){5, {0x03045E, 0x0077B6, 0x00B4D8, \
						0x90E0EF, 0xCAF0F8,}};
	tab[6] = (t_pal){5, {0x562135, 0xC3829E, 0xE9B1CD, \
						0xFFE7DE, 0xFCD1D7,}};
	tab[7] = (t_pal){5, {0x0006FA, 0xBF5F201, 0xB9D9B4, \
						0xF2DF7E, 0xF2B591,}};
	return (tab);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->buf + (int)(y * data->line_length + x
			* (data->bits_pixel * 0.125));
	*(unsigned int *)dst = color;
}

int	lerp(int v0, int v1, double p)
{
	return ((int)((double)v0 + (v1 - v0) * p));
}
