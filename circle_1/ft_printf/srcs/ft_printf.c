/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:35:35 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/15 13:31:23 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(va_list ap, char *format)
{
	int	res;

	res = 0;
	if (*format == 'c')
		res = ft_print_chr(va_arg(ap, int));
	else if (*format == 's')
		res = ft_print_str(va_arg(ap, char *));
	else if (*format == 'p')
		res = ft_print_void_hexa(va_arg(ap, unsigned long long));
	else if (*format == 'x')
		res = ft_print_lower_hexa(va_arg(ap, unsigned int));
	else if (*format == 'X')
		res = ft_print_upper_hexa(va_arg(ap, unsigned int));
	else if (*format == 'u')
		res = ft_print_unsigned_num(va_arg(ap, unsigned int));
	else if (*format == 'd' || *format == 'i')
		res = ft_print_num(va_arg(ap, int));
	else if (*format == '%')
		res = ft_print_percent();
	return (res);
}

int	parse_format(va_list ap, char *format)
{
	int	res;

	res = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (!(*format))
				break ;
			res = res + print_format(ap, format);
		}
		else
		{
			ft_putchar_fd(*format, 1);
			res++;
		}
		format++;
	}
	return (res);
}

int	ft_printf(const char *format, ...)
{
	int		res;
	va_list	ap;

	res = 0;
	va_start(ap, format);
	res = parse_format(ap, (char *)format);
	va_end(ap);
	return (res);
}
