/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagformat_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tratanat <tawan.rtn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 21:39:08 by tratanat          #+#    #+#             */
/*   Updated: 2022/03/02 23:27:16 by tratanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"
#include "libft.h"

int	printf_string(char *result)
{
	int		length;
	int		padding;
	char	*output;

	if (result == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	if (p_precision(-1) < (int)ft_strlen(result) && printf_flags(-1) & (1 << 2))
		length = p_precision(-1);
	else
		length = ft_strlen(result);
	output = (char *)ft_calloc((length + 1), sizeof(char));
	ft_strlcpy(output, result, length + 1);
	padding = 0;
	if ((printf_flags(-1) >> 6) > length)
		padding = (printf_flags(-1) >> 6) - length;
	length += padding;
	padding_space(output, padding);
	free(output);
	return (length);
}

int	printf_char(int c)
{
	int	length;
	int	left_aligned;
	int	min_width;
	int	flags;
	int	padding;

	flags = printf_flags(-1);
	min_width = flags >> 6;
	left_aligned = flags & 1;
	padding = 0;
	if (min_width > 1)
		padding = min_width - 1;
	length = 1 + padding;
	if (!left_aligned)
		while (padding--)
			write(1, " ", 1);
	ft_putchar_fd(c, 1);
	if (left_aligned)
		while (padding--)
			write(1, " ", 1);
	return (length);
}

int	printf_hex(char *result, int upper)
{
	int	min_width;
	int	flags;
	int	padding;
	int	length;

	flags = printf_flags(-1);
	min_width = flags >> 6;
	padding = 0;
	length = ft_strlen(result);
	if (p_precision(-1) > (int)ft_strlen(result))
		length = p_precision(-1);
	if (min_width > length)
		padding = min_width - length;
	if ((flags & (1 << 3)) && padding == 0 && *result != '0')
		padding = 2;
	length += padding;
	if (*result == '0' && ft_strlen(result) == 1)
		prepad_hex(flags, padding, "", p_precision(-1) - ft_strlen(result));
	else if (upper)
		prepad_hex(flags, padding, "0X", p_precision(-1) - ft_strlen(result));
	else
		prepad_hex(flags, padding, "0x", p_precision(-1) - ft_strlen(result));
	ft_putstr_fd(result, 1);
	if (flags & 1)
		while (padding-- > ((flags & (1 << 3)) * 2))
			write(1, " ", 1);
	return (length);
}

void	prepad_hex(int flags, int padding, const char *prefix, int precision)
{
	if (!(flags & 1))
	{
		if (flags & (1 << 3))
		{
			padding -= 2;
			if (!(flags & (1 << 1)))
				while (padding-- > 0)
					write(1, " ", 1);
			write(1, prefix, ft_strlen(prefix));
			while (padding-- > 0)
				write(1, "0", 1);
		}
		else
		{
			while (padding-- > 0)
			{
				if (!(flags & (1 << 1)))
					write(1, " ", 1);
				else
					write(1, "0", 1);
			}
		}
	}
	else if (flags & (1 << 3))
		write(1, prefix, ft_strlen(prefix));
	while (precision-- > 0)
		write(1, "0", 1);
}

void	prepad_num(int flags, int padding, int positive, int precision)
{
	char	sign[3];

	sign[0] = '-';
	sign[1] = '+';
	sign[2] = ' ';
	if (flags & (1 << 5) && (flags & (1 << 1)))
		write(1, &sign[positive], 1);
	else if (flags & (1 << 4) && (flags & (1 << 1)))
		write(1, &sign[positive * 2], 1);
	else if (!positive && (flags & (1 << 1)))
		write(1, &sign[positive], 1);
	padding -= (!positive || flags & (1 << 5) || flags & (1 << 4));
	while (padding-- > 0)
	{
		if (flags & (1 << 1))
			write(1, "0", 1);
		else if (!(flags & 1) && !(flags & (1 << 1)))
			write(1, " ", 1);
	}
	if (flags & (1 << 5) && !(flags & (1 << 1)))
		write(1, &sign[positive], 1);
	else if (flags & (1 << 4) && !(flags & (1 << 1)))
		write(1, &sign[positive * 2], 1);
	else if (!positive && !(flags & (1 << 1)))
		write(1, &sign[positive], 1);
	while (precision-- > 0)
		write(1, "0", 1);
}
