/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 10:30:54 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/11 19:27:24 by sooyokim         ###   ########.fr       */
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

typedef struct pivot_cnt_struct
{
	int	pivot1_cnt;
	int	pivot2_cnt;
	int	pivot3_cnt;
}	t_pc;

typedef struct print_buf_struct
{
	char					*print_buf;
	int						total_cnt;
	struct print_buf_struct	*next;
}	t_buf;

typedef struct instruction_struct
{
	char						*ins;
	int							total_cnt;
	struct instruction_struct	*next;
}	t_ins;

int		get_number(char	**av, int ac, t_head *a);

void	head_free(t_head *h);
void	list_free(t_list *lst);
t_pc	*pivot_cnt_pre_set(t_pc *pivot_cnt);
char	**split_input(char *s, char c, int *words_cnt);
int		atoi_input(char *str, int *error);

t_head	*new_head(void);
t_head	*list_add(t_head *head, int data, int sort_check, int *error);
void	push_stack(t_head *head_in, t_list *lst);
t_list	*pull_stack(t_head *head_in);
int		lst_last_data(t_list *lst);

int		push_from_to(t_head *b, t_head *a, t_buf *print_buf, char option);
int		swap(t_head *a, t_buf *print_buf, char option);
int		re_reverse(t_head *a, t_buf *print_buf, char option);
int		reverse(t_head *a, t_buf *print_buf, char option);

int		swap_insert_print_buf(t_buf *print_buf, char option);
int		push_from_to_insert_print_buf(t_buf *print_buf, char option);
int		reverse_insert_print_buf(t_buf *print_buf, char option);
int		re_reverse_insert_print_buf(t_buf *print_buf, char option);

int		push_from_to_checker(t_head *b, t_head *a);
int		swap_checker(t_head *a);
int		re_reverse_checker(t_head *a);
int		reverse_checker(t_head *a);
int		re_reverse_both_checker(t_head *a, t_head *b);
int		reverse_both_checker(t_head *a, t_head *b);
int		swap_both_checker(t_head *a, t_head *b);

int		sort_a_case_1(t_head *a, t_head *b, t_buf *print_buf, int *error);
int		sort_a_case_2(t_head *a, t_head *b, t_buf *print_buf, int *error);
int		sort_a_case_3(t_head *a, t_buf *print_buf, int *error);
int		sort_a_case_4(t_head *a, t_buf *print_buf, int *error);
int		sort_a_case_5(t_head *a, t_buf *print_buf, int *error);

int		sort_b_case_1(t_head *a, t_head *b, t_buf *print_buf, int *error);
int		sort_b_case_2(t_head *a, t_head *b, t_buf *print_buf, int *error);
int		sort_b_case_3(t_head *a, t_head *b, t_buf *print_buf, int *error);
int		sort_b_case_4(t_head *a, t_head *b, t_buf *print_buf, int *error);
int		sort_b_case_5(t_head *a, t_head *b, t_buf *print_buf, int *error);

int		sort_a(t_head *a, t_head *b, int size, t_buf *print_buf);
int		sort_b(t_head *a, t_head *b, int size, t_buf *print_buf);
void	write_sort_complete_a(t_head *a, int size);
int		*int_loc(int size);
int		check_asc_sort_a(t_head *a, int size);

int		sort_optimize_3(t_head *a, t_buf *print_buf);
int		sort_a_optimize_case1(t_head *a, t_buf *print_buf, int *error);
int		sort_a_optimize_case2(t_head *a, t_buf *print_buf, int *error);
int		sort_a_optimize_case3(t_head *a, t_buf *print_buf, int *error);
int		sort_a_optimize_case4(t_head *a, t_buf *print_buf, int *error);
int		sort_a_optimize_case5(t_head *a, t_buf *print_buf, int *error);

int		sort_optimize_5(t_head *a, t_head *b, t_buf *print_buf);

int		strsize(char *s);

int		divide_stack_a(t_head *a, t_head *b, t_pivot pivot, t_buf *buf);
int		divide_stack_b(t_head *a, t_head *b, t_pivot pivot, t_buf *buf);

int		check_desc_sort_b(t_head *b, int size);
int		check_asc_sort_a(t_head *a, int size);
int		*sort_arr(int size, int *sort);
int		check_sort_a(t_head *a);

t_pivot	get_pivot(t_head *a, t_pivot p);
int		get_pivot_mid(t_head *a, int mid);
int		divide_stack_recur(t_head *a, t_head *b, int total_cnt, t_buf *buf);

int		initial_sort_check(t_head *a);
int		process_remain_ra_data(t_head *a, t_buf *buf);

t_buf	*initial_print_buf(void);
int		insert_print_buf(t_buf *buf, char *str);
void	print_buf_out(t_buf *buf);
void	print_buf_free(t_buf *buf);

t_buf	*last_buf(t_buf *buf);
int		find_word_in_list(t_list *lst, int data, int *error);
int		free_char_pointer_and_return_zero(char **a);
int		all_free_with_error(t_head *a, t_head *b, t_buf *buf);
void	all_free(t_head *a, t_head *b, t_buf *buf);

void	print_all(char *s);
void	print_free(t_buf *buf);
t_list	*last_lst(t_list *lst);
t_list	*last_second_lst(t_list *lst);
char	*insert_words(char *str);

t_buf	*algorithm_optimize(t_buf *buf);

int		check_available_r_rr_delete(t_buf *buf, char *s2, char *s3, int *flag);
int		check_available_change_rrr(t_buf *buf, char *s1, char *s2, int *flag);
int		check_available_change_rr(t_buf *buf, char *s1, char *s2, int *flag);
int		check_available_change_ss(t_buf *buf, char *s1, char *s2, int *flag);
int		algorithm_optimize_case(t_buf *buf, char *str1, char *str2, char *str3);

t_buf	*last_second_buf(t_buf *buf);
int		check_words(char *a, char *b);
int		put_error_1_return_zero(int *error);
t_pivot	pivot_initial(void);

int		count_jump_words(t_buf *buf, char *jump_words);
int		jump_check(t_buf *buf, char *jump_words, char *words);
void	free_del_2_3(t_buf *del1, t_buf *del2);

void	del_cnt_change1(t_buf *buf, char *change_words, int cnt, int *flag);
void	del_3_change_1(t_buf *buf, char *change_words, char *str3, int *flag);
void	del_2_change_1(t_buf *buf, char *change_words, char *str2, int *flag);
void	del_2_3(t_buf *buf, char *str2, char *str3, int *flag);

int		all_free_with_error_checker(t_head *a, t_head *b, t_ins *ins_list);
void	all_free_checker(t_head *a, t_head *b);

char	*get_next_line(int fd);
int		instruction_check(char *str);
t_ins	*initial_insturction_struct(void);

t_ins	*insert_instruction(t_ins *ins, char *str);
void	instruction_free(t_ins *ins_list);
int		run_instruction(t_ins *ins_list, t_head *a, t_head *b);

#endif