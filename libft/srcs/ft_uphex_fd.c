/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uphex_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:11:34 by asioud            #+#    #+#             */
/*   Updated: 2022/12/20 13:11:35 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int32_t	ft_uphex_fd(uint32_t nbr, int32_t fd)
{
	int32_t		i;
	const char	hexbase[] = "0123456789ABCDEF";

	i = 0;
	if (nbr >= 16)
	{
		i += ft_uphex_fd(nbr / 16, fd);
		i += ft_uphex_fd(nbr % 16, fd);
	}
	if (nbr < 16)
		i += ft_putchar_fd(hexbase[nbr], fd);
	return (i);
}
