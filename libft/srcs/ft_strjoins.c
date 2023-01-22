/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:10:34 by asioud            #+#    #+#             */
/*   Updated: 2022/12/20 13:10:35 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdarg.h>
#include <stdio.h>

char	*ft_strjoins(char *join(), ...)
{
	size_t	len;
	char	*out;
	char	*str;
	va_list	argp;

	va_start(argp, join);
	str = va_arg(argp, char *);
	len = ft_strlen(str);
	out = ft_strdup("");
	while (str)
	{
		out = join(out, str);
		str = va_arg(argp, char *);
		if (str)
			len += ft_strlen(str);
	}
	return (out);
}
