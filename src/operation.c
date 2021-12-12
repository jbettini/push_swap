/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 20:12:34 by jbettini          #+#    #+#             */
/*   Updated: 2021/12/12 04:21:43 by jbettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap_the_pile(t_list *pile, char *instruction)
{
    if (pile && pile->next)
        ft_list_swap(pile->content, pile->next->content);
    if (instruction != NULL)
        ft_putstr(instruction);
}

void    swap_all_pile(t_list *a, t_list *b)
{
    swap_the_pile(a, NULL);
    swap_the_pile(b, "ss\n");
}
/*
void    push_top_pile(t_list *dst, t_list *src, char *instruction)
{
    if (src)
    {   
        ft_lstadd_front(&src, dst);
    }
    ft_putstr(instruction);
}
*/

void    rotate_the_pile(t_list **pile, char *instruction)
{
    if (pile)
    {
        t_list  *tmp;
        t_list  *new;

        tmp = *pile;
        new = ft_lstnew(tmp->content);
        ft_lstadd_back(&tmp, new);
        *pile = tmp->next;
        free(tmp);
        tmp->content = NULL;
        tmp = NULL;
        if (instruction != NULL)
            ft_putstr(instruction);
    }
}

void    reverse_the_pile(t_list **pile, char *instruction)
{
    if (pile)
    {
        t_list  *tmp;
        t_list  *tmp2;
        t_list  *new;

        tmp = ft_lstlast(*pile);
        new = ft_lstnew((ft_lstlast(*pile)->content));
        ft_lstadd_front(pile, new);
        tmp = *pile;
        while (tmp->next)
        {
            tmp2 = tmp;
            tmp = tmp->next;
        }
        tmp->content = NULL;
        free(tmp2->next);
        tmp2->next = NULL;
        if (instruction != NULL)
            ft_putstr(instruction);
    }
}

void    rotate_all_pile(t_list *a, t_list *b)
{
    rotate_the_pile(&a, NULL);
    rotate_the_pile(&b, "rr\n");
}
