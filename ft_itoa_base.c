/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tratanat <tawan.rtn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:45:32 by tratanat          #+#    #+#             */
/*   Updated: 2022/02/20 19:36:52 by tratanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	getdigit_base(unsigned long n, int base);
int	ft_abs_base(unsigned int n);

char	*ft_itoa_base(unsigned int n, int base)
{
	int				digit;
	int				negative;
	char			*out;
	int				i;
	unsigned int	num;

	negative = 0;
	num = (unsigned int)(ft_abs_base(n));
	if (n < 0)
		negative = 1;
	digit = getdigit_base(num, base);
	out = (char *)malloc((digit + negative + 1) * sizeof(char));
	if (!out)
		return (NULL);
	i = digit + negative;
	out[i--] = '\0';
	while (i >= negative)
	{
		if (num % base < 10)
			out[i--] = '0' + (num % base);
		else
			out[i--] = 'a' + ((num % base) % 10);
		num /= base;
	}
	if (negative)
		out[0] = '-';
	return (out);
}

int	ft_abs_base(unsigned int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	getdigit_base(unsigned long n, int base)
{
	int	digit;

	digit = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= base;
		digit++;
	}
	return (digit);
}