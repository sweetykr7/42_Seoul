/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_setting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:46:29 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/19 18:15:36 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include "libft.h"

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

t_img	new_image(t_mlx *mlx)
{	
	t_img	img;

	img.img_ptr = mlx_new_image(mlx->mlx_ptr, W_WIDTH, W_HEIGHT);
	img.data = mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_l,
			&img.endian);
	return (img);
}

int	julia_setting(t_mlx *mlx, const char *para1, const char *para2)
{
	int	error;

	error = 0;
	mlx->julia_c.re = atod_check((char *)para1, &error);
	if (error)
		return (0);
	mlx->julia_c.im = atod_check((char *)para2, &error);
	if (error)
		return (0);
	return (1);
}

t_mlx	*init_mlx(const char *fractol, const char **av)
{
	t_mlx	*mlx;

	mlx = mlx_structure_init(mlx);
	if (!mlx)
		return (0);
	mlx->img = new_image(mlx);
	if (!mlx->img.img_ptr)
		return (0);
	mlx->vp = init_viewpoint(mlx->vp);
	mlx->fractol = fractol;
	viewpoint_setting(mlx->vp, fractol);
	if (ft_strcmp(fractol, "julia"))
		if (!julia_setting(mlx, av[2], av[3]))
			return (0);
	return (mlx);
}
