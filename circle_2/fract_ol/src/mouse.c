/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:44:36 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/19 10:45:14 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	hook_mouse(int button, int x, int y, t_mlx *mlx)
{
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
