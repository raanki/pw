/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <ranki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:33:14 by ranki             #+#    #+#             */
/*   Updated: 2022/12/05 14:28:18 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_median(t_list *lst)
{
    int min;
    int max;
    t_list *tmp;
    
    if (lst == NULL)
        return 0;
    tmp = lst;
    min = tmp->content;
    max = tmp->content;
    while (tmp != NULL)
    {
        if (min > tmp->content)
            min = tmp->content;
        if (max < tmp->content)
            max= tmp->content;
        tmp =  tmp->next;
    }
    return ((min + max) / 2);
}

int ft_quick_sort(t_list **a, t_list **b, int size)
{
    int pivot;
    int i;
    t_list *tmp;
    
    if (ft_checksorted(*a))
        return (1);
    if (size < 2)
    {
        ft_sort_2(a);
        return (1);
    }
    i = 0;
    pivot = ft_median(*a);
    tmp = (*a);
    while (i < size + size % 2)
    {
        if ((*a)->content < pivot)
            ft_push_b(a, b);
        else
            ft_rotate_a(a);
        tmp = tmp->next;
        i++;
    }
    
    return (ft_quick_sort(a, b, size / 2 + size % 2) && ft_quick_sort(a, b, size / 2));
    
}

int ft_quick_sort_b(t_list **a, t_list **b, int size)
{
    int pivot;
    int i;
    t_list *tmp;
    
    if (ft_checksorted(*b))
        while(size--)
            ft_push_a(a ,b);
    if (size < 2)
    {
        ft_sort_2(b);
        ft_push_a(a, b);
        ft_push_a(a, b);
        return (1);
    }
    i = 0;
    pivot = ft_median(*b);
    tmp = (*b);
    while (i < size + size % 2)
    {
        if ((*b)->content < pivot)
            ft_push_a(a, b);
        else
            ft_rotate_b(a);
        tmp = tmp->next;
        i++;
    }
  /*  while ()
        ft_rrotate_b(b);*/
    return (ft_quick_sort(a, b, size / 2 + size % 2) && ft_quick_sort(a, b, size / 2));
    
}