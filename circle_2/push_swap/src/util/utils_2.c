/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:54:18 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/08 12:26:48 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pc	*pivot_cnt_pre_set(t_pc *pivot_cnt)
{
	pivot_cnt = (t_pc *)malloc(sizeof(pivot_cnt));
	if (!pivot_cnt)
		return (0);
	pivot_cnt->pivot1_cnt = 0;
	pivot_cnt->pivot2_cnt = 0;
	pivot_cnt->pivot3_cnt = 0;
	return (pivot_cnt);
}

void	print_all(char const *s)
{
	if (!s)
		return ;
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
}

t_list	*last_lst(t_list *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_list	*last_second_lst(t_list *lst)
{
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}

char	*insert_words(char *str)
{
	char	*res;
	int		strlen;
	int		i;

	strlen = strsize(str);
	res = (char *)malloc(sizeof(strlen) + 1);
	if (!res)
		return (0);
	i = 0;
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
