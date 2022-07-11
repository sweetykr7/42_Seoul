/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_input2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 10:55:28 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/11 13:20:39 by sooyokim         ###   ########.fr       */
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

int	atoi_input_calculator(char *str, int *error, int m)
{
	unsigned int	n;

	n = 0;
	while (*str)
	{	
		if (*str < '0' || *str > '9')
		{
			*error = 1;
			return (0);
		}
		if (n > (2147483648 - (unsigned int)(*str - '0')) / 10 && m == -1)
		{
			*error = 1;
			return (0);
		}
		else if (n > (2147483647 - (unsigned int)(*str - '0')) / 10 && m == 1)
		{
			*error = 1;
			return (0);
		}
		n = n * 10 + (*str - '0');
		str++;
	}	
	return (n * m);
}

int	atoi_input(char *str, int *error)
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
	if (*str < '0' || *str > '9')
	{
		*error = 1;
		return (0);
	}
	return (atoi_input_calculator(str, error, m));
}
