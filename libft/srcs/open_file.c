/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:37:52 by asioud            #+#    #+#             */
/*   Updated: 2023/01/02 17:50:52 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../includes/libft.h"

int	open_file(char *filename, int i)
{
	int	file;

	file = 0;
	if (i == 0)
		file = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0777);
	else if (i == 1)
		file = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (i == 2)
		file = open(filename, O_RDONLY, 0777);
	if (file == -1)
		display_error("\e[1;31mOpening file Error", 1);
	return (file);
}
