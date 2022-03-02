/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_padding_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tratanat <tawan.rtn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 09:05:47 by tratanat          #+#    #+#             */
/*   Updated: 2022/03/01 09:17:17 by tratanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "ft_printf_bonus.h"

void	padding_space(char *output, int padding)
{
	if (!(printf_flags(-1) & 1))
		while (padding--)
			write(1, " ", 1);
	ft_putstr_fd(output, 1);
	if (printf_flags(-1) & 1)
		while (padding--)
			write(1, " ", 1);
}
