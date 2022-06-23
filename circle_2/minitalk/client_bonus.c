/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:06:45 by sooyokim          #+#    #+#             */
/*   Updated: 2022/06/21 15:53:59 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	confirm_msg(void)
{
	ft_putstr_fd("Message is confirmed \n", 1);
}

void	send_msg(int sig, pid_t pid)
{
	if (sig == 1)
	{
		if (kill(pid, SIGUSR1) == -1)
		{
			ft_putstr_fd("PLZ Check the PID", 1);
			exit(1);
		}
	}
	else
	{
		if (kill(pid, SIGUSR2) == -1)
		{
			ft_putstr_fd("PLZ Check the PID", 1);
			exit(1);
		}
	}
	usleep(100);
}

void	send_to_serv(unsigned char c, pid_t pid)
{
	int	res;
	int	cnt;

	res = c;
	cnt = 8;
	while (cnt != 0)
	{
		send_msg(res % 2, pid);
		res = res / 2;
		cnt--;
	}
	c++;
}

int	main(int ac, char **av)
{
	if (ac != 3)
	{	
		ft_putstr_fd("PLZ put 3 parameters(./client <PID> <Message>)", 1);
		return (0);
	}
	if (av[2][0] == '\0')
	{
		ft_putstr_fd("PLZ insert Message", 1);
		return (0);
	}
	signal(SIGUSR1, (void *)confirm_msg);
	while (*av[2])
	{
		send_to_serv(*av[2], ft_atoi(av[1]));
		av[2]++;
	}
	send_to_serv(127, ft_atoi(av[1]));
	return (0);
}
