/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:08:22 by asioud            #+#    #+#             */
/*   Updated: 2022/12/20 13:08:24 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *ptr, int32_t c, size_t n)
{
	uint8_t	*ptr2;

	ptr2 = (uint8_t *)ptr;
	while (n-- > 0)
	{
		if (*ptr2 == (uint8_t)c)
			return ((void *)ptr2);
		ptr2++;
	}
	return (0);
}
