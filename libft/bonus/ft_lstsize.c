/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:03:35 by asioud            #+#    #+#             */
/*   Updated: 2022/12/20 13:03:37 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*counter;
	size_t	i;

	counter = lst;
	i = 0;
	if (!lst)
		return (0);
	while (counter != NULL)
	{
		counter = counter->next;
		i++;
	}
	return (i);
}
