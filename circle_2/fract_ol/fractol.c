/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 10:44:26 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/18 19:45:08 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include "mlx.h"
#include <math.h>


int	input_check(int ac, const char **av)
{
	if (ac != 2)
	{
		ft_putstr("input : [mandelbrot] / [julia]\n");
		return (0);
	}
	if (!ft_strcmp(av[1], "mandelbrot") && !ft_strcmp(av[1], "julia"))
	{
		ft_putstr("input : [mandelbrot] / [julia]\n");
		return (0);
	}
	return (1);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = (img->data) + (x * img->bpp / 8) + (y * img->size_l);
	*(unsigned int *)dst = color;
}

int		color_set(int iter)
{
	double	r;
	double	g;
	double	b;
	int		color;

	r = sin(0.3 * (double)iter);
	g = sin(0.3 * (double)iter + 3) * 127 + 128;
	b = sin(0.3 * (double)iter + 3) * 127 + 128;
	color = ((int)(255.999 * r) << 16) + ((int)(255.999 * g) << 8) + ((int)(255.999 * b));
	return (color);
}

int		julia(t_count count, int iter, t_viewpoint *vp)
{
	t_complex	z;
	double	c_re;
	double	c_im;
	double	x;
	double	x_new;
	double	y;

	c_re = -1;
	c_im = 0;
	// x = ((count.i - W_WIDTH / 2) * 4.0 / W_WIDTH);
	// y = ((W_HEIGHT / 2) - count.j) * 4.0 / W_HEIGHT;
	z = screen_to_complex(count.i, count.j, vp);
	x = z.re;
	y = z.im;
	while ((x * x + y * y < 4) && (iter < ITER_MAX))
	{
		x_new = x * x - y * y + c_re;
		y = 2 * x * y + c_im;
		x = x_new;
		iter++;
	}
	return (iter);
}

int	mandelbrot(t_count count, int iter, t_viewpoint *vp)
{
	t_complex	c;
	double		x;
	double		x_new;
	double		y;

	c = screen_to_complex(count.i, count.j, vp);
	x = 0;
	y = 0;
	while ((x * x + y * y < 4) && (iter < ITER_MAX))
	{
		x_new = x * x - y * y + c.re;
		y = 2 * x * y + c.im;
		x = x_new;
		iter++;
	}
	return (iter);
}


void	render(t_mlx *mlx)
{
	t_img	img;
	int		iter;
	int		color;
	t_count	c;

	img = mlx->img;
	c.i = -1;
	while (++c.i < W_WIDTH)
	{
		c.j = -1;
		while (++c.j < W_HEIGHT)
		{
			//iter = mandelbrot(c, 0, mlx->vp);
			iter = julia(c, 0, mlx->vp);
			if (iter < ITER_MAX)
			{
				color = color_set(iter);//0x00FFFFFF
				my_mlx_pixel_put(&img, c.i, c.j, color);
			}
            else
				my_mlx_pixel_put(&img, c.i, c.j, 0x00000000);			
		}		
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, (mlx->img.img_ptr), 0, 0);
}

t_img	*del_image(t_mlx *mlx, t_img *img)
{
	if (img)
	{
		if (img->img_ptr)
			mlx_destroy_image(mlx->mlx_ptr, img->img_ptr);
		free(img);
		img = 0;
	}
	return (0);
}

t_img	new_image(t_mlx *mlx)
{	
	t_img	img;

	// img = malloc(sizeof(t_img));
	// if (!img)
	// 	return (0);
	img.img_ptr = mlx_new_image(mlx->mlx_ptr, W_WIDTH, W_HEIGHT);
	// if (!img.img_ptr)
	// 	return (del_image(mlx, img));
	img.data = mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_l,
			&img.endian);
	return (img);
}

t_mlx	*mlx_structure_init(t_mlx *mlx)
{
	t_img	*img;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return (0);
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return (0);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, W_WIDTH, W_HEIGHT, "fractol");
	if (!mlx->win_ptr)
		return (0);
	mlx->vp = malloc(sizeof(t_viewpoint));
	if (!mlx->vp)
		return (0);
	return (mlx);
}

void		viewport_fit(t_viewpoint *v)
{
	double w;
	double h;

	w = v->xmax - v->xmin;
	h = v->ymax - v->ymin;
	if (w / h >= (float)W_WIDTH / W_HEIGHT)
	{
		v->ymin = -(w * W_HEIGHT / W_WIDTH / 2);
		v->ymax = w * W_HEIGHT / W_WIDTH / 2;
	}
	else
	{
		v->xmin = -(h * W_WIDTH / W_HEIGHT / 2);
		v->xmax = (h * W_WIDTH / W_HEIGHT / 2);
	}
}
#include <stdio.h>
t_viewpoint *init_viewpoint(t_viewpoint *vp)
{
	vp->offx = 0.0f;
	vp->offy = 0.3f;
	vp->xmax = 1.0f;
	vp->xmin = -2.5f;
	vp->ymax = 1.0f;
	vp->ymin = -1.0f;
	vp->zoom = 1.0f;
	viewport_fit(vp);
	
	//printf("vp->xmax : %f\n", vp->xmax);
	return (vp);
}

t_mlx	*init_mlx(void)
{
	t_mlx	*mlx;

	mlx = mlx_structure_init(mlx);
	if (!mlx)
		return (0);
	mlx->img = new_image(mlx);
	ft_putstr("init_mlx \n");
	mlx->vp = init_viewpoint(mlx->vp);
	ft_putstr("init_mlx \n");
	// if (!mlx->img)
	// 	return (0);
	return (mlx);
}

int hook_mousedown(int button, int x, int y, t_mlx *mlx)
{
	printf("button_num: %d , press at %dx%d\n", button, x, y);
	if (button == 4)
	{
		zoom(x, W_HEIGHT - y, mlx, 1 / ZOOM);
		render(mlx);
	}
	else if (button == 5)
	{
		zoom(x, W_HEIGHT - y, mlx, ZOOM);
		render(mlx);
	}

	return (0);
}
int hook_mouseup(int button, int x, int y, t_mlx *mlx)
{
	printf("mouseup!!!!! button_num: %d , press at %dx%d\n", button, x, y);	
	// zoom(x,y, mlx, ZOOM);
	return (0);
}

int	main(int ac, const char **av)
{
	t_mlx		*mlx;
	t_viewpoint	*vp;

	if (!input_check(ac, av))
		return (0);
	mlx = init_mlx();
	render(mlx);
	//mlx_hook(mlx->win_ptr, 4, 0, ft_mouse_press, 0); //클릭
	mlx_key_hook(mlx->win_ptr, hook_keydown, mlx); 
	mlx_hook(mlx->win_ptr, 4, 0, hook_mousedown, mlx); //1L << 2
	//mlx_hook(mlx->win_ptr, 5, 0, hook_mouseup, mlx); //1L << 3
	//mlx_hook(mlx->window, 6, 1L << 6, hook_mousemove, mlx);
	//mlx_loop_hook(mlx->mlx_ptr, main_loop, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
