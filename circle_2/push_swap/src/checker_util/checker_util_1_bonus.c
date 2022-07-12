/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_util_1_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 10:59:39 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/12 11:04:21 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	all_free_with_error_checker(t_head *a, t_head *b, t_ins *ins_list)
{
	if (a)
		head_free(a);
	if (b)
		head_free(b);
	if (ins_list)
		instruction_free(ins_list);
	print_all("Error\n");
	return (0);
}

void	all_free_checker(t_head *a, t_head *b)
{
	if (a)
		head_free(a);
	if (b)
		head_free(b);
}

t_ins	*initial_insturction_struct(void)
{
	t_ins	*ins;

	ins = (t_ins *)malloc(sizeof(t_ins));
	if (!ins)
		return (0);
	ins->ins = 0;
	ins->next = 0;
	ins->total_cnt = 0;
	return (ins);
}

void	instruction_free(t_ins *ins_list)
{
	t_ins	*temp;

	while (ins_list)
	{
		if (ins_list->next)
			temp = ins_list->next;
		else
			temp = 0;
		free(ins_list->ins);
		ins_list = 0;
		free (ins_list);
		if (temp)
			ins_list = temp;
	}
}
