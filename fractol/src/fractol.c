/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minell <minell@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 23:11:25 by minell            #+#    #+#             */
/*   Updated: 2022/03/18 02:59:56 by minell           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_if_frac(t_data *data, int x, int y)
{
	if (data->frachoice == 1)
		ft_color(data, x, y, mandelbrot(data, x, y));
	if (data->frachoice == 2)
		ft_color(data, x, y, mandelbrot_naoborot(data, x, y));
	if (data->frachoice == 3)
		ft_color(data, x, y, mandelbrot2(data, x, y));
	if (data->frachoice == 4)
		ft_color(data, x, y, mandelbrot1(data, x, y));
	if (data->frachoice == 5)
		ft_color(data, x, y, julia(data, x, y));
	if (data->frachoice == 6)
		ft_color(data, x, y, julia2(data, x, y));
}

int	ft_draw(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < data->winwidth)
	{
		y = 0;
		while (y < data->winhight)
		{
			ft_if_frac(data, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

int	ft_write(int a)
{
	if (a == 1)
		write(1, "\033[1;35mChoose fractal\n \
- mandelbrot\n \
- mandelbrot_naoborot\n \
- mandelbrot1\n \
- mandelbrot2\n \
- julia\n \
- julia1\n", 109);
	if (a == 2)
		write(1, "\033[1;35mChoose  the right fractal\n \
- mandelbrot\n \
- mandelbrot_naoborot\n - mandelbrot1\n \
- mandelbrot2\n - julia\n \
- julia1\n", 119);
	if (a == 3)
		write(1, "\033[1;36m	Manual:\n move: strelochki\n \
max iter: + / -\n pause: p\n restart: space\n\n", 78);
	return (1);
}

int	ft_frachoice(int argc, char **argv, t_data *data)
{
	ft_write(3);
	if (argc < 2)
		exit(ft_write(1));
	if (!ft_strcmp(argv[1], "mandelbrot"))
		data->frachoice = 1;
	else if (!ft_strcmp(argv[1], "mandelbrot_naoborot"))
		data->frachoice = 2;
	else if (!ft_strcmp(argv[1], "mandelbrot1"))
		data->frachoice = 3;
	else if (!ft_strcmp(argv[1], "mandelbrot2"))
		data->frachoice = 4;
	else if (!ft_strcmp(argv[1], "julia"))
		data->frachoice = 5;
	else if (!ft_strcmp(argv[1], "julia1"))
		data->frachoice = 6;
	else
		exit(ft_write(2));
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	ft_frachoice(argc, argv, &data);
	data.mlx = mlx_init();
	vardef(&data);
	data.pal = &get_pal()[0];
	data.win = mlx_new_window(data.mlx, data.winwidth, \
		data.winhight, "minell's fractol");
	data.img = mlx_new_image(data.mlx, data.winwidth, data.winhight);
	data.buf = mlx_get_data_addr(data.img, &data.bits_pixel, \
		&data.line_length, &data.endian);
	ft_draw(&data);
	mlx_hook(data.win, 06, 1L << 6, locmouse, &data);
	mlx_hook(data.win, 17, 1l << 2, closewin, &data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_mouse_hook(data.win, mouse_hook, &data);
	mlx_loop(data.mlx);
}
