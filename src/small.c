/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 21:38:09 by jbettini          #+#    #+#             */
/*   Updated: 2021/12/14 19:33:25 by jbettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int smallest_case(t_list *a)
{
    if (ft_atoi(A) > ft_atoi(NEXT) && ft_atoi(NEXT) < \
            ft_atoi(ALAST) && ft_atoi(ALAST) > ft_atoi(A))
        return (1);
    if (ft_atoi(A) > ft_atoi(NEXT) && ft_atoi(NEXT) > \
            ft_atoi(ALAST) && ft_atoi(ALAST) < ft_atoi(A))
        return (2);
    if (ft_atoi(A) > ft_atoi(NEXT) && ft_atoi(NEXT) < \
            ft_atoi(ALAST) && ft_atoi(ALAST) < ft_atoi(A))
        return (3);
    if (ft_atoi(A) < ft_atoi(NEXT) && ft_atoi(NEXT) > \
            ft_atoi(ALAST) && ft_atoi(ALAST) > ft_atoi(A))
        return (4);
    if (ft_atoi(A) < ft_atoi(NEXT) && ft_atoi(NEXT) > \
            ft_atoi(ALAST) && ft_atoi(ALAST) < ft_atoi(A))
        return (5);
    if (is_sorted(a))
        return (6);
    return (0);
}

t_list    *smallest_sort(t_list *a, t_list *b)
{
    int i;

    i = smallest_case(a);
    while (!is_sorted(a))
    {
        if (i == 1)
            SA
        else if (i == 2)
        {
            SA
            RRA
        }
        else if (i == 3)
            RA
        else if (i == 4)
        {
            SA
            RA
        }
        else if (i == 5)
            RRA
    }
    return (a);
}

int get_position(int b, t_list *a)
{
    int pos;

    pos = 1;
    while (a->next)
    {
        if (b > ft_atoi(a->content))
            pos++;
        a = a->next;
    }
    if (a->next == NULL && ft_atoi(ALAST) < b)
        ++pos;
    return (pos);
}
