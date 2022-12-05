/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checksorted.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <ranki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 22:38:55 by ranki             #+#    #+#             */
/*   Updated: 2022/12/05 00:48:06 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     ft_checksorted(t_list *lst)
{
    int     i;
    t_list  *tmp;
    t_list  *prec;

    if  (lst == NULL)
        return (1);
    tmp = lst->next;
    prec = lst;
    while(tmp != NULL)
    {
        if(prec->content > tmp->content)
            return (0);
        tmp = tmp->next;
        prec = prec->next;
    }
    return (1);
}
