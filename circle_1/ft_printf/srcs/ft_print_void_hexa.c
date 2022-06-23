/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_void_hexa.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:35:06 by sooyokim          #+#    #+#             */
/*   Updated: 2022/04/15 09:11:33 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa_len(unsigned long num)
{
	int	cnt;

	cnt = 0;
	while (num > 0)
	{
		num = num / 16;
		cnt++;
	}
	return (cnt);
}

void	ft_print_hexa(unsigned long long num)
{
	if (num >= 16)
	{
		ft_print_hexa(num / 16);
		ft_print_hexa(num % 16);
	}
	else
	{
		if (num < 10)
			ft_putchar_fd(num + '0', 1);
		else
			ft_putchar_fd(num - 10 + 'a', 1);
	}	
}

int	ft_print_void_hexa(unsigned long long num)
{
	int	res;

	res = 0;
	res = write(1, "0x", 2);
	if (num == 0)
		return (res + write(1, "0", 1));
	else
	{
		ft_print_hexa(num);
		return (res + ft_hexa_len(num));
	}
}
