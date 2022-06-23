/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:20:50 by sooyokim          #+#    #+#             */
/*   Updated: 2022/03/21 11:31:24 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' \
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int				m;
	unsigned int	n;

	m = 1;
	while (is_space(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			m = -1;
		str++;
	}
	n = 0;
	while (*str && '0' <= *str && *str <= '9')
	{
		if (n > (2147483648 - (unsigned int)(*str - '0')) / 10 && m == -1)
			return (0);
		else if (n > (2147483647 - (unsigned int)(*str - '0')) / 10 && m == 1)
			return (-1);
		n = n * 10 + (*str - '0');
		str++;
	}
	return (n * m);
}
