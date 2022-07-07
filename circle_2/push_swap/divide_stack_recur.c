/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_stack_recur.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 11:48:52 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/07 13:38:29 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_pivot(t_pivot *pivot)
{
	free(pivot);
}


int		check_data_zero(t_head *a, t_head *b)
{
	t_list	*temp;
	int		i;
	
	temp = a->head;
	i = 1;
	while (i <= a->total_cnt)
	{
		if (temp->data == 0)
			return (-1);
		i++;
		if (temp->next)
			temp = temp->next;
		else
			break;
	}

	temp = b->head;
	i = 1;
	while (i <= b->total_cnt)
	{
		if (temp->data == 0)
			return (-2);
		i++;
		if (temp->next)
			temp = temp->next;
		else
			break;
	}

	return (1);
}

int		check_data_zero_one(t_head *a)
{
	t_list	*temp;
	int		i;
	
	temp = a->head;
	i = 1;
	while (i <= a->total_cnt)
	{
		if (temp->data == 0)
			return (-1);
		i++;
		if (temp->next)
			temp = temp->next;
		else
			break;
	}

	return (1);
}

void	divide_stack_a_check(t_head *a, t_head *b, t_pivot *pivot, t_buf *buf)
{
	if (1 <= a->head->cluster_cnt && a->head->cluster_cnt <= 3)
	{
		//printf("pass test7\n");
		sort_a(a, b, a->head->cluster_cnt, buf);
		//printf("pass test8\n");
	}
	else
	{
		//printf("cluster check before test9 : %d\n",a->head->cluster_cnt);
		//printf("pass test9\n");
		pivot = get_pivot(a, pivot);
		//printf("pass test10\n");
		if (pivot->pivot1 != 0 || pivot->pivot2 != 0)
			divide_stack_a(a, b, pivot, buf);
		//printf("pass test11\n");
	}
	free(pivot);
}

void	divide_stack_b_check(t_head *a, t_head *b, t_pivot *pivot, t_buf *buf)
{
	if (b->head->cluster_cnt <= 3)
		sort_b(a, b, b->head->cluster_cnt, buf);
	else
	{
		pivot = get_pivot(b, pivot);
		if (pivot->pivot1 != 0 || pivot->pivot2 != 0)
			divide_stack_b(a, b, pivot, buf);
	}
	free(pivot);
}



void	divide_stack_recur(t_head *a, t_head *b, int total_cnt, t_buf *buf)
{
	t_pivot	*pivot;
	int		check_sort_a_res;
	int		check_data_zero_res;

	check_data_zero_res = check_data_zero(a, b);
	if (check_data_zero_res == -1)
	{
		printf("check_data zero in a!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
		if (a->head && b->head)
		{
			printf("check a total_cnt : %d\n", a->total_cnt);
			printf("check a head data : %d\n", a->head->data);
			printf("check b total_cnt : %d\n", b->total_cnt);
			printf("check b head data : %d\n", b->head->data);
		}
		exit (0);
	}
	if (check_data_zero_res == -2)
	{
		printf("check_data zero in b!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
		if (a->head && b->head)
		{
			printf("check a total_cnt : %d\n", a->total_cnt);
			printf("check a head data : %d\n", a->head->data);
			printf("check b total_cnt : %d\n", b->total_cnt);
			printf("check b head data : %d\n", b->head->data);
		}
		exit (0);
	}
	pivot = malloc(sizeof(t_pivot));
	if (!pivot)
		return ;
	pivot->pivot1 = 0;
	pivot->pivot2 = 0;
	check_sort_a_res = 0;
	check_asc_sort_a(a, a->total_cnt);
	check_sort_a_res = check_sort_a(a);
	//printf("pass check_asc_sort_a\n");
	if (a->total_cnt == total_cnt && check_sort_a_res == 1)
	{
		free(pivot);
		return ;
	}
	if (check_sort_a_res == 2)
	{
		if (a->total_cnt > 0 && b->total_cnt > 0)
		{
			if (lst_last_data(a->head) < b->head->data)
			{
				//printf("pass check_sort_a_res == 2 and lst_last_data(a->head) < b->head->data\n");
				divide_stack_b_check(a, b, pivot, buf);
				divide_stack_recur(a, b, total_cnt, buf);
				return ;
			}
		}
		//printf("pass check_sort_a_res == 2 before while\n");
		while (a->head->cluster_cnt == 0 || a->head->cluster_cnt == -1)
		{
			//printf("in the while\n");
			re_reverse(a, buf, 'a');
		}
		check_sort_a_res = check_sort_a(a);
		//printf("after while + check sort_a");
	}
	if (check_sort_a_res == 0)
	{
		//printf("check_sort_a_res == 0 before divide_stack_a_check\n");
		divide_stack_a_check(a, b, pivot, buf);
		//printf("pass divide_stack_a_check\n");
	}
	else
	{
		//printf("check_sort_a_res == 0 before divide_stack_b_check\n");
		divide_stack_b_check(a, b, pivot, buf);
		//printf("pass divide_stack_b_check\n");
	}
	divide_stack_recur(a, b, total_cnt, buf);
}
