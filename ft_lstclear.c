/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <ranki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:22:55 by ranki             #+#    #+#             */
/*   Updated: 2022/12/04 22:25:54 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*before;

	if (*lst == NULL)
		return ;
	tmp = *lst;
	while (tmp != NULL)
	{
		before = tmp;
		tmp = tmp->next;
		del(before->content);
		free(before);
	}
	*lst = 0;
}*/
