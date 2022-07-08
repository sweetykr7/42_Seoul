/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_util_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 11:34:14 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/08 12:03:50 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_change_words(t_buf *buf, t_buf *last_point, char *words, int cnt)
{
	int		i;
	t_buf	*temp;

	i = -1;
	temp = buf;
	while (++i < cnt)
		temp = temp->next;
	temp->next = last_point;
	free(buf->print_buf);
	buf->print_buf = insert_words(words);
}

void	del_cnt_change1(t_buf *buf, char *change_words, int cnt, int *flag)
{
	t_buf	*temp;
	t_buf	*last_point;
	t_buf	*del;
	int		i;

	temp = buf;
	i = -1;
	while (++i < cnt)
	{
		if (temp->next->next->next)
			last_point = temp->next->next->next;
		else
		{
			last_point = 0;
			break ;
		}
		del = temp->next->next;
		temp = temp->next;
	}
	del->next = 0;
	insert_change_words(buf, last_point, change_words, cnt);
	free(del->print_buf);
	free(del);
	*flag = 0;
}	

void	del_3_change_1(t_buf *buf, char *change_words, char *str3, int *flag)
{
	t_buf	*temp;
	t_buf	*del;

	if (buf->next->next->next)
		temp = buf->next->next->next;
	else
		temp = 0;
	del = buf->next->next;
	del->next = 0;
	buf->next->next = temp;
	free(buf->print_buf);
	buf->print_buf = insert_words(change_words);
	free(del->print_buf);
	free(del);
	if (buf->next->next)
		str3 = buf->next->next->print_buf;
	*flag = 0;
}

void	del_2_change_1(t_buf *buf, char *change_words, char *str2, int *flag)
{
	t_buf	*temp;
	t_buf	*del;

	if (buf->next->next)
		temp = buf->next->next;
	else
		temp = 0;
	del = buf->next;
	del->next = 0;
	buf->next = temp;
	free(buf->print_buf);
	buf->print_buf = insert_words(change_words);
	free(del->print_buf);
	free(del);
	str2 = buf->next->print_buf;
	*flag = 0;
}

void	del_2_3(t_buf *buf, char *str2, char *str3, int *flag)
{
	t_buf	*temp;
	t_buf	*del1;
	t_buf	*del2;

	if (buf->next->next->next)
		temp = buf->next->next->next;
	else
		temp = 0;
	del1 = buf->next;
	del2 = buf->next->next;
	del1->next = 0;
	del2->next = 0;
	buf->next = temp;
	free_del_2_3(del1, del2);
	if (buf->next)
		str2 = buf->next->print_buf;
	else
		str2 = 0;
	if (buf->next->next)
		str3 = buf->next->next->print_buf;
	else
		str3 = 0;
	*flag = 0;
}
