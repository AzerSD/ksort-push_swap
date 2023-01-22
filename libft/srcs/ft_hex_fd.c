/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:07:19 by asioud            #+#    #+#             */
/*   Updated: 2023/01/01 05:37:29 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int32_t	ft_hex_fd(uint64_t nbr, int32_t fd)
{
	int32_t		i;
	const char	hexbase[] = "0123456789abcdef";

	i = 0;
	if (nbr == 0)
		i += ft_putchar_fd('0', fd);
	if (nbr >= 16)
	{
		i += ft_hex_fd(nbr / 16, fd);
		i += ft_hex_fd(nbr % 16, fd);
	}
	if (nbr < 16 && nbr != 0)
		i += ft_putchar_fd(hexbase[nbr], fd);
	return (i);
}
