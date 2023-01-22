/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:06:08 by asioud            #+#    #+#             */
/*   Updated: 2023/01/05 07:43:15 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "../includes/libft.h"

void	display_error(char *error_msg, bool yeet)
{
	write(2, error_msg, ft_strlen(error_msg));
	if (yeet == true)
		exit(EXIT_FAILURE);
}
