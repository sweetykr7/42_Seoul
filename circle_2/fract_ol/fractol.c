/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 10:44:26 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/14 20:01:16 by sooyokim         ###   ########.fr       */
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


int		mandelbrot(int count_w, int count_h, int iter)
{
	double c_re;
	double c_im;
	double x;
	double x_new;
	double y;

	//iter++;
	c_re = ((count_w - W_WIDTH / 2) * 3.0 / W_WIDTH) - 0.5;
	c_im = ((W_HEIGHT / 2) - count_h) * 2.0 / W_HEIGHT;
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


void	put_pixel(t_img *img)
{
	int		iter;
    int		color;
	int		i;
	int		j;

	i = 0;
	while (i <= W_HEIGHT)
	{
		j = 0;
		while (j <= W_WIDTH)
		{
			iter = mandelbrot(i, j, 0);
			//iter = julia(count_w, count_h, 0, img);
			if (iter < ITER_MAX)
			{
				color = color_set(iter);
				my_mlx_pixel_put(img, i, j, 0x00FFFFFF);
			}
            else
				my_mlx_pixel_put(img, i, j, 0x00000000);
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

t_img	*new_image(t_mlx *mlx)
{	
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!mlx->img)
		return (0);
	img->img_ptr = mlx_new_image(mlx->mlx_ptr, W_WIDTH, W_HEIGHT);
	if (!img->img_ptr)
		return (del_image(mlx, img));
	img->data = mlx_get_data_addr(img->img_ptr, &img->bpp, &img->size_l,
			&img->endian);
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
	if (!mlx->img)
		return (0);
	return (mlx);
}

int	main(int ac, const char **av)
{
	t_mlx	*mlx;

	if (!input_check(ac, av))
		return (0);
	mlx = init_mlx();
	ft_putstr("test\n");
	put_pixel(mlx->img);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img->img_ptr, 0, 0);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}



// #include "mlx.h"

// typedef struct  s_data
// {
//   void	*img;
//   char	*addr;
//   int	bits_per_pixel;
//   int	line_length;
//   int	endian;
// }               t_data;

// void  my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
//   char *dst;

//   dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
//   *(unsigned int*)dst = color;
// }

// int main(void)
// {
//   void	  *mlx;
//   void	  *mlx_win;
//   t_data  img;
//   int     i;
//   int     j;
//   int     k;

//   mlx = mlx_init();
//   mlx_win = mlx_new_window(mlx, 600, 400, "miniRT");
//   img.img = mlx_new_image(mlx, 600, 400);
//   img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
//   for (i = 250, k = 99; i < 300; i++, k -= 2)
//   {
//     for (j = 150 + k; j < 250; j++)
//       my_mlx_pixel_put(&img, i, j, 0x0000FF00);
//   }
//   for (i = 300, k = 0; i < 350; i++, k += 2)
//   {
//     for (j = 150 + k; j < 250; j++)
//       my_mlx_pixel_put(&img, i, j, 0x0000FF00);
//   }
//   mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
//   mlx_loop(mlx);
//   return (0);
// }