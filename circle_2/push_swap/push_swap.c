/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:30:45 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/11 10:52:53 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_head	*a;
	t_head	*b;
	t_buf	*buf;

	if (ac < 2)
		return (0);
	a = new_head();
	b = new_head();
	buf = initial_print_buf();
	if (!a || !b || !buf)
		return (all_free_with_error(a, b, buf));
	if (!get_number(av, ac, a))
		return (all_free_with_error(a, b, buf));
	a->head->cluster_cnt = a->total_cnt;
	divide_stack_recur(a, b, a->total_cnt, buf);
	buf = algorithm_optimize(buf);
	print_buf_out(buf);
	all_free(a, b, buf);
	return (0);
}
