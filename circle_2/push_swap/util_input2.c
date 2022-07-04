/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_input2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 10:55:28 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/04 10:56:47 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' \
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	atoi_input(const char *str)
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
