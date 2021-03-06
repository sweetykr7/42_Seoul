/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 12:33:09 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/11 18:41:41 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_words(char *a, char *b)
{
	int	res;
	int	i;

	res = 1;
	i = 0;
	while (a[i])
	{
		if (a[i] != b[i])
			return (0);
		i++;
	}
	if (b[i])
		return (0);
	return (res);
}

int	put_error_1_return_zero(int *error)
{
	*error = 1;
	return (0);
}

t_pivot	pivot_initial(void)
{
	t_pivot	p;

	p.pivot1 = 0;
	p.pivot2 = 0;
	return (p);
}
