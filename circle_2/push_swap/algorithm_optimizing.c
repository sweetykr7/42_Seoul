/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_optimizing.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:09:05 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/07 11:08:30 by sooyokim         ###   ########.fr       */
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

int	check_words(char *a, char *b)
{
	int	res;
	int	i;

	res = 1;
	i = 0;
	while (a[i])
	{
		if (a[i] != b[i])
			return (0);
		i++;
	}
	if (b[i])
		return (0);
	return (res);
}

void	reduce_change_1_2(t_buf *buf, char *change_words)
{
	t_buf	*temp;
	t_buf	*del;

	temp = buf->next->next;
	del = buf->next;
	del->next = 0;
	buf->next = temp;
	free(buf->print_buf);
	buf->print_buf = insert_words(change_words);
	free(del->print_buf);
	free(del);
}

void	reduce_2_3(t_buf *buf, char *str2, char *str3)
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
	free(del1->print_buf);
	free(del2->print_buf);
	free(del1);
	free(del2);
	if (buf->next)
		str2 = buf->next->print_buf;
	else
		str2 = 0;
	if (buf->next->next)
		str3 = buf->next->next->print_buf;
	else
		str3 = 0;
}

int	algorithm_optimize_case(t_buf *buf, char *str1, char *str2, char *str3)
{
	int	flag;

	flag = 1;
	
	if (check_words(str2, "ra\n"))
	{
		if (check_words(str3, "rra\n"))
			reduce_2_3(buf, str2, str3);
	}
	else if (check_words(str2, "rra\n"))
	{
		if (check_words(str3, "ra\n"))
			reduce_2_3(buf, str2, str3);
	}
	else if (check_words(str2, "rb\n"))
	{
		if (check_words(str3, "rrb\n"))
			reduce_2_3(buf, str2, str3);
	}
	else if (check_words(str2, "rrb\n"))
	{
		if (check_words(str3, "rb\n"))
			reduce_2_3(buf, str2, str3);
	}
	
	(void)str1;
	// if (check_words(str1, "ra\n"))
	// {
	// 	if (check_words(str2, "rb\n"))
	// 		reduce_change_1_2(buf, "rr\n");		
	// }
	// else if (check_words(str1, "rb\n"))
	// {
	// 	if (check_words(str2, "ra\n"))
	// 		reduce_change_1_2(buf, "rr\n");		
	// }
	// else if (check_words(str1, "rra\n"))
	// {
	// 	if (check_words(str2, "rrb\n"))
	// 		reduce_change_1_2(buf, "rrr\n");		
	// }
	// else if (check_words(str1, "rrb\n"))
	// {
	// 	if (check_words(str2, "rra\n"))
	// 		reduce_change_1_2(buf, "rrr\n");		
	// }
	return (flag);
}

t_buf	*algorithm_optimize(t_buf *buf)
{
	char	*str1;
	char	*str2;
	char	*str3;
	t_buf	*temp;
	int		flag;

	if (buf->total_cnt < 3)
		return (buf);
	temp = buf;
	flag = 1;
	while (temp->next->next)
	{
		str1 = temp->print_buf;
		str2 = temp->next->print_buf;
		str3 = temp->next->next->print_buf;
		flag = algorithm_optimize_case(temp, str1, str2, str3);
		if (temp->next->next && flag)
			temp = temp->next;
		else
			break ;
	}
	return (buf);
}
