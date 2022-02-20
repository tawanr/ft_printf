/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tratanat <tawan.rtn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 14:25:27 by tratanat          #+#    #+#             */
/*   Updated: 2022/02/20 19:44:24 by tratanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int	ft_printf(const char *, ...);
int	ft_printarg(const char flag, va_list arg_ptr);
char	*ft_itoa_u(unsigned int n);
int	ft_putnbr_u(unsigned int n, int fd);
char	*ft_itoa_base(unsigned int n, int base);
int	ft_printhex_up(int ptr);
int	ft_printhex_low(int ptr);
int	ft_printadd_hex(unsigned long *ptr);
int	getdigit_base(unsigned long n, int base);

#endif