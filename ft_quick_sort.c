/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <ranki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:33:14 by ranki             #+#    #+#             */
/*   Updated: 2022/12/06 00:04:55 by ranki            ###   ########.fr       */
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
    int cpt;
    
    size = ft_lstsize(*a);
    t_list *tmp;
    printf("\nquicaaaaaaaaaaaaaaaaaayyyyyyyyyyyaaaaaaaaa\n");
    printf("size = %d\n", size);
    if (ft_checksorted(*a))
        return (1);
    if (size < 3)
    {
       printf("return by sort 2\n");
        if (size == 2)
        {
            ft_sort_2(a);
            /*ft_push_b(a, b);
            ft_push_b(a, b);*/
        }
        else if (size == 1)
        {
            ft_push_a(a, b);
        }
        return (1);
    }
    i = 0;
    cpt = 0;
    pivot = ft_median(*a);
    tmp = (*a);
    printf("size = %d\n", size);
    printf("Pivot = %d\n", pivot);
    while (i < size)
    {
       // printf("i = %d\n", i);
        if ((*a)->content <= pivot)
        {
            ft_push_b(a, b);
            cpt++;
        }
        else
            ft_rotate_a(a);
       printf("a = ");
        ft_printlist(*a);
        printf("\n");
        printf("b = ");
        ft_printlist(*b);
        printf("\n\n");
        i++;
    }
    /* printf("b = ");
        ft_printlist(*b);
    printf("\n");*/
    //printf("fin boucle kkk size - cpt = %d\n", size - cpt);
    //return (1);
    return (ft_quick_sort(a, b, size + cpt) && ft_quick_sort_b(a, b, cpt));
    
}


int ft_quick_sort_b(t_list **a, t_list **b, int size)
{
    int pivot;
    int i;
    int cpt;
    t_list *tmp;
    
    size = ft_lstsize(*b);
    printf("\nquicbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbtttttttttttbbb\n");
    if (ft_checksorted_d(*b))
    {
        while(size--)
            ft_push_a(a ,b);
        return (1);
    }
    if (size < 3)
    {   
        if (size == 2)
        {
            ft_sort_2(b);
           /**/ ft_push_a(a, b);
            ft_push_a(a, b);*/
        }
        else if (size == 1)
        {
            ft_push_a(a, b);
        }
        return (1);
    }
    i = 0;
    cpt = 0;
    pivot = ft_median(*b);
    tmp = (*b);
     printf("size = %d\n", size);
    printf("Pivot = %d\n", pivot);
    while (i < size)
    {
        if ((*b)->content > pivot)
        {
            if ((*a)->content < (*b)->content)
            {
                ft_push_a(a, b);
                ft_swap_a(a);
            }
            else
            ft_push_a(a, b);
            cpt++;
        }
        else
            ft_rotate_b(b);
        i++;
      printf("a = ");
        ft_printlist(*a);
        printf("\n");
        printf("b = ");
        ft_printlist(*b);
        printf("\n\n");
    }
 
   // printf("size - cpt = %d\n", size - cpt);
    return (ft_quick_sort(a, b, size + cpt) && ft_quick_sort_b(a, b, size + cpt));
    
}