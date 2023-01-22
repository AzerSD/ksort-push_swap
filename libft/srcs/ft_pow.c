/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:08:49 by asioud            #+#    #+#             */
/*   Updated: 2022/12/20 13:08:51 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_pow(int64_t base, int32_t power)
{
	int32_t	i;
	int64_t	nbr;

	i = 1;
	nbr = base;
	if (power == 1)
		return (base);
	while (i < power)
	{
		nbr = nbr * base;
		i++;
	}
	return (nbr);
}
