/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 10:44:26 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/15 17:57:57 by sooyokim         ###   ########.fr       */
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

int		julia(int count_w, int count_h, int iter)
{
	double	c_re;
	double	c_im;
	double	x;
	double	x_new;
	double	y;

	c_re = 0;
	c_im = 1;
	x = ((count_w - W_WIDTH / 2) * 4.0 / W_WIDTH);
	y = ((W_HEIGHT / 2) - count_h) * 4.0 / W_HEIGHT;
	while ((pow(x, 2.0) + pow(y, 2.0) < 4) && (iter < ITER_MAX))
	{
		x_new = pow(x, 2.0) - pow(y, 2.0) + c_re;
		y = 2 * x * y + c_im;
		x = x_new;
		iter++;
	}
	return (iter);
}

// int		mandelbrot(int i, int j, int iter)
// {
// 	double c_re;
// 	double c_im;
// 	double x;
// 	double x_new;
// 	double y;

// 	//iter++;
// 	c_re = ((i - W_WIDTH / 2) * 3 / W_WIDTH) - 0.5;
// 	c_im = ((W_HEIGHT / 2) - j) * 2.0 / W_HEIGHT;
// 	x = 0;
// 	y = 0;
// 	while ((pow(x, 2.0) + pow(y, 2.0) < 4) && (iter < ITER_MAX))
// 	{
// 		x_new = pow(x, 2.0) - pow(y, 2.0) + c_re;
// 		y = 2 * x * y + c_im;
// 		x = x_new;
// 		iter++;
// 	}
// 	return (iter);
// }

int		mandelbrot(int count_w, int count_h, int iter)
{
	double c_re;
	double c_im;
	double x;
	double x_new;
	double y;

	c_re = ((count_w - W_WIDTH / 2) * 3.0 / W_WIDTH) - 0.5;
	c_im = ((W_HEIGHT / 2) - count_h) * 2.0 / W_HEIGHT - 0.5;
	x = 0;
	y = 0;
	while ((pow(x, 2.0) + pow(y, 2.0) < 4) && (iter < ITER_MAX))
	{
		x_new = pow(x, 2.0) - pow(y, 2.0) + c_re;
		y = 2 * x * y + c_im;
		x = x_new;
		iter++;
	}
	return (iter);
}


void	put_pixel(t_img img, t_mlx *mlx)
{
	int		iter;
    int		color;
	int		i;
	int		j;

	i = 0;
	while (i < W_WIDTH)
	{
		j = 0;
		while (j < W_HEIGHT)
		{
			iter = mandelbrot(i, j, 0);
			//iter = julia(i, j, 0);
			if (iter < ITER_MAX)
			{
				color = color_set(iter);
				//0x00FFFFFF
				my_mlx_pixel_put(&img, i, j, color);
			}
            else
				my_mlx_pixel_put(&img, i, j, 0x00000000);			
			j++;
		}
		i++;
	}
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
	return (mlx);
}

t_mlx	*init_mlx(void)
{
	t_mlx	*mlx;

	mlx = mlx_structure_init(mlx);
	if (!mlx)
		return (0);
	mlx->img = new_image(mlx);
	// if (!mlx->img)
	// 	return (0);
	return (mlx);
}

#include <stdio.h>
int ft_mouse_press(int button, int x, int y, void *p)
{
	printf("button_num: %d , press at %dx%d\n", button, x, y);	
	return (0);
}

int hook_mousedown(int button, int x, int y, void *p)
{
	printf("button_num: %d , press at %dx%d\n", button, x, y);	
	return (0);
}
int hook_mouseup(int button, int x, int y, void *p)
{
	printf("button_num: %d , press at %dx%d\n", button, x, y);	
	return (0);
}

int	main(int ac, const char **av)
{
	t_mlx	*mlx;

	if (!input_check(ac, av))
		return (0);
	mlx = init_mlx();
	ft_putstr("test\n");
	put_pixel(mlx->img, mlx);
	//test_put_pixel(mlx->img);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, (mlx->img.img_ptr), 0, 0);
	//mlx_hook(mlx->win_ptr, 4, 0, ft_mouse_press, 0); //클릭
	mlx_key_hook(mlx->win_ptr, hook_keydown, mlx); 
	mlx_hook(mlx->win_ptr, 4, 1L << 2, hook_mousedown, mlx);
	mlx_hook(mlx->win_ptr, 5, 1L << 3, hook_mouseup, mlx);
	//mlx_hook(mlx->window, 6, 1L << 6, hook_mousemove, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}

