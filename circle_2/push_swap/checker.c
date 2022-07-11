/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:55:59 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/11 11:14:39 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_instruction(t_ins *ins_list)
{
	char	*instruction;

	instruction = get_next_line(0);
	while (instruction)
	{
		if (!instruction_check(instruction))
		{
			free(instruction);
			return (0);
		}
		insert_instruction(ins_list, instruction);
		instruction = get_next_line(0);
	}
	return (1);
}

void	check_asc_sort_a_checker(t_head *a, int size)
{
	if (check_asc_sort_a(a, size))
		print_all("OK\n");
	else
		print_all("KO\n");
}

void	checker_sort_result(t_head *a, t_head *b, t_ins *ins_list, int size)
{
	if (ins_list->total_cnt != 0)
	{
		if (!run_instruction(ins_list, a, b))
			print_all("KO\n");
		else
			check_asc_sort_a_checker(a, size);
	}
	else
		check_asc_sort_a_checker(a, size);
}

int	main(int ac, char **av)
{
	t_head	*a;
	t_head	*b;
	t_ins	*ins_list;
	int		size;

	if (ac < 2)
		return (0);
	a = new_head();
	b = new_head();
	ins_list = initial_insturction_struct();
	if (!a || !b || !ins_list)
		return (all_free_with_error_checker(a, b, ins_list));
	if (!get_number(av, ac, a))
		return (all_free_with_error_checker(a, b, ins_list));
	a->head->cluster_cnt = a->total_cnt;
	size = a->total_cnt;
	if (!get_instruction(ins_list))
		return (all_free_with_error_checker(a, b, ins_list));
	checker_sort_result(a, b, ins_list, size);
	all_free_checker(a, b);
	instruction_free(ins_list);
	return (0);
}
