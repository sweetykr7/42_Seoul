/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:45:12 by sooyokim          #+#    #+#             */
/*   Updated: 2022/04/19 08:50:31 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

int		ft_print_chr(int c);
int		ft_print_str(char *c);
int		ft_print_sign(char c);
int		print_format(va_list ap, char *format);
int		parse_format(va_list ap, char *format);
int		ft_print_void_hexa(unsigned long long num);
int		ft_print_lower_hexa(unsigned int num);
int		ft_print_upper_hexa(unsigned int num);
int		ft_print_unsigned_num(unsigned int num);
int		ft_print_signed_num(int num);
int		ft_print_num(int num);
int		ft_print_percent(void);
int		ft_printf(const char *format, ...);

#endif