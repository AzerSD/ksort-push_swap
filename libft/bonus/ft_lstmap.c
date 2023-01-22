/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:03:17 by asioud            #+#    #+#             */
/*   Updated: 2022/12/20 13:03:19 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list			*tmp;
	struct s_list	*lst2;

	lst2 = malloc(sizeof(t_list));
	if (!lst2)
		return (NULL);
	tmp = lst;
	while (tmp != 0)
	{
		if (!(f(tmp->content)))
			ft_lstdelone(tmp->content, del);
		lst2->content = f(tmp->content);
		lst2 = lst2->next;
		tmp = tmp->next;
	}
	return (lst2);
}
