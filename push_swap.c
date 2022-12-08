/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <ranki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 21:30:36 by ranki             #+#    #+#             */
/*   Updated: 2022/12/08 16:44:19 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

 void   ft_printlist(t_list *lst)
{
    if (lst == NULL)
        return ;
    printf("%d ", lst->content);
    ft_printlist(lst->next);
}

void   ft_printlistchar(t_listopt *lst)
{
    if (lst == NULL)
        return ;
    printf("%s\n", lst->content);
    ft_printlistchar(lst->next);
}

t_list *ft_argtolist(int argc, char **argv)
{
    int i;
    t_list *lst;
   
    i = 1;
    lst = NULL;
    while (i < argc)
    {
        ft_lstadd_back(&lst, ft_lstnew(atoi(argv[i])));
        i++;
    }
    return(lst);
}

void    add_move(t_listopt **result, char *s)
{
    ft_lstadd_backchar(result, ft_lstnewstr(s));
}

int main (int argc, char**argv)
{
        t_list  *lst = ft_argtolist(argc, argv);
        t_list  *b = NULL;
        t_listopt  *result = NULL;
        ft_quick_sort(&lst, &b, ft_lstsize(lst), &result);
        simply(&result);
        ft_printlistchar(result);
        ft_printlist(lst);
        ft_lstclear(&lst);
        ft_lstclearchar(&result);
        return (0);
}