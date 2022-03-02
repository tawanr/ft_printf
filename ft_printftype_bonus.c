/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printftype_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tratanat <tawan.rtn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 22:42:22 by tratanat          #+#    #+#             */
/*   Updated: 2022/03/03 00:49:22 by tratanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "ft_printf_bonus.h"

int	ft_printadd_hex(void *ptr)
{
	char	*out;
	int		printlen;
	int		padding;

	if (ptr == NULL)
		write(1, "(nil)", 5);
	if (ptr == NULL)
		return (5);
	printlen = 2;
	out = ft_itoa_base((unsigned long long int)ptr, 16);
	printlen += ft_strlen(out);
	padding = 0;
	if ((printf_flags(-1) >> 6) > printlen)
		padding = (printf_flags(-1) >> 6) - printlen;
	if ((printf_flags(-1) >> 6) > printlen)
		printlen = printf_flags(-1) >> 6;
	if (!(printf_flags(-1) & 1) && padding > 0)
		while (padding-- > 0)
			write(1, " ", 1);
	write(1, "0x", 2);
	ft_putstr_fd(out, 1);
	while (padding-- > 0)
		write(1, " ", 1);
	free(out);
	return (printlen);
}

int	ft_printhex_low(long int ptr)
{
	unsigned int	hex;
	char			*result;
	int				length;
	int				padding;

	padding = printf_flags(-1) >> 6;
	if (ptr == 0)
	{
		if (!(printf_flags(-1) & 1))
			prepad_num(printf_flags(-1), padding - 1, 1, p_precision(-1) - 1);
		write(1, "0", 1);
		while (padding-- > 1 && printf_flags(-1) & 1)
			write(1, " ", 1);
		if (printf_flags(-1) >> 6)
			return (printf_flags(-1) >> 6);
		return (1);
	}
	if (ptr < 0)
		hex = (unsigned long int)(((-ptr) ^ 0xFFFFFFFF) + 1);
	else
		hex = (unsigned long int)ptr;
	result = ft_itoa_base(hex, 16);
	length = printf_hex(result, 0);
	free(result);
	return (length);
}

int	ft_printhex_up(long int ptr)
{
	unsigned int	hex;
	char			*result;
	size_t			i;
	int				length;
	int				padding;

	padding = 0;
	padding = printf_flags(-1) >> 6;
	if (ptr == 0)
	{
		if (!(printf_flags(-1) & 1))
			prepad_num(printf_flags(-1), padding - 1, 1, p_precision(-1) - 1);
		write(1, "0", 1);
		while (padding-- > 1 && printf_flags(-1) & 1)
			write(1, " ", 1);
		if (printf_flags(-1) >> 6)
			return (printf_flags(-1) >> 6);
		return (1);
	}
	if (ptr < 0)
		hex = (unsigned long int)(((-ptr) ^ 0xFFFFFFFF) + 1);
	else
		hex = (unsigned long int)ptr;
	result = ft_itoa_base(hex, 16);
	i = -1;
	while (++i < ft_strlen(result))
		result[i] = ft_toupper(result[i]);
	length = printf_hex(result, 1);
	free(result);
	return (length);
}

int	ft_putnbr_u(unsigned int n, int fd)
{
	char	*out;
	int		digits;
	int		i;
	int		padding;
	int		flags;

	i = -1;
	padding = 0;
	flags = printf_flags(-1);
	out = ft_itoa_u(n);
	digits = ft_strlen(out);
	if (flags & (1 << 2))
		if (p_precision(-1) > digits)
			digits = p_precision(-1);
	if ((flags >> 6) > digits)
		padding = (flags >> 6) - digits;
	if (!(flags & 1))
		prepad_num(flags, padding, 1, digits - ft_strlen(out));
	while (++i < (int)ft_strlen(out))
		write(fd, out + i, 1);
	i += (digits - ft_strlen(out)) + padding;
	if (flags & 1)
		while (padding-- > 0)
			write(1, " ", 1);
	free(out);
	return (i);
}

int	ft_printint(long int num)
{
	int		pos;
	char	*output;
	int		padding;
	int		length;
	int		flags;

	pos = 1;
	padding = 0;
	flags = printf_flags(-1);
	if (num < 0)
		pos = 0;
	if (num < 0)
		num = -num;
	output = ft_itoa(num);
	length = ft_strlen(output);
	if ((flags & (1 << 2)) && p_precision(-1) > length)
		length = p_precision(-1);
	if ((flags >> 6) > length)
		padding = (printf_flags(-1) >> 6) - length;
	else
		length += !!((flags & (1 << 4)) || (flags & (1 << 5)) || !pos);
	if ((flags & (1 << 2)) || (flags & (1 << 1)) || !(flags & 1))
		prepad_num(flags, padding, pos, p_precision(-1) - ft_strlen(output));
	else
		prepad_num(flags, 0, pos, p_precision(-1) - ft_strlen(output));
	if (num != 0 || (!(flags & (1 << 2)) || \
	((p_precision(-1) > 0) && num == 0)))
		ft_putstr_fd(output, 1);
	else if (num == 0 && p_precision(-1) == 0 && (flags >> 6) > 0)
		write(1, " ", 1);
	free(output);
	length += padding;
	if ((flags & 1) && !(flags & (1 << 1)))
		while ((padding-- > !pos || flags & (1 << 5) || flags & (1 << 4)))
			write(1, " ", 1);
	return (length);
}
