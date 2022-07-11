/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_sort_optimize_3_case.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:56:00 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/11 18:27:18 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_a_optimize_case1(t_head *a, t_buf *print_buf, int *error)
{
	if (!re_reverse(a, print_buf, 'a'))
		return (put_error_1_return_zero(error));
	if (!swap(a, print_buf, 'a'))
		return (put_error_1_return_zero(error));
	return (1);
}

int	sort_a_optimize_case2(t_head *a, t_buf *print_buf, int *error)
{
	if (!swap(a, print_buf, 'a'))
		return (put_error_1_return_zero(error));
	return (1);
}

int	sort_a_optimize_case3(t_head *a, t_buf *print_buf, int *error)
{
	if (!re_reverse(a, print_buf, 'a'))
		return (put_error_1_return_zero(error));
	return (1);
}

int	sort_a_optimize_case4(t_head *a, t_buf *print_buf, int *error)
{
	if (!reverse(a, print_buf, 'a'))
		return (put_error_1_return_zero(error));
	return (1);
}

int	sort_a_optimize_case5(t_head *a, t_buf *print_buf, int *error)
{
	if (!swap(a, print_buf, 'a'))
		return (put_error_1_return_zero(error));
	if (!re_reverse(a, print_buf, 'a'))
		return (put_error_1_return_zero(error));
	return (1);
}
