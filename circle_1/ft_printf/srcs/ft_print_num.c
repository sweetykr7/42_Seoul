/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:25:41 by sooyokim          #+#    #+#             */
/*   Updated: 2022/04/15 09:16:11 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_itoa_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num > 0)
	{
		num = num / 10;
		len ++;
	}
	return (len);
}

int	ft_print_num_str(char *num_a)
{
	int	res;

	res = 0;
	if (!(*num_a))
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	while (num_a[res])
	{
		ft_putchar_fd(num_a[res], 1);
		res++;
	}
	return (res);
}

char	*ft_unsigned_itoa(unsigned int num)
{
	char	*res;
	int		len;

	len = 0;
	len = ft_unsigned_itoa_len(num);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	res[len] = '\0';
	while (num > 0)
	{
		res[len - 1] = (num % 10) + '0';
		num = num / 10;
		len--;
	}
	return (res);
}

int	ft_print_unsigned_num(unsigned int num)
{
	int		len;
	char	*res;

	len = 0;
	if (num == 0)
		len = write(1, "0", 1);
	else
	{
		res = ft_unsigned_itoa(num);
		if (!res)
			return (0);
		len = ft_print_num_str(res);
		free(res);
	}	
	return (len);
}

int	ft_print_num(int num)
{
	char	*num_a;
	int		len;

	len = 0;
	num_a = ft_itoa(num);
	len = ft_print_num_str(num_a);
	free(num_a);
	return (len);
}
