/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:30:45 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/02 14:41:40 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "util_list.c"
#include "util_stack_a.c"
#include "util_stack_b.c"
#include "utils_1.c"
#include "utils_2.c"
#include "util_sort_a.c"
#include "util_sort_a_case.c"
#include "util_sort_b.c"
#include "util_sort_b_case.c"
#include "util_print_buf.c"
#include "util_divide_stack_a.c"
#include "util_divide_stack_b.c"
#include "util_sort_check.c"
#include "get_pivot.c"
#include "divide_stack_recur.c"
#include "ft_itoa.c"
#include "ft_atoi.c"

#include <stdio.h>

int	main(int ac, char **av)
{
	ac = 0;
	**av = 0;
	//int	test[23] = {1,40,-1,-2,-15,5,15,20,3,-10,11,-60,2,7,4,-50,-40,-30,6,8,9,10,12};
	//int	test[4] = {1,40,-1,-2};
	int	test[5] = {1,40,-1,-2,-15};
	int cnt;
	int	i;
	t_head *a;
	t_head *b;
	char	*print_buf;
	int total_cnt;
	t_list *temp;

	//예외처리들
	//split으로 가져오기	
	//가져온거 a에 집어 넣기

	print_buf = (char *)malloc(sizeof(char) * 1);
	if (!print_buf)
		return (0);
	print_buf[0] = '\0';
	a = new_head();
	b = new_head();
	i = 0;
	cnt = 5;
	while (i < cnt)
	{
		list_add(a, test[i], 0);
		i++;
	}
	a->head->cluster_cnt = cnt; // 나중에 갯수 카운팅해서 넣어주면 됨.
	//숫자 카운팅 해줘야함. total_cnt와 lst에 cluster_cnt에도 카운팅 하도록 하자.
	//lstsize() 파악만 되면 굳이 안해줘도 될듯?
	total_cnt = cnt;
	divide_stack_recur(a, b, total_cnt, print_buf);
	i = 0;
	temp = a->head;
	while (i < total_cnt)
	{
		printf("check list [%d] : %d \n",i,temp->data);
		i++;
		if(temp->next)
			temp = temp->next;
	}
	printf("complete\n");
	all_free(a);
	all_free(b);
	printf("complete\n");
	return (0);
}

// int	main(int ac, char **av)
// {
// 	t_head	*a;
// 	t_head	*b;
// 	char	*print_buf;
// 	int		total_cnt;
// 	int		i;
// 	t_list	*temp;

// 	//예외처리들
// 	//split으로 가져오기	
// 	//가져온거 a에 집어 넣기

// 	print_buf = (char *)malloc(sizeof(char) * 1);
// 	if (!print_buf)
// 		return (0);
// 	print_buf[0] = '\0';
// 	a = new_head();
// 	b = new_head();
// 	//printf("test");
// 	i = 1;
// 	while (i < ac)
// 	{
// 		list_add(a, ft_atoi(av[i]), 0);
// 		printf("check : %d \n", ft_atoi(av[i]));
// 		i++;
// 	}
// 	a->head->cluster_cnt = 23; // 나중에 갯수 카운팅해서 넣어주면 됨.
// 	//숫자 카운팅 해줘야함. total_cnt와 lst에 cluster_cnt에도 카운팅 하도록 하자.
// 	//lstsize() 파악만 되면 굳이 안해줘도 될듯?
// 	total_cnt = ac - 1;
// 	a->head->cluster_cnt = total_cnt;

// 	printf("pass test\n");
// 	divide_stack_recur(a, b, total_cnt, print_buf);
// 	printf("pass test2\n");
// 	i = 0;
// 	temp = a->head;
// 	while (i < total_cnt)
// 	{
// 		printf("check list [%d] : %d \n",i,temp->data);
// 		i++;
// 		if(temp->next)
// 			temp = temp->next;
// 	}
// 	// printf("complete\n");
// 	// all_free(a);
// 	// all_free(b);
// 	// printf("complete\n");
// 	return (0);
// }
