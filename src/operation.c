/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 20:12:34 by jbettini          #+#    #+#             */
/*   Updated: 2021/12/12 21:43:36 by jbettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap_the_pile(t_list *pile, char *instruction)
{
    if (pile && pile->next)
        ft_list_swap(&pile, &(pile->next));
    if (instruction != NULL)
        ft_putstr(instruction);
}

void    push_top_pile(t_list **dst, t_list **src, char *instruction)
{
    if (*src)
    {   
        t_list  *tmp;

        tmp = ft_lstnew((*src)->content);
        ft_lstadd_front(dst, tmp);
        tmp = *src;
        *src = (*src)->next;
        tmp->content = NULL;
        free(tmp);
        tmp = NULL;
        ft_putstr(instruction); 
    }
}

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
        tmp->content = NULL;
        free(tmp);
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
