/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmem_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:09:19 by asioud            #+#    #+#             */
/*   Updated: 2022/12/20 13:09:20 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int32_t	ft_putmem_fd(size_t *ptr, int32_t fd)
{
	if (!ptr)
		return (ft_putstr_fd(NULL_OUTPUT, fd));
	return (ft_putstr_fd("0x", fd) + ft_hex_fd((uint64_t)ptr, fd));
}
