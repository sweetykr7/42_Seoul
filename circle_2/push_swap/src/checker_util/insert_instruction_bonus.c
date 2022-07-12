/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_instruction_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:24:40 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/12 11:04:21 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_ins	*last_instruction(t_ins *ins)
{
	t_ins	*temp;

	temp = 0;
	while (ins->next)
		ins = ins->next;
	temp = ins;
	return (temp);
}

void	insert_instruction_input_lst(t_ins *temp, char *res)
{
	t_ins	*res_buf;

	if (!temp->ins)
		temp->ins = res;
	else
	{
		res_buf = initial_insturction_struct();
		temp->next = res_buf;
		temp->next->ins = res;
		temp->next->next = 0;
	}
}

t_ins	*insert_instruction(t_ins *ins, char *str)
{
	t_ins	*temp;
	int		strlen;
	int		i;

	strlen = strsize(str);
	temp = last_instruction(ins);
	if (!str)
	{
		temp->next = 0;
		return (ins);
	}
	i = -1;
	insert_instruction_input_lst(temp, str);
	ins->total_cnt = ins->total_cnt + 1;
	return (ins);
}
