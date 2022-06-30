/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 10:30:54 by sooyokim          #+#    #+#             */
/*   Updated: 2022/06/30 11:17:57 by sooyokim         ###   ########.fr       */
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
t_head	*list_add(t_head *head, int data);
t_head	*push(t_head *head_in, int data);
t_head	*pull(t_head *head_in, int *pull_data);

void	pa(t_head *a, t_head *b);
void	sa(t_head *a);
void	rra(t_head *a);
void	ra(t_head *a);

void	pb(t_head *a, t_head *b);
void	sb(t_head *b);
void	rrb(t_head *b);
void	rb(t_head *b);

void	sort_a_case_1(t_head *a, t_head *b);
void	sort_a_case_2(t_head *a, t_head *b);
void	sort_a_case_3(t_head *a, t_head *b);
void	sort_a_case_4(t_head *a, t_head *b);
void	sort_a_case_5(t_head *a, t_head *b);

void	sort_b_case_1(t_head *a, t_head *b);
void	sort_b_case_2(t_head *a, t_head *b);
void	sort_b_case_3(t_head *a, t_head *b);
void	sort_b_case_4(t_head *a, t_head *b);
void	sort_b_case_5(t_head *a, t_head *b);

void	sort_a(t_head *a, t_head *b, int size);
void	sort_b(t_head *a, t_head *b, int size);
int		*int_loc(int size, t_pivot *pivot);

#endif