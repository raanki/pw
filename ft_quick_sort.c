/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <ranki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:33:14 by ranki             #+#    #+#             */
/*   Updated: 2022/12/08 00:46:33 by ranki            ###   ########.fr       */
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
    return ((min + max) / 2);
}

int ft_quick_sort(t_list **a, t_list **b, int size)
{
    int pivot;
    int i;
    
    size = ft_lstsize(*a);
    // printf("\nquicaaaaaaaaaaaaaaaaaayyyyyyyyyyyaaaaaaaaa\n");
    // printf("a = ");
    //     ft_printlist(*a);
    //     printf("\n");
    //     printf("b = ");
    //     ft_printlist(*b);
    //     printf("\n\n");
    /*printf("size = %d\n", size);*/
    if (ft_checksorted(*a, size))
    {
        // printf("a est triee et on sort de quick a\n");
        return (1);
    }
    if (size <= 3)
    {
        ft_sort_adup(a, b, size);
        // printf("a nest pas trie mais sa taille est inferieur a 3 on le trie \n");
        return (1);
    }
    i = 0;
    pivot = ft_median(*a, size);
    //printf("pivot = %d\n",pivot);
    int size_b = 0;
    int size_a = 0;
    while (i < size)
    {
       // printf("i = %d\n", i);
        if ((*a)->content <= pivot)
        {
            ft_push_b(a, b);
            size_b++;
        }
        else
        {
            ft_rotate_a(a);
            size_a++;
        }
    //    printf("a = ");
    //     ft_printlist(*a);
    //     printf("\n");
    //     printf("b = ");
    //     ft_printlist(*b);
    //     printf("\n\n");
        i++;
    }
    i = 0;
    while(i < size_a)
    {
        ft_rrotate_a(a);
        i++;
    }
    return (ft_quick_sort(a, b, size_a) && ft_quick_sort_b(a, b,  size_b));
}


int ft_quick_sort_b(t_list **a, t_list **b, int size)
{
    int pivot;
    int i;
    
    // size = ft_lstsize(*b);
    // printf("\nquicbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbtttttttttttbbb\n");
    // printf("a = ");
    //     ft_printlist(*a);
    //     printf("\n");
    //     printf("b = ");
    //     ft_printlist(*b);
    //     printf("\n\n");
        
    if (ft_checksorted_d(*b, size))
    {
        while(size--)
            ft_push_a(a ,b);
        return (1);
    }
    if (size <= 3)
    {
        ft_sort_bdup(a, b, size);
        return (1);
    }
    i = 0;
    pivot = ft_median(*b, size);
    int size_b = 0;
    int size_a = 0;
    while (i < size)
    {
        if ((*b)->content > pivot)
        {
            ft_push_a(a, b);
            size_a++;
        }
        else
        {
            ft_rotate_b(b);
            size_b++;    
        }
        i++;
    //   printf("a = ");
    //     ft_printlist(*a);
    //     printf("\n");
    //     printf("b = ");
    //     ft_printlist(*b);
    //     printf("\n\n");
    }
    i = 0;
    while(i < size_b)
    {
        ft_rrotate_b(b);
        i++;
    }
 
   // printf("size - cpt = %d\n", size - cpt);
    return (ft_quick_sort(a, b, size_a) && ft_quick_sort_b(a, b, size_b));
    
}