/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 10:21:29 by sooyokim          #+#    #+#             */
/*   Updated: 2022/06/21 16:31:51 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	check_bit_len(unsigned char c)
{
	if (c >= 10 && c <= 13)
	{
		g_data.msg_set[2] = '\0';
		return (2);
	}
	else if (c == 14)
	{
		g_data.msg_set[3] = '\0';
		return (3);
	}
	else if (c == 15)
	{
		g_data.msg_set[4] = '\0';
		return (4);
	}
	g_data.msg_set[1] = '\0';
	return (1);
}

unsigned char	rev_msg(int option)
{
	int				len;
	unsigned char	temp;
	unsigned char	temp_rev;

	temp = g_data.msg;
	temp_rev = 0;
	len = 8;
	while (len != 0)
	{
		temp_rev = (temp_rev << 1) + (temp % 2);
		temp = temp / 2;
		len--;
	}
	if (option == 2)
		g_data.msg = 0;
	return (temp_rev);
}

void	print_msg(siginfo_t *act_result)
{
	if (g_data.msg_set[0] == 127)
	{
		kill(act_result->si_pid, SIGUSR1);
		ft_putchar_fd('\n', 1);
	}
	else
		write(1, g_data.msg_set, g_data.bit_len);
	g_data.msg = 0;
	g_data.cnt = 0;
	g_data.bit_len = 0;
}

void	act_handler(int sig, siginfo_t *act_result, void *a)
{
	(void)a;
	if (sig == SIGUSR1)
		g_data.msg = (g_data.msg << 1) + 1;
	else
		g_data.msg = g_data.msg << 1;
	g_data.cnt++;
	if (g_data.cnt == 8)
		g_data.bit_len = check_bit_len(rev_msg(1) / 16);
	if ((g_data.cnt % 8) == 0)
		g_data.msg_set[(g_data.cnt / 8) - 1] = rev_msg(2);
	if (g_data.cnt == 8 * g_data.bit_len)
		print_msg(act_result);
}

int	main(void)
{
	struct sigaction	act;
	char				*pid;

	g_data.msg = 0;
	pid = ft_itoa(getpid());
	act.sa_sigaction = act_handler;
	act.sa_flags = SIGINFO;
	sigemptyset(&(act.sa_mask));
	ft_putstr_fd("PID : ", 1);
	ft_putstr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	free(pid);
	while (1)
	{		
		sigaction(SIGUSR1, &act, NULL);
		sigaction(SIGUSR2, &act, NULL);
		pause();
	}
	return (0);
}
