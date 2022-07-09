/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_instruction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:56:06 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/09 15:35:01 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	run_instruction_case(char *str, t_head *a, t_head *b)
{
	if (check_words(str, "pa\n"))
		return (push_from_to_checker(b, a));
	if (check_words(str, "pb\n"))
		return (push_from_to_checker(a, b));
	if (check_words(str, "ra\n"))
		return (reverse_checker(a));
	if (check_words(str, "rb\n"))
		return (reverse_checker(b));
	if (check_words(str, "rr\n"))
		return (reverse_both_checker(a, b));
	if (check_words(str, "rra\n"))
		return (re_reverse_checker(a));
	if (check_words(str, "rrb\n"))
		return (re_reverse_checker(b));
	if (check_words(str, "rrr\n"))
		return (re_reverse_both_checker(a, b));
	if (check_words(str, "sa\n"))
		return (swap_checker(a));
	if (check_words(str, "sb\n"))
		return (swap_checker(b));
	if (check_words(str, "ss\n"))
		return (swap_both_checker(a, b));
	return (1);
}

int	run_instruction(t_ins *ins_list, t_head *a, t_head *b)
{
	t_ins	*temp;

	temp = ins_list;
	while (temp)
	{
		if (!run_instruction_case(temp->ins, a, b))
			return (0);
		temp = temp->next;
	}
	return (1);
}
