/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 17:12:05 by sooyokim          #+#    #+#             */
/*   Updated: 2022/04/15 09:33:37 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexa_chr_len(unsigned int num)
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

void	ft_print_hexa_chr(unsigned int num, int option)
{
	if (num >= 16)
	{
		ft_print_hexa_chr(num / 16, option);
		ft_print_hexa_chr(num % 16, option);
	}
	else
	{
		if (num < 10)
			ft_putchar_fd(num + '0', 1);
		else
		{
			if (option == 1)
				ft_putchar_fd(num - 10 + 'a', 1);
			else if (option == 2)
				ft_putchar_fd(num - 10 + 'A', 1);
		}
	}	
}

int	ft_print_lower_hexa(unsigned int num)
{
	int	res;

	res = 0;
	if (num == 0)
		return (res + write(1, "0", 1));
	else
	{
		ft_print_hexa_chr(num, 1);
		return (res + ft_print_hexa_chr_len(num));
	}
}

int	ft_print_upper_hexa(unsigned int num)
{
	int	res;

	res = 0;
	if (num == 0)
		return (res + write(1, "0", 1));
	else
	{
		ft_print_hexa_chr(num, 2);
		return (res + ft_print_hexa_chr_len(num));
	}
}
