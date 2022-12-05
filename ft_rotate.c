/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <ranki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 00:39:27 by ranki             #+#    #+#             */
/*   Updated: 2022/12/05 01:14:08 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_rotate_a(t_list **lst)
{
    t_list *tmp;
    
    if (*lst == NULL)
        return ;
    tmp = ft_lstnew((*lst)->content);
    ft_lstadd_back(lst, tmp);
    tmp->next = NULL;
    *lst = (*lst)->next;
    printf("ra\n");
}

void    ft_rotate_b(t_list **lst)
{
    t_list *tmp;
    
    if (*lst == NULL)
        return ;
    tmp = ft_lstnew((*lst)->content);
    ft_lstadd_back(lst, tmp);
    tmp->next = NULL;
    *lst = (*lst)->next;
    printf("rb\n");
}

void    ft_rotate_rr(t_list **a, t_list **b)
{
    t_list *tmp;
    
    if (*a == NULL || *b == NULL)
        return ;
    tmp = ft_lstnew((*a)->content);
    ft_lstadd_back(a, tmp);
    tmp->next = NULL;
    *a = (*a)->next;
    tmp = ft_lstnew((*b)->content);
    ft_lstadd_back(b, tmp);
    tmp->next = NULL;
    *b = (*b)->next;
    printf("rr\n");
}