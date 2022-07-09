/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_stack_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 14:18:13 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/09 14:35:47 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	re_reverse_both_checker(t_head *a, t_head *b)
{
	if (!re_reverse_checker(a))
		return (0);
	if (!re_reverse_checker(b))
		return (0);
	return (1);
}

int	reverse_both_checker(t_head *a, t_head *b)
{
	if (!reverse_checker(a))
		return (0);
	if (!reverse_checker(b))
		return (0);
	return (1);
}

int	swap_both_checker(t_head *a, t_head *b)
{
	if (!swap_checker(a))
		return (0);
	if (!swap_checker(b))
		return (0);
	return (1);
}
