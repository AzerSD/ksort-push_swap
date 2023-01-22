/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uputnbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:11:41 by asioud            #+#    #+#             */
/*   Updated: 2022/12/20 13:11:42 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int32_t	ft_uputnbr_fd(uint32_t nbr, int32_t fd)
{
	int32_t	i;
	char	c;

	i = 0;
	if (nbr >= 10)
	{
		i += ft_uputnbr_fd(nbr / 10, fd);
		i += ft_uputnbr_fd(nbr % 10, fd);
	}
	if (nbr < 10)
	{
		c = nbr + '0';
		i += ft_putchar_fd(c, fd);
	}
	return (i);
}
