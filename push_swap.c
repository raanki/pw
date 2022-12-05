/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <ranki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 21:30:36 by ranki             #+#    #+#             */
/*   Updated: 2022/12/05 15:02:09 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

void    ft_printlist(t_list *lst)
{
    if (lst == NULL)
        return ;
    printf("%d ", lst->content);
    ft_printlist(lst->next);
}

t_list *ft_argtolist(int argc, char **argv)
{
    int i;
    t_list *lst;
   
    i = 1;
    while (i < argc)
    {
        ft_lstadd_back(&lst, ft_lstnew(atoi(argv[i])));
        i++;
    }
    return(lst);
}

int main (int argc, char**argv)
{
        t_list *lst = ft_argtolist(argc, argv);
        ft_printlist(lst);
        if (ft_checksorted(lst))
            printf("\nLa liste est bien trie\n\n");
        else
        {
            printf("\nla liste nest pas triee on va la trie\n\n");
        }
        //ft_swap_a(&lst);
       // ft_printlist(lst);
        //ft_unstack(&lst);
        t_list *b = malloc(sizeof(t_list));
        ft_quick_sort(&lst, &b, ft_lstsize(lst));
        printf("a = ");
        ft_printlist(lst);
        printf("b = ");
        ft_printlist(b);
        ft_lstclear(&lst);
        return (0);
}