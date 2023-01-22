/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstsize.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:03:41 by asioud            #+#    #+#             */
/*   Updated: 2022/12/20 13:03:43 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	lstsize(void *lst)
{
	t_list	*lst2;
	size_t	i;

	i = 0;
	lst2 = (t_list *)lst;
	if (!lst2)
		return (0);
	while (lst2 != NULL)
	{
		lst2 = lst2->next;
		i++;
	}
	return (i);
}
