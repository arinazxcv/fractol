/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minell <minell@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 23:11:25 by minell            #+#    #+#             */
/*   Updated: 2022/03/18 02:39:47 by minell           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	closewin(t_data *data)
{
	mlx_destroy_image(data->mlx, data->win);
	exit(EXIT_SUCCESS);
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_data *data)
{
	if (keycode == 4)
	{
		data->zoom -= 0.15 * data->zoom;
		data->zoomx -= 0.15 * x / 300 * data->zoom;
		data->zoomy -= 0.15 * y / 300 * data->zoom;
		data->depthmax += 2;
	}
	if (keycode == 5 && data->zoom < 5)
	{
		data->zoom += 0.15 * data->zoom;
		data->zoomx += 0.15 * x / 300 * data->zoom;
		data->zoomy += 0.15 * y / 300 * data->zoom;
		data->depthmax -= 2;
	}
	ft_draw(data);
	return (0);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
		closewin(data);
	if (keycode >= 18 && keycode <= 23)
		data->pal = &get_pal()[keycode - 18];
	if (keycode == 123)
		data->updown += data->zoom;
	if (keycode == 126)
		data->leftright += data->zoom;
	if (keycode == 124)
		data->updown -= data->zoom;
	if (keycode == 125)
		data->leftright -= data->zoom;
	if (keycode == 49)
		vardef(data);
	if (keycode == 69)
		data->depthmax *= 2;
	if (keycode == 78 && data->depthmax >= 50)
		data->depthmax /= 2;
	if (keycode == 35 && data->moovepls == 1)
		data->moovepls = 0;
	else if (keycode == 35 && data->moovepls == 0)
		data->moovepls = 1;
	return (ft_draw(data));
}
