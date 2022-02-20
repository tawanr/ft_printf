/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tratanat <tawan.rtn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 14:17:37 by tratanat          #+#    #+#             */
/*   Updated: 2022/02/20 17:36:06 by tratanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *str, ...)
{
	va_list	arg_ptr;
	int	length;

	length = 0;
	va_start(arg_ptr, str);
	while (*str)
	{
		if (*str == '%')
		{
			ft_printarg(*(++str), arg_ptr);
		}
		else
		{
			write(1, str, 1);
		}
		str++;
		length++;
	}
	va_end(arg_ptr);
	return (length);
}

void	ft_printarg(const char flag, va_list arg_ptr)
{
	if (flag == 'c')
		ft_putchar_fd(va_arg(arg_ptr, int), 1);
	else if (flag == 's')
		ft_putstr_fd(va_arg(arg_ptr, char *), 1);
	else if (flag == 'p')
		ft_printadd_hex(va_arg(arg_ptr, void *));
	else if (flag == 'd' || flag == 'i')
		ft_putnbr_fd(va_arg(arg_ptr, int), 1);
	else if (flag == 'u')
		ft_putnbr_u(va_arg(arg_ptr, unsigned int), 1);
	else if (flag == 'x')
		ft_printhex_low(va_arg(arg_ptr, int));
	else if (flag == 'X')
		ft_printhex_up(va_arg(arg_ptr, int));
	else if (flag == '%')
		write(1, "%", 1);
	else
		return ;
	return ;
}

void	ft_printadd_hex(void *ptr)
{
	write(1, "0x10", 4);	
	ft_putstr_fd(ft_itoa_base((int)ptr, 16), 1);
}

void	ft_printhex_low(int ptr)
{
	unsigned long	hex;
	int	negative_num;
	char	*result;

	negative_num = 0xFFFFFFFF;
	if (ptr < 0)
	{
		ptr = -ptr;
		hex = (unsigned long)((ptr ^ negative_num) + 1);
	}
	else
		hex = (unsigned long)ptr;
	result = ft_itoa_base((int)hex, 16);
	ft_putstr_fd(result + (ft_strlen(result) - 8), 1);
	free(result);
}

void	ft_printhex_up(int ptr)
{
	unsigned long	hex;
	int	negative_num;
	char	*result;
	size_t	i;

	negative_num = 0xFFFFFFFF;
	if (ptr < 0)
	{
		ptr = -ptr;
		hex = (unsigned long)((ptr ^ negative_num) + 1);
	}
	else
		hex = (unsigned long)ptr;
	result = ft_itoa_base((int)hex, 16);
	i = 0;
	while (i < ft_strlen(result))
	{
		result[i] = ft_toupper(result[i]);
		i++;
	}
	ft_putstr_fd(result + (ft_strlen(result) - 8), 1);
	free(result);
}

void	ft_putnbr_u(unsigned int n, int fd)
{
	char	*out;
	int	i;

	out = ft_itoa_u(n);
	i = 0;
	write(fd, out, ft_strlen(out));
	free(out);
}