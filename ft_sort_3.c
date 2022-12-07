/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <ranki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:19:02 by ranki             #+#    #+#             */
/*   Updated: 2022/12/08 00:30:12 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_sort_adup(t_list **a, t_list **b, int size)
{
    t_list *second;
    t_list *third;
    
    second = (*a)->next;
    third = second->next;
    if (size == 2)
    {
        second = (*a)->next;
        if ((*a)->content > second->content)
            ft_swap_a(a);
    }
    else if (size == 3)
    {
        if ((*a)->content >= second->content && second->content >= third->content)
        {
            ft_swap_a(a);
            ft_push_b(a,b);
            ft_swap_a(a);
            ft_push_a(a,b);
            ft_swap_a(a);
        }
        else if ((*a)->content >= second->content && (*a)->content >= third->content && second->content <= third->content)
        {
            ft_swap_a(a);
            ft_push_b(a,b);
            ft_swap_a(a);
            ft_push_a(a,b);
        }
        else if ((*a)->content <= second->content && (*a)->content >= third->content && second->content >= third->content)
        {
            ft_push_b(a,b);
            ft_swap_a(a);
            ft_push_a(a,b);
            ft_swap_a(a);
        }
        else if ((*a)->content >= second->content && second->content <= third->content && (*a)->content <= third->content)
        {
            ft_swap_a(a);
        }
        else if ((*a)->content <= second->content && second->content >= third->content && (*a)->content <= third->content)
        {
            ft_push_b(a,b);
            ft_swap_a(a);
            ft_push_a(a,b);
        }
    }
    
}
   // ft_printlist(*a);
    // while (ft_checksorted(*a, size) != 1)
    // {
    //     tmp = (*a)->next;
    //     tmp2 = tmp->next;
    //     if (ft_checksorted_d(*a))
    //     {
    //         ft_rotate_a(a);
    //     }
    //     else if ((*a)->content > tmp2->content)
    //     {
    //         ft_rotate_a(a);
    //     }
    //     else if ((*a)->content > tmp->content)
    //     {
    //             ft_swap_a(a);
    //     }
    //     else
    //     {
    //         ft_rotate_a(a);
    //     }
    // }


// void    ft_sort_3d(t_list **b, int size)
// {
//     //printf("pbsse pbr feneu\n");
//      t_list *tmp;
//     t_list *tmp2;
    
//     //printf("pbsse pbr feneu\n");
//     if (b == NULL || *b == 0)
//         return ;
//    // ft_printlist(*b);
//     while (ft_checksorted_d(*b, size) != 1)
//     {
//         tmp = (*b)->next;
//         tmp2 = tmp->next;
//         if (ft_checksorted(*b))
//         {
//             ft_rotate_b(b);
//         }
//         else if ((*b)->content < tmp2->content)
//         {
//             ft_rotate_b(b);
//         }
//         else if ((*b)->content < tmp->content)
//         {
//                 ft_swap_b(b);
//         }
//         else
//         {
//             ft_rotate_b(b);
//         }
//     }
// }

void    ft_sort_bdup(t_list **a, t_list **b, int size)
{
    t_list *second;
    t_list *third;
    
    second = (*b)->next;
    third = second->next;
    if (size == 1)
        ft_push_a(a,b);
    else if (size == 2)
    {
        second = (*b)->next;
        if ((*b)->content < second->content)
            ft_swap_b(b);
        ft_push_a(a, b);
        ft_push_a(a, b);
    }
    else if (size == 3)
    {
        if ((*b)->content >= second->content && second->content >= third->content)
        {
            ft_push_a(a,b);
            ft_push_a(a,b);
            ft_push_a(a,b);
        }
        else if ((*b)->content >= second->content && (*b)->content >= third->content && second->content <= third->content)
        {
            ft_push_a(a,b);
            ft_swap_b(b);
            ft_push_a(a,b);
            ft_push_a(a,b);
        }
        else if ((*b)->content <= second->content && (*b)->content >= third->content && second->content >= third->content)
        {
            ft_swap_b(b);
            ft_push_a(a,b);
            ft_push_a(a,b);
            ft_push_a(a,b);
        }
        else if ((*b)->content >= second->content && second->content <= third->content && (*b)->content <= third->content)
        {
            ft_push_a(a,b);
            ft_swap_b(b);
            ft_push_a(a,b);
            ft_swap_a(a);
            ft_push_a(a,b);
        }
        else if ((*b)->content <= second->content && second->content >= third->content && (*b)->content <= third->content)
        {
            ft_swap_b(b);
            ft_push_a(a,b);
            ft_swap_b(b);
            ft_push_a(a,b);
            ft_push_a(a,b);
        }
        else if ((*b)->content <= second->content && second->content <= third->content)
        {
            ft_rotate_b(b);
            ft_swap_b(b);
            ft_push_a(a,b);
            ft_push_a(a,b);
            ft_rrotate_b(b);
            ft_push_a(a,b);
        }
    }
    
}