/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:30:45 by sooyokim          #+#    #+#             */
/*   Updated: 2022/06/30 20:17:11 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "util_list.c"
#include "util_stack_a.c"
#include "util_stack_b.c"
#include "utils.c"
#include "util_sort_a.c"
#include "util_sort_a_case.c"
#include "util_sort_b.c"
#include "util_sort_b_case.c"


int	lstsize(t_list *lst)
{
	int		len;

	len = 0;
	while (lst)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}

// int	cluster_size(t_head *head)
// {
// 	int		cnt;
// 	t_list	*temp;

// 	cnt = 0;
// 	temp = head->head;
// 	while (temp->cluster_cnt != 0)
// 	{
// 		cnt++;
// 		if (!temp->next)
// 			break ;
// 		temp = temp->next;
// 	}
// 	return (cnt);
// }

void	divide_stack_a_pivot1(t_head *a, t_head *b, int *pivot_cnt1)
{
	a->head->cluster_cnt = 0;
	pb(a, b);
	*pivot_cnt1 = *pivot_cnt1 + 1;
}

void	divide_stack_a_pivot2(t_head *a, t_head *b, int *pivot_cnt2)
{
	a->head->cluster_cnt = 0;
	pb(a, b);
	rb(b);
	*pivot_cnt2 = *pivot_cnt2 + 1;
}

void	divide_stack_a_pivot3(t_head *a, t_head *b, int *pivot_cnt3)
{
	a->head->cluster_cnt = 0;
	ra(a);
	*pivot_cnt3 = *pivot_cnt3 + 1;
}

void	divide_stack_a(t_head *a, t_head *b, int pivot1, int pivot2)
{
	int		i;
	int		pivot1_cnt;
	int		pivot2_cnt;
	int		pivot3_cnt;
	t_list	*temp;

	pivot1_cnt = 0;
	pivot2_cnt = 0;
	pivot3_cnt = 0;
	i = a->head->cluster_cnt + 1;
	temp = a->head;
	while (--i > 0 && temp)
	{
		if (temp->data <= pivot1)
			divide_stack_a_pivot1(a, b, &pivot1_cnt);
		else if (temp->data <= pivot2)
			divide_stack_a_pivot2(a, b, &pivot2_cnt);
		else
			divide_stack_a_pivot3(a, b, &pivot3_cnt);
		temp = temp->next;
	}
	b->head->cluster_cnt = pivot1_cnt;
	i = pivot2_cnt + 1;
	while (--i > 0)
		rrb(b);
	i = pivot3_cnt + 1;
	while (--i > 0)
		rra(a);
	b->head->cluster_cnt = pivot2_cnt;
	a->head->cluster_cnt = pivot3_cnt;
}

void	divide_stack_b_pivot1(t_head *a, t_head *b, int *pivot_cnt1)
{
	b->head->cluster_cnt = 0;
	rb(b);
	*pivot_cnt1 = *pivot_cnt1 + 1;
}

void	divide_stack_b_pivot2(t_head *a, t_head *b, int *pivot_cnt2)
{
	b->head->cluster_cnt = 0;
	pa(a, b);
	ra(a);
	*pivot_cnt2 = *pivot_cnt2 + 1;
}

void	divide_stack_b_pivot3(t_head *a, t_head *b, int *pivot_cnt3)
{
	b->head->cluster_cnt = 0;
	pa(a, b);
	*pivot_cnt3 = *pivot_cnt3 + 1;
}

void	divide_stack_b(t_head *a, t_head *b, int pivot1, int pivot2)
{
	int		i;
	int		pivot1_cnt;
	int		pivot2_cnt;
	int		pivot3_cnt;
	t_list	*temp;

	pivot1_cnt = 0;
	pivot2_cnt = 0;
	pivot3_cnt = 0;
	i = b->head->cluster_cnt + 1;
	temp = b->head;
	while (--i > 0 && temp)
	{
		if (temp->data <= pivot1)
			divide_stack_b_pivot1(a, b, &pivot1_cnt);
		else if (temp->data <= pivot2)
			divide_stack_b_pivot2(a, b, &pivot2_cnt);
		else
			divide_stack_b_pivot3(a, b, &pivot3_cnt);
		temp = temp->next;
	}
	a->head->cluster_cnt = pivot3_cnt;
	i = pivot1_cnt + 1;
	while (--i > 0)
		rrb(b);
	b->head->cluster_cnt = pivot1_cnt;
	temp = a->head;
	i = a->total_cnt - pivot2_cnt + 1;
	while (--i > 0)
		temp = temp->next;
	temp->cluster_cnt = pivot2_cnt;
}

int	check_sort_a(t_head *a)
{
	t_list	*temp;

	temp = a->head;
	while (temp)
	{
		if (temp->cluster_cnt != -1)
			return (0);
		if (!temp->next)
			break ;
		temp = temp->next;
	}
	return (1);
}

t_pivot	get_pivot(t_head *a)
{
	t_pivot	p;
	t_list	*temp;
	int		*sort;
	int		size;
	int		i;

	size = a->head->cluster_cnt;
	sort = int_loc(size, &p);
	if (!sort)
		return (p);
	temp = a->head;
	i = 0;
	while (i < size && temp)
	{
		sort[i] = temp->data;
		temp = temp->next;
		i++;
	}
	sort = sort_arr(size, sort);
	p.pivot1 = sort[(size / 3)];
	p.pivot2 = sort[((size * 2) / 3)];
	free(sort);
	return (p);
}



void	divide_stack_recur(t_head *a, t_head *b, int total_cnt)
{
	//피벗 추출하는거(이안에 정렬을 해야만 피벗 추출 가능함.)
	//정렬확인?
	//처음에 스택 a에 들어있는 개수를 넣어준다.
	//스택 a에 정렬되지 않은게 있다면 a부터 정렬을 한다. (a에 있는 대상들 -1인지 확인하기)
	t_pivot	pivot;

	int	test_point;

	if (check_sort_a(a) == 1 && a->total_cnt == total_cnt)
		return ;
	if (check_sort_a(a) == 0)
	{
		while (a->head->cluster_cnt == 0 || a->head->cluster_cnt == -1)
			rra(a);
		if (1 <= a->head->cluster_cnt && a->head->cluster_cnt <= 3)
		{
			sort_a(a, b, a->head->cluster_cnt);			
		}
		else
		{
			pivot = get_pivot(a);
			if (pivot.pivot1 != 0 || pivot.pivot2 != 0)
			{
				divide_stack_a(a, b, pivot.pivot1, pivot.pivot2);
			}
		}
		test_point = 0;
	}
	else      //a가 다 정렬되었을때 이쪽으로 b를 정리
	{
		if (b->head->cluster_cnt <= 3)
		{
			sort_b(a, b, b->head->cluster_cnt);
		}
		else
		{
			pivot = get_pivot(b);
			if (pivot.pivot1 != 0 || pivot.pivot2 != 0)
			{
				divide_stack_b(a, b, pivot.pivot1, pivot.pivot2);
			}
		}
	}
	divide_stack_recur(a, b, total_cnt);
		//3등분?
	//a에는 가장 무거운거
	//b에는 |2 1순서로 넣는다.
	//b의 1을 넣을때는 pb, ra를 하면 됨.
	//b의 두번째 무리를 정렬할때 부터는 이렇게 하지 말고 2를 최하단으로 넣었다가 다시 뺀다
	//2를 pb->rb->///////////rrb(나중) 순으로 정렬한다.
}


int	main(int ac, char **av)
{
	ac = 0;
	**av = 0;
	int	test[23] = {1,40,-1,-2,-15,5,15,20,3,-10,11,-60,2,7,4,-50,-40,-30,6,8,9,10,12};
	int	i;
	t_head *a;
	t_head *b;
	int total_cnt;

	//예외처리들
	//split으로 가져오기	
	//가져온거 a에 집어 넣기
	a = new_head();
	b = new_head();
	i = 0;
	while (i < 23)
	{
		list_add(a, test[i], 0);
		i++;
	}
	a->head->cluster_cnt = 23; // 나중에 갯수 카운팅해서 넣어주면 됨.
	//숫자 카운팅 해줘야함. total_cnt와 lst에 cluster_cnt에도 카운팅 하도록 하자.
	//lstsize() 파악만 되면 굳이 안해줘도 될듯?

	total_cnt = 23;
	divide_stack_recur(a, b, total_cnt);
	
	//말록 해제 했는지 여부 확인
	return (0);
}
