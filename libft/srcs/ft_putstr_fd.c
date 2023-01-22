/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:09:29 by asioud            #+#    #+#             */
/*   Updated: 2022/12/20 13:09:30 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int32_t	ft_putstr_fd(char *str, int32_t fd)
{
	if (!str)
		return (ft_putstr_fd("(null)", fd));
	return (write(fd, str, ft_strlen(str)));
}
