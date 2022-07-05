/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 10:30:54 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/05 15:21:52 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> //지워야함!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

typedef struct linked_list
{
	int					data;
	int					cluster_cnt;
	struct linked_list	*next;
}	t_list;

typedef struct list_head
{
	int					total_cnt;
	struct linked_list	*head;
}	t_head;

typedef struct pivot_struct
{
	int	pivot1;
	int	pivot2;
}	t_pivot;

typedef struct pivot_cnt_struct
{
	int	pivot1_cnt;
	int	pivot2_cnt;
	int	pivot3_cnt;
}	t_pc;

typedef struct print_buf_struct
{
	char	*print_buf;
	int		print_cnt;
}	t_buf;

void	all_free(t_head *h);
void	list_free(t_list *lst);
t_pc	*pivot_cnt_pre_set(t_pc *pivot_cnt);
char	**split_input(char const *s, char c, int *words_cnt);
int		atoi_input(const char *str);

t_head	*new_head(void);
t_head	*list_add(t_head *head, int data, int sort_check);
void	push(t_head *head_in, int data);
int		pull(t_head *head_in);
int		lst_last_data(t_list *lst);

void	pa(t_head *a, t_head *b, t_buf *print_buf);
void	sa(t_head *a, t_buf *print_buf);
void	rra(t_head *a, int sort_check, t_buf *print_buf);
void	ra(t_head *a, t_buf *print_buf);

void	pb(t_head *a, t_head *b, t_buf *print_buf);
void	sb(t_head *b, t_buf *print_buf);
void	rrb(t_head *b, int sort_check, t_buf *print_buf);
void	rb(t_head *b, t_buf *print_buf);

void	sort_a_case_1(t_head *a, t_head *b, t_buf *print_buf);
void	sort_a_case_2(t_head *a, t_head *b, t_buf *print_buf);
void	sort_a_case_3(t_head *a, t_buf *print_buf);
void	sort_a_case_4(t_head *a, t_buf *print_buf);
void	sort_a_case_5(t_head *a, t_buf *print_buf);

void	sort_b_case_1(t_head *a, t_head *b, t_buf *print_buf);
void	sort_b_case_2(t_head *a, t_head *b, t_buf *print_buf);
void	sort_b_case_3(t_head *a, t_head *b, t_buf *print_buf);
void	sort_b_case_4(t_head *a, t_head *b, t_buf *print_buf);
void	sort_b_case_5(t_head *a, t_head *b, t_buf *print_buf);

void	sort_a(t_head *a, t_head *b, int size, t_buf *print_buf);
void	sort_b(t_head *a, t_head *b, int size, t_buf *print_buf);
void	write_sort_complete_a(t_head *a, int size);
int		*int_loc(int size, t_pivot *pivot);
int		check_asc_sort_a(t_head *a, int size);

void	sort_a_optimize(t_head *a, t_buf *print_buf);
void	sort_a_optimize_case1(t_head *a, t_buf *print_buf);
void	sort_a_optimize_case2(t_head *a, t_buf *print_buf);
void	sort_a_optimize_case3(t_head *a, t_buf *print_buf);
void	sort_a_optimize_case4(t_head *a, t_buf *print_buf);
void	sort_a_optimize_case5(t_head *a, t_buf *print_buf);

int		strsize(char *s);

void	divide_stack_a_pivot1(t_head *a, t_head *b, int *p_cnt1, t_buf *buf);
void	divide_stack_a_pivot2(t_head *a, t_head *b, int *p_cnt2, t_buf *buf);
void	divide_stack_a_pivot3(t_head *a, int *p_cnt3, t_buf *buf);
void	divide_stack_a(t_head *a, t_head *b, t_pivot pivot, t_buf *buf);

void	divide_stack_b_pivot1(t_head *b, int *p_cnt1, t_buf *buf);
void	divide_stack_b_pivot2(t_head *a, t_head *b, int *p_cnt2, t_buf *buf);
void	divide_stack_b_pivot3(t_head *a, t_head *b, int *p_cnt3, t_buf *buf);
void	divide_stack_b(t_head *a, t_head *b, t_pivot pivot, t_buf *buf);

int		check_desc_sort_b(t_head *b, int size);
int		check_asc_sort_a(t_head *a, int size);
int		*sort_arr(int size, int *sort);
int		check_sort_a(t_head *a);

t_pivot	get_pivot(t_head *a);
void	divide_stack_recur(t_head *a, t_head *b, int total_cnt, t_buf *buf);

t_buf	*initial_print_buf(void);
void	insert_print_buf(t_buf *buf, char *str);
void	print_all(char const *s);
void	print_free(t_buf *buf);

void	sort_a_optimize(t_head *a, t_buf *print_buf);

#endif