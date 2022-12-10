/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <ranki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:33:14 by ranki             #+#    #+#             */
/*   Updated: 2022/12/10 01:14:47 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_median(t_list *lst, int size)
{
    int min;
    int max;
    t_list *tmp;
    int i = 0;
    
    if (lst == NULL)
        return 0;
    tmp = lst;
    min = tmp->content;
    max = tmp->content;
    while (tmp != NULL && i < size)
    {
        if (min > tmp->content)
            min = tmp->content;
        if (max < tmp->content)
            max = tmp->content;
        tmp =  tmp->next;
        i++;
    }
    min = min / 2;
    max = max / 2;
    return (min + max);
}

int get_median(t_list *lst, int size)
{
    int i;
    int j;
    int current_pivot;
    long int check;
    t_list *tmp;
    t_list *tmp2;

    if (lst == NULL)
        return(0);
    tmp = lst;
    i = 0;
    check = 0;
    current_pivot = ft_median(lst, size);
   // printf("size = %d \n", size);
    while (tmp != NULL && i < size)
    {
        j = 0;
        current_pivot = tmp->content;
        tmp = tmp->next;
        tmp2 = lst;
        while (tmp2 != NULL && j < size)
        {
            if (tmp2->content <= current_pivot)
                check -= 1;
            if (tmp2->content > current_pivot)
                check += 1;
            tmp2 = tmp2->next;
            j++;
        }
   //     printf("check = %d avec le pivot = %d\n", check, current_pivot);
        if (check == 0 || check == -1 || check == 1 || check == 2 || check == -2)
        {
          //  printf("ici \n");
            return (current_pivot);
        }
        i++;
    }
    //printf("Mauvaise fonction\n");
            current_pivot = ft_median(lst, size);
     return (current_pivot);
    
}

int ft_quick_sort(t_list **a, t_list **b, int size, t_listopt **result)
{
    int pivot;
    int i;

    if (ft_checksorted(*a, size))
        return (1);
    if (size <= 3)
    {
        ft_sort_adup(a, b, size, result);
        return (1);
    }
    i = 0;
    pivot = ft_median(*a, size);
    int size_b = 0;
    int size_a = 0;
    while (i < size)
    {
        if ((*a)->content <= pivot)
        {
            ft_push_b(a, b, result);
            size_b++;
        }
        else
        {
            ft_rotate_a(a, result);
            size_a++;
        }
        i++;
    }
    i = 0;
    while(i < size_a)
    {
        ft_rrotate_a(a, result);
        i++;
    }
    return (ft_quick_sort(a, b, size_a, result) && ft_quick_sort_b(a, b,  size_b, result));
}


int ft_quick_sort_b(t_list **a, t_list **b, int size, t_listopt **result)
{
    int pivot;
    int i;
    
    if (ft_checksorted_d(*b, size))
    {
        while(size--)
            ft_push_a(a ,b, result);
        return (1);
    }
    if (size <= 3)
    {
        ft_sort_bdup(a, b, size, result);
        return (1);
    }
    i = 0;
    pivot = ft_median(*b, size);
    //printf("pivot = %d\n", pivot);
    int size_b = 0;
    int size_a = 0;
    while (i < size)
    {
        if ((*b)->content >= pivot)
        {
            ft_push_a(a, b, result);
            size_a++;
        }
        else
        {
            ft_rotate_b(b, result);
            size_b++;    
        }
        i++;
    }
    i = 0;
    while(i < size_b)
    {
        ft_rrotate_b(b, result);
        i++;
    }
    return (ft_quick_sort(a, b, size_a, result) && ft_quick_sort_b(a, b, size_b, result));
    
}