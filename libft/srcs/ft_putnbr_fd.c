/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:09:24 by asioud            #+#    #+#             */
/*   Updated: 2022/12/20 13:09:26 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int32_t	ft_putnbr_fd(int32_t nbr, int32_t fd)
{
	char	c;
	size_t	i;

	i = 0;
	if (nbr == -2147483648)
		return (ft_putstr_fd("-2147483648", fd), 11);
	else if (nbr < 0)
	{
		i += ft_putchar_fd('-', fd);
		nbr = ft_abs(nbr);
	}
	if (nbr >= 10)
	{
		i += ft_putnbr_fd(nbr / 10, fd);
		i += ft_putnbr_fd(nbr % 10, fd);
	}
	else if (nbr < 10 && nbr != -2147483648)
	{
		c = nbr + '0';
		i += ft_putchar_fd(c, fd);
	}
	return (i);
}
