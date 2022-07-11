/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_stack_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:22:31 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/11 17:33:43 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_from_to_insert_print_buf(t_buf *print_buf, char option)
{
	if (option == 'a')
	{
		if (!insert_print_buf(print_buf, "pa\n"))
			return (0);
	}
	else if (option == 'b')
	{
		if (!insert_print_buf(print_buf, "pb\n"))
			return (0);
	}
	return (1);
}

int	swap_insert_print_buf(t_buf *print_buf, char option)
{
	if (option == 'a')
	{
		if (!insert_print_buf(print_buf, "sa\n"))
			return (0);
	}
	else if (option == 'b')
	{
		if (!insert_print_buf(print_buf, "sb\n"))
			return (0);
	}
	return (1);
}

int	re_reverse_insert_print_buf(t_buf *print_buf, char option)
{
	if (option == 'a')
	{
		if (!insert_print_buf(print_buf, "rra\n"))
			return (0);
	}
	else if (option == 'b')
	{
		if (!insert_print_buf(print_buf, "rrb\n"))
			return (0);
	}
	return (1);
}

int	reverse_insert_print_buf(t_buf *print_buf, char option)
{
	if (option == 'a')
	{
		if (!insert_print_buf(print_buf, "ra\n"))
			return (0);
	}
	else if (option == 'b')
	{
		if (!insert_print_buf(print_buf, "rb\n"))
			return (0);
	}
	return (1);
}
