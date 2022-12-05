/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <ranki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 21:33:59 by ranki             #+#    #+#             */
/*   Updated: 2022/12/05 22:51:14 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	int			content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst);
int ft_checksorted(t_list *lst);
void ft_swap_a(t_list **lst);
void ft_swap_b(t_list **lst);
void ft_swap_ss(t_list **a, t_list **b);
void    ft_push_a(t_list **a, t_list **b);
void    ft_push_b(t_list **a, t_list **b);
t_list *ft_unstack(t_list **a);
void    ft_rotate_a(t_list **lst);
void    ft_rotate_b(t_list **lst);
void ft_rrotate_a(t_list **a);
void ft_rrotate_b(t_list **b);
void ft_rrotate_rr(t_list **a, t_list **b);
void    ft_middlelst(t_list **a, t_list **b);
void    ft_sort_2(t_list **lst);
int ft_quick_sort(t_list **a, t_list **b, int size);
int ft_quick_sort_b(t_list **a, t_list **b, int size);
 void   ft_printlist(t_list *lst);
 int     ft_checksorted_d(t_list *lst);
#endif