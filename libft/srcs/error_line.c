/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:06:16 by asioud            #+#    #+#             */
/*   Updated: 2022/12/20 13:06:18 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	error_line(char *msg, int32_t line, char *file, int32_t exit_nbr)
{
	ft_printf_fd(STDERR_FILENO, "%s @ %s %s", msg, line, file);
	if (exit_nbr >= 0)
		exit(exit_nbr);
}
