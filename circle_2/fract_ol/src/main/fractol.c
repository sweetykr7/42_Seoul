/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 10:44:26 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/20 13:31:32 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"

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
