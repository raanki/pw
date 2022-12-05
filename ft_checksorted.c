/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checksorted.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <ranki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 22:38:55 by ranki             #+#    #+#             */
/*   Updated: 2022/12/05 22:53:22 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     ft_checksorted(t_list *lst)
{
    int up;
    int down;
    t_list  *tmp;
    t_list  *prec;

    up = 1;
    down = 0;
    if  (lst == NULL)
        return (1);
    tmp = lst->next;
    prec = lst;
    while(tmp != NULL)
    {
        if(prec->content > tmp->content)
            up = 0;
      /*if(prec->content < tmp->content)
            down = 0;        */    
        tmp = tmp->next;
        prec = prec->next;
    }
    return ((up == 1 || down == 1));
}
int     ft_checksorted_d(t_list *lst)
{
    int up;
    int down;
    t_list  *tmp;
    t_list  *prec;

    up = 0;
    down = 1;
    if  (lst == NULL)
        return (1);
    tmp = lst->next;
    prec = lst;
    while(tmp != NULL)
    {
        /*if(prec->content > tmp->content)
            up = 0;*/
      if(prec->content < tmp->content)
            down = 0;           
        tmp = tmp->next;
        prec = prec->next;
    }
    return ((up == 1 || down == 1));
}

void    ft_sort_2(t_list **lst)
{
    t_list *tmp;
    
    if (lst == NULL)
        return ;
    tmp = (*lst)->next;
    if (tmp->content > tmp->content)
        ft_swap_a(lst);
}
