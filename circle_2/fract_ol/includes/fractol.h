/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 10:52:53 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/18 19:13:19 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define W_WIDTH 800
# define W_HEIGHT 600
# define ITER_MAX 100
# define ZOOM 1.5f
# define MOVE 200.0f

typedef struct structure_img{
	void		*img_ptr;
	char		*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct viewpoint_structure
{
	double	xmin;
	double	xmax;
	double	ymin;
	double	ymax;
	double	zoom;
	double	offx;
	double	offy;
}			t_viewpoint;

typedef struct structure_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_viewpoint	*vp;
	char		*fractol;
}				t_mlx;

typedef struct count_x_y
{
	int		i;
	int		j;
}	t_count;

typedef struct s_complex
{
	double		re;
	double		im;
}				t_complex;

int			hook_keydown(int key, t_mlx *mlx);
void		zoom(int x, int y, t_mlx *mlx, double z);
void		render(t_mlx *mlx);
void		move(int x, int y, t_mlx *mlx, char option);
t_complex	screen_to_complex(int count_x, int count_y, t_viewpoint *vp);

#endif