/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chr_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:08:40 by sooyokim          #+#    #+#             */
/*   Updated: 2022/04/14 14:25:33 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		ft_putchar_fd(c[i], 1);
		i++;
	}
	return (i);
}

int	ft_print_chr(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_print_str(char *c)
{
	int	i;

	i = 0;
	if (!c)
		return (ft_putstr("(null)"));
	while (c[i])
	{
		write(1, &c[i], 1);
		i++;
	}
	return (i);
}

int	ft_print_percent(void)
{
	write(1, "%", 1);
	return (1);
}
