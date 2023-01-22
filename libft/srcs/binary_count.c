/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:05:57 by asioud            #+#    #+#             */
/*   Updated: 2022/12/20 13:05:59 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	binary_count(size_t lst_size)
{
	size_t	bin_count;

	bin_count = 0;
	while (lst_size)
	{
		lst_size >>= 1;
		bin_count++;
	}
	return (bin_count);
}
