/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tratanat <tawan.rtn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 14:17:37 by tratanat          #+#    #+#             */
/*   Updated: 2022/03/02 15:56:11 by tratanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "ft_printf_bonus.h"

int	ft_printf(const char *str, ...)
{
	va_list	arg_ptr;
	int		length;
	int		flag_offset;

	length = 0;
	va_start(arg_ptr, str);
	while (*str)
	{
		if (*str == '%')
		{
			p_precision(0);
			printf_flags(-2);
			flag_offset = get_flags(++str);
			str = str + flag_offset;
			length += ft_printarg(*str, arg_ptr);
			str++;
			continue ;
		}
		write(1, str, 1);
		length++;
		str++;
	}
	va_end(arg_ptr);
	return (length);
}

int	get_flags(const char *str)
{
	int	offset;
	int	precision;

	offset = assign_flags(str);
	str = str + offset;
	if (*str == '.')
	{
		offset++;
		printf_flags(2);
		precision = ft_atoi(++str);
		if (precision > 0)
			p_precision(precision);
		if (ft_isdigit(*str))
			offset += getdigit(precision);
	}
	return (offset);
}

int	ft_printarg(const char flag, va_list arg_ptr)
{
	if (flag == 'c')
		return (printf_char(va_arg(arg_ptr, int)));
	else if (flag == 's')
		return (printf_string(va_arg(arg_ptr, char *)));
	else if (flag == 'p')
		return (ft_printadd_hex(va_arg(arg_ptr, void *)));
	else if (flag == 'd' || flag == 'i')
		return (ft_printint(va_arg(arg_ptr, int)));
	else if (flag == 'u')
		return (ft_putnbr_u(va_arg(arg_ptr, unsigned int), 1));
	else if (flag == 'x')
		return (ft_printhex_low(va_arg(arg_ptr, long int)));
	else if (flag == 'X')
		return (ft_printhex_up(va_arg(arg_ptr, long int)));
	else if (flag == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (0);
}

// Flags =	[5:numeric_sign][4:prepend_space][3:hex_prefix]
//			[2:precision][1:prepend_zero][0:left-align]
int	assign_flags(const char *str)
{
	int	flag_res;
	int	offset;
	int	width;

	offset = 0;
	printf_flags(-2);
	flag_res = check_flags(*str);
	while (flag_res >= 0)
	{
		printf_flags(flag_res);
		flag_res = check_flags(*(++str));
		offset++;
	}
	width = ft_atoi(str);
	if (width)
	{
		printf_flags((width << 6));
		offset += getdigit(width);
	}
	return (offset);
}

int	printf_flags(int flag)
{
	static int	form_flags = 0;

	if (flag == -2)
		form_flags = 0;
	if (flag >= 0 && flag < 6)
		form_flags = form_flags | (1 << flag);
	else if (flag >= 6)
		form_flags = form_flags | flag;
	else if (flag == -1)
		return (form_flags);
	return (0);
}

int	check_flags(char c)
{
	if (c == '-')
		return (0);
	if (c == '0')
		return (1);
	if (c == '#')
		return (3);
	if (c == ' ')
		return (4);
	if (c == '+')
		return (5);
	return (-1);
}

int	p_precision(int precision)
{
	static int	form_precision = 0;

	if (precision == -1)
		return (form_precision);
	form_precision = precision;
	return (0);
}
