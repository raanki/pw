/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <ranki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 23:18:48 by ranki             #+#    #+#             */
/*   Updated: 2022/12/05 00:48:12 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_swap_a(t_list **lst)
{
    t_list *tmp;

    if (*lst == NULL || (*lst)->next == NULL )
        return ;
    tmp = *lst;
    *lst = ((*lst)->next);
    tmp->next = ((*lst)->next);
    ((*lst)->next) = tmp;
    printf("sa\n");
}

void ft_swap_b(t_list **lst)
{
    t_list *tmp;

    if (*lst == NULL || (*lst)->next == NULL )
        return ;
    tmp = *lst;
    *lst = ((*lst)->next);
    tmp->next = ((*lst)->next);
    ((*lst)->next) = tmp;
    printf("sb\n");
}

void ft_swap_ss(t_list **a, t_list **b)
{
    t_list *tmp;

    if (*a == NULL || (*a)->next == NULL || *b == NULL || (*b)->next == NULL)
        return ;
    tmp = *a;
    *a = ((*a)->next);
    tmp->next = ((*a)->next);
    ((*a)->next) = tmp;
    tmp = *b;
    *b = ((*b)->next);
    tmp->next = ((*b)->next);
    ((*b)->next) = tmp;
    printf("ss\n");
}

