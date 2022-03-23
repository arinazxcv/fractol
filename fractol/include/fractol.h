/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minell <minell@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 23:11:25 by minell            #+#    #+#             */
/*   Updated: 2022/03/18 03:06:57 by minell           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include	<stdlib.h>
# include "../mlx/mlx.h"
# include <stdlib.h>
# include <math.h>
# include <unistd.h>

typedef unsigned char	t_char;

typedef struct s_pal
{
	t_char		count;
	int			colors[16];
}						t_pal;

typedef struct s_rgba
{
	t_char	r;
	t_char	g;
	t_char	b;
	t_char	a;
}	t_rgba;

typedef union s_color {
	t_rgba	rgba;
	int		value;
}	t_color;

typedef struct s_complex
{
	double		r;
	double		i;
}					t_complex;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*buf;
	int				bits_pixel;
	int				line_length;
	int				endian;
	int				winwidth;
	int				winhight;
	int				mousex;
	int				mousey;
	int				depthmax;
	double			leftright;
	double			updown;
	double			zoom;
	double			zoomx;
	double			zoomy;
	double			i;
	double			j;
	int				frachoice;
	int				moovepls;
	t_pal			*pal;
	int				color_f;
}				t_data;

void	ft_color(t_data *v, int x, int y, int iter);
t_color	smooth(t_data *d, int iter);
t_color	linear_color(double i, int max, t_pal *pal);
t_color	color_lerp(t_color col1, t_color col2, double p);
int		lerp(int v0, int v1, double p);
t_pal	*get_pal(void);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		key_hook(int keycode, t_data *data);
int		key_hook2(int keycode, t_data *data);
int		closewin(t_data *data);
int		mouse_hook(int keycode, int x, int y, t_data *data);
void	vardef(t_data *data);
int		ft_frachoice(int argc, char **argv, t_data *data);
int		ft_draw(t_data *data);
int		norm(t_data *data, int x, int y);
int		mandelbrot2(t_data *data, int px, int py);
int		mandelbrot1(t_data *data, int px, int py);
int		mandelbrot(t_data *data, int px, int py);
int		mandelbrot_naoborot(t_data *data, int px, int py);
int		locmouse(int x, int y, t_data *data);
int		ft_strcmp(const char *s1, const char *s2);
int		julia(t_data *data, int px, int py);
int		julia2(t_data *data, double xx, double yy);

#endif