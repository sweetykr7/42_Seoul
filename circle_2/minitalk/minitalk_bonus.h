/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:01:48 by sooyokim          #+#    #+#             */
/*   Updated: 2022/06/21 15:56:29 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct recieve_massage
{
	unsigned char	msg;
	unsigned char	rev_msg;
	int				cnt;
	int				bit_len;
	unsigned char	msg_set[5];
}t_rec_msg;

t_rec_msg	g_data;

#endif