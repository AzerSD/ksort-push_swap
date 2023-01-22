/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:08:59 by asioud            #+#    #+#             */
/*   Updated: 2022/12/20 13:09:01 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../includes/libft.h"

static	int32_t	ft_cases(const char chr, va_list argp, \
								int32_t count, int32_t fd)
{
	if (!argp)
		return (0);
	if (chr == 'c')
		count += ft_putchar_fd(va_arg(argp, int32_t), fd);
	if (chr == 's')
		count += ft_putstr_fd(va_arg(argp, char *), fd);
	if (chr == '%')
		count += ft_putchar_fd('%', fd);
	if (chr == 'i' || chr == 'd')
		count += ft_putnbr_fd(va_arg(argp, int32_t), fd);
	if (chr == 'u')
		count += ft_uputnbr_fd(va_arg(argp, uint32_t), fd);
	if (chr == 'p')
		count += ft_putmem_fd(va_arg(argp, size_t *), fd);
	if (chr == 'x')
		count += ft_hex_fd(va_arg(argp, uint32_t), fd);
	if (chr == 'X')
		count += ft_uphex_fd(va_arg(argp, uint32_t), fd);
	return (count);
}

int32_t	ft_printf_fd(int32_t fd, const char *str, ...)
{
	va_list	argp;
	size_t	count;

	count = 0;
	va_start(argp, str);
	while (*str)
	{
		if (*str == '%')
		{	
			str++;
			count = ft_cases(*str, argp, count, fd);
		}
		else
			count += ft_putchar_fd(*str, fd);
		str++;
	}
	return (count);
}
