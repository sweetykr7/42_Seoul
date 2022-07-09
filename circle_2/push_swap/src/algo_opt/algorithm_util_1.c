/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_util_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 11:34:12 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/09 12:32:45 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_buf	*last_second_buf(t_buf *buf)
{
	t_buf	*temp;

	temp = 0;
	while (buf->next->next)
		buf = buf->next;
	temp = buf;
	return (temp);
}

int	count_jump_words(t_buf *buf, char *jump_words)
{
	int		cnt;
	t_buf	*temp;

	cnt = 0;
	temp = buf->next;
	while (temp && check_words(temp->print_buf, jump_words))
	{
		cnt++;
		if (temp->next)
			temp = temp->next;
		else
			temp = 0;
	}
	return (cnt);
}

int	jump_check(t_buf *buf, char *jump_words, char *words)
{
	t_buf	*temp;

	temp = buf->next;
	while (temp && check_words(temp->print_buf, jump_words))
	{		
		if (temp->next)
			temp = temp->next;
		else
			temp = 0;
	}
	if (!temp)
		return (0);
	return (check_words(temp->print_buf, words));
}

void	free_del_2_3(t_buf *del1, t_buf *del2)
{
	free(del1->print_buf);
	free(del2->print_buf);
	free(del1);
	free(del2);
}
