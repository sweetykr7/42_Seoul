/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 10:44:26 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/19 18:17:30 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include "mlx.h"

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

int	main(int ac, const char **av)
{
	t_mlx		*mlx;
	t_viewpoint	*vp;

	if (!input_check(ac, av))
		return (0);
	mlx = init_mlx(av[1], av);
	render(mlx);
	mlx_key_hook(mlx->win_ptr, hook_key, mlx);
	mlx_hook(mlx->win_ptr, 4, 0, hook_mouse, mlx);
	mlx_hook(mlx->win_ptr, 17, 0, terminate_fractol, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
