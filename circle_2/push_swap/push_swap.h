/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 10:30:54 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/01 16:03:50 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

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

t_head	*new_head(void);
t_head	*list_add(t_head *head, int data, int sort_check);
void	push(t_head *head_in, int data);
void	pull(t_head *head_in, int *pull_data);

void	pa(t_head *a, t_head *b, char *print_buf);
void	sa(t_head *a, char *print_buf);
void	rra(t_head *a, char *print_buf);
void	ra(t_head *a, char *print_buf);

void	pb(t_head *a, t_head *b, char *print_buf);
void	sb(t_head *b, char *print_buf);
void	rrb(t_head *b, char *print_buf);
void	rb(t_head *b, char *print_buf);

void	sort_a_case_1(t_head *a, t_head *b, char *print_buf);
void	sort_a_case_2(t_head *a, t_head *b, char *print_buf);
void	sort_a_case_3(t_head *a, t_head *b, char *print_buf);
void	sort_a_case_4(t_head *a, t_head *b, char *print_buf);
void	sort_a_case_5(t_head *a, t_head *b, char *print_buf);

void	sort_b_case_1(t_head *a, t_head *b, char *print_buf);
void	sort_b_case_2(t_head *a, t_head *b, char *print_buf);
void	sort_b_case_3(t_head *a, t_head *b, char *print_buf);
void	sort_b_case_4(t_head *a, t_head *b, char *print_buf);
void	sort_b_case_5(t_head *a, t_head *b, char *print_buf);

void	sort_a(t_head *a, t_head *b, int size, char *print_buf);
void	sort_b(t_head *a, t_head *b, int size, char *print_buf);
int		*int_loc(int size, t_pivot *pivot);
int		check_asc_sort_a(t_head *a, int size);

int		strsize(char *s);
char	*insert_print_buf(char *print_buf, char *str);
void	all_free(t_head *h);
void	list_free(t_list *lst);



#endif