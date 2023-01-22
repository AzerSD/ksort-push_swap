/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:08:27 by asioud            #+#    #+#             */
/*   Updated: 2022/12/20 13:08:28 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int32_t	ft_memcmp(const void *ptr1, const void *ptr2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (((uint8_t *)ptr1)[i] == ((uint8_t *)ptr2)[i] && i < n - 1)
		i++;
	return (((uint8_t *)ptr1)[i] - ((uint8_t *)ptr2)[i]);
}
