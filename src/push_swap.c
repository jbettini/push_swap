/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 20:09:58 by jbettini          #+#    #+#             */
/*   Updated: 2021/12/15 06:47:21 by jbettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list  *create_a(char **arg)
{
    size_t  i;
    t_list  *a;

    i = 0;
    a = ft_lstnew(arg[i]);
    while(arg[++i])
        ft_lstadd_back(&a, ft_lstnew(arg[i]));
    return (a);
}

void    insert_swap(char **arg)
{
    size_t i;
    size_t pos;
    int min;

    i = 0;
    pos = 0;
    min = ft_atoi(arg[i]);
    while(arg[i])
    {
        if (ft_atoi(arg[i]) < min)
        {
            min = ft_atoi(arg[i]);
            ft_swap_str(&arg[0], &arg[i]);
        }
        i++;
    }
}

char    **ft_sort_insert(char **arg)
{
    size_t  i;

    i = -1;
    while (arg[++i])
        insert_swap(&arg[i]);
    return (arg);
}

char    *index_pos(int nb, char **arg)
{
    int i;

    i = -1;
    while (arg[++i])
    {
        if (ft_atoi(arg[i]) == nb)
            return (ft_itoa(i));
    }
    return (NULL);
}

t_list  *convert_to_pos(t_list  **a, char **arg)
{
    t_list  *tmp;

    tmp = *a;
    while (tmp)
    {
        tmp->content = index_pos(ft_atoi(tmp->content), arg);
        tmp = tmp->next;
    }
    return (*a);
}

int only_one(t_list *a, int i)
{
    while(a)
    {
        if (itb(ft_atoi(a->content)) / i == 0)
            return (0);
        a = a->next;
    }
    return (1);
}

int size_max(int nb)
{
    int i;
    char *tmp;

    tmp = ft_itoa_base(nb, "01");
    nb = ft_atoi(tmp);
    free(tmp);
    i = 1;
    while (nb != 0)
    {
        i *= 10;
        nb /= 10;
    }
    i /= 10;
    return (i);
}

t_list  *ft_radix_sort(t_list **a, t_list **b)
{
    int i;

    i = size_max(ft_lstsize(*a));
    while (!is_sorted(*a) || ft_lstsize(*b) > 0 || i != 0)
    {
        while (itb(ft_atoi((*a)->content)) / i == 0)
            push_top_pile(b, a, "pb\n");
        while (itb(ft_atoi((*a)->content)) / i == 1 && !only_one(*a, i))
            rotate_the_pile(a, "ra\n");
        if (only_one(*a, i))
        {
            while (ft_lstsize(*b) > 0)
                push_top_pile(a, b, "pa\n");
            i /= 10;
        }
    }
    return (*a);
}

t_list  *big_case(t_list **a, t_list **b, char **arg)
{
    arg = ft_sort_insert(arg);
    *a = convert_to_pos(a, arg);
    *a = ft_radix_sort(a, b);
    return (*a);
}

void    push_swap(char **arg, int ac)
{
    t_list  *a;
    t_list  *b;
    int     leak;

    leak = 0;
    a = create_a(arg);
    b = NULL;
    if (ft_lstsize(a) <= 5 && ft_lstsize(a) >= 2 && !is_sorted(a))
        a = small_case(&a, &b);
    else if (ft_lstsize(a) > 5)
    {
        leak++;
        a = big_case(&a, &b, arg);
    }
    if (!is_sorted(a))
        printf("is no Sort\n");
    else 
        printf("is Sort\n");
    if (leak == 1)
        ft_lstclear(&a, free);
    else
        ft_lstclear(&b, ft_lstdel_content);
    ft_lstclear(&b, ft_lstdel_content);
}

// `ruby -e "puts (0..499).to_a.shuffle.join(' ')"`