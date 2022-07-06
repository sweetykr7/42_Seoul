/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joey <joey@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:30:45 by sooyokim          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/07/06 17:08:48 by sooyokim         ###   ########.fr       */
=======
/*   Updated: 2022/07/05 18:36:46 by joey             ###   ########.fr       */
>>>>>>> 5bacde3b30f7f8306311c73242efe815a428b1b9
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "util_list.c"
#include "util_stack.c"
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
#include "util_input1.c"
#include "util_input2.c"
#include "util_sort_a_optimize_case.c"
#include "util_sort_a_optimize.c"

//#include <stdio.h>



// int	main(int ac, char **av)
// {
// 	ac = 0;
// 	**av = 0;
// 	//int	test[23] = {1,40,-1,-2,-15,5,15,20,3,-10,11,-60,2,7,4,-50,-40,-30,6,8,9,10,12};
// 	//int	test[4] = {1,40,-1,-2};
// 	int	test[5] = {1,40,-1,-2,-15};
// 	int cnt;
// 	int	i;
// 	t_head *a;
// 	t_head *b;
// 	char	*print_buf;
// 	int total_cnt;
// 	t_list *temp;

// 	//예외처리들
// 	//split으로 가져오기	
// 	//가져온거 a에 집어 넣기

// 	print_buf = (char *)malloc(sizeof(char) * 1);
// 	if (!print_buf)
// 		return (0);
// 	print_buf[0] = '\0';
// 	a = new_head();
// 	b = new_head();
// 	i = 0;
// 	cnt = 5;
// 	while (i < cnt)
// 	{
// 		list_add(a, test[i], 0);
// 		i++;
// 	}
// 	a->head->cluster_cnt = cnt; // 나중에 갯수 카운팅해서 넣어주면 됨.
// 	//숫자 카운팅 해줘야함. total_cnt와 lst에 cluster_cnt에도 카운팅 하도록 하자.
// 	//lstsize() 파악만 되면 굳이 안해줘도 될듯?
// 	total_cnt = cnt;
// 	divide_stack_recur(a, b, total_cnt, print_buf);
// 	i = 0;
// 	temp = a->head;
// 	while (i < total_cnt)
// 	{
// 		printf("check list [%d] : %d \n",i,temp->data);
// 		i++;
// 		if(temp->next)
// 			temp = temp->next;
// 	}
// 	printf("complete\n");
// 	all_free(a);
// 	all_free(b);
// 	printf("complete\n");
// 	return (0);
// }


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

int	get_number(char	**av, int ac, t_head *a)
{	
	char	**input;
	int		i;
	int		j;
	int		words_cnt;

	i = 1;
	j = 0;
	while (i < ac)
	{
		input = split_input(av[i], ' ', &words_cnt);
		while (j < words_cnt)
		{
			list_add(a, atoi_input(input[j]), 0);
			free(input[j]);
			j++;
		}
		free(input);
		j = -1;
		j = 0;
		i++;
	}
	return (1);
}

int main(int ac, char **av)
{
	t_head	*a;
	t_head	*b;
	//t_list	*temp;
	t_buf	*buf;
	//int		i;

	a = new_head();
	b = new_head();
	buf = initial_print_buf();
	//av[1] = "80 55 10 5 63 14 92 43 64 90 57 67 52 98 40 77 56 83 76 87 7 72 66 21 97 49 68 3 16 30 4 59 22 60 78 58 20 81 44 35 74 6 12 24 82 37 19 32 26 47 39 100 51 62 41 79 86 54 93 48 84 31 45 38 69 46 11 95 13 70 73 18 61 27 96 2 65 15 71 34 99 17 1 89 85 42 50 9 28 8 53 88 25 29 94 23 36 91 75 33";
	//av[1] = "39 40 36 18 33 14 4 27 11 28 19 17 2 35 24 13 30 16 6 32 15 21 25 31 22 12 10 20 37 7 29 1 23 3 5 9 34 38 8 26";
	//av[1] = "2 1 3 6 5 8";
	//av[1] = "5 2 3 1 4";
	//av[1] = "3 22 12 16 1 2 21 11 19 14 6 13 18 10 9 20 8 23 5 24 17 25 15 4 7"
	//av[1] = "3 2 1";
	// av[2] = "3";
	// av[3] = "1";
	// av[4] = "1 30 100 -100 200";
	//av[1] = "1 14 15 20 12 8 4 11 17 18 7 5 16 2 6 9 10 3 13 19";
	//av[1] = "15 11 17 7 18 16 2 13 12 14 20 4 10 5 3 1 9 8 6 19";
	av[1] = "25 4 1 34 20 15 23 32 18 33 30 36 22 6 27 5 10 8 40 21 29 9 37 24 12 11 7 14 35 19 3 26 16 38 39 13 17 31 28 2";
	//av[1] = "64 44 21 23 2 3 19 4 40 59 49 98 41 62 100 54 5 27 6 80 88 94 60 51 33 96 76 20 7 74 85 11 71 67 24 79 90 15 35 38 48 45 72 17 25 43 95 36 31 75 61 70 29 91 9 69 84 68 26 18 52 53 14 1 97 28 66 77 56 39 37 12 13 16 78 87 22 86 10 83 73 81 8 58 30 34 50 99 92 63 89 42 93 32 82 55 57 65 47 46 -100";
	//av[1] = "5 4 3 2 1";
<<<<<<< HEAD
	//ac = 2;
=======
	ac = 2;
>>>>>>> 5bacde3b30f7f8306311c73242efe815a428b1b9
	get_number(av, ac, a);
	a->head->cluster_cnt = a->total_cnt;
	divide_stack_recur(a, b, a->total_cnt, buf);
	//printf("print buf test : %s\n", buf->print_buf);
	// 아랫부분 테스트용
	//print_all(buf->print_buf);
	// write(1,"s",1);
	// write(1,"a",1);
	// write(1,"\n",1);
<<<<<<< HEAD
	print_buf_out(buf);
	// temp = a->head;
	// i = 1;
	// while (i <= a->total_cnt)
	// {
	// 	printf("check list [%d] : %d \n",i,temp->data);
	// 	i++;
	// 	if (temp->next)
	// 		temp = temp->next;
	// 	else
	// 		break;
	// }
	// printf("complete\n");
	
=======
	temp = a->head;
	i = 1;
	while (i <= a->total_cnt)
	{
		printf("check list [%d] : %d \n",i,temp->data);
		printf("cluster cnt [%d] : %d \n",i,temp->cluster_cnt);
		i++;
		if (temp->next)
			temp = temp->next;
		else
			break;
	}
	printf("complete\n");
>>>>>>> 5bacde3b30f7f8306311c73242efe815a428b1b9
	all_free(a);
	all_free(b);
	free_print_buf(buf);
	//print_free(buf);
	//printf("complete\n");
	return (0);
}


// int main(int ac, char **av)
// {
// 	ac = 0;
// 	(void)av;

// 	write(1, "sa\n", 3);
// }
