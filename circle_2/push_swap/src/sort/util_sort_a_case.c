/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_sort_a_case.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:15:16 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/11 18:31:59 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_a_case_1(t_head *a, t_head *b, t_buf *print_buf, int *error)
{
	if (!swap(a, print_buf, 'a'))
		return (put_error_1_return_zero(error));
	if (!reverse(a, print_buf, 'a'))
		return (put_error_1_return_zero(error));
	if (!reverse(a, print_buf, 'a'))
		return (put_error_1_return_zero(error));
	if (!push_from_to(a, b, print_buf, 'b'))
		return (put_error_1_return_zero(error));
	if (!re_reverse(a, print_buf, 'a'))
		return (put_error_1_return_zero(error));
	if (!re_reverse(a, print_buf, 'a'))
		return (put_error_1_return_zero(error));
	if (!push_from_to(b, a, print_buf, 'a'))
		return (put_error_1_return_zero(error));
	return (1);
}

int	sort_a_case_2(t_head *a, t_head *b, t_buf *print_buf, int *error)
{
	if (!reverse(a, print_buf, 'a'))
		return (put_error_1_return_zero(error));
	if (!reverse(a, print_buf, 'a'))
		return (put_error_1_return_zero(error));
	if (!push_from_to(a, b, print_buf, 'b'))
		return (put_error_1_return_zero(error));
	if (!re_reverse(a, print_buf, 'a'))
		return (put_error_1_return_zero(error));
	if (!re_reverse(a, print_buf, 'a'))
		return (put_error_1_return_zero(error));
	if (!push_from_to(b, a, print_buf, 'a'))
		return (put_error_1_return_zero(error));
	return (1);
}

int	sort_a_case_3(t_head *a, t_buf *print_buf, int *error)
{
	if (!swap(a, print_buf, 'a'))
		return (put_error_1_return_zero(error));
	if (!reverse(a, print_buf, 'a'))
		return (put_error_1_return_zero(error));
	if (!swap(a, print_buf, 'a'))
		return (put_error_1_return_zero(error));
	if (!re_reverse(a, print_buf, 'a'))
		return (put_error_1_return_zero(error));
	return (1);
}

int	sort_a_case_4(t_head *a, t_buf *print_buf, int *error)
{
	if (!reverse(a, print_buf, 'a'))
		return (put_error_1_return_zero(error));
	if (!swap(a, print_buf, 'a'))
		return (put_error_1_return_zero(error));
	if (!re_reverse(a, print_buf, 'a'))
		return (put_error_1_return_zero(error));
	return (1);
}

int	sort_a_case_5(t_head *a, t_buf *print_buf, int *error)
{
	if (!swap(a, print_buf, 'a'))
		return (put_error_1_return_zero(error));
	return (1);
}
