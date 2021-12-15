/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 23:00:43 by jbettini          #+#    #+#             */
/*   Updated: 2021/12/15 18:00:37 by jbettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_valid_num(char *arg)
{
    int i;
    int j;

    i = 0;
    j = 0;
    if (arg[i] == '-')
        i++;
    while (arg[i])
    {
        if (ft_isdigit(arg[i]))
            j++;
        else
            return (0);
        i++;
    }
    if (j > 10)
        return 0;
    return (1);
}

int check_limits(char *arg)
{
    long long   nb;

    nb = ft_atoll(arg);
    if (nb > 2147483647)
        return (0);
    else if (nb < -2147483648)
        return (0);
    return (1);
}

int check_double(char **arg)
{
    int i;
    int j;

    j = 0;
    i = j + 1;
    while (arg[j])
    {
        i = j + 1;
        while (arg[i])
        {
            if (!ft_strcmp(arg[j], arg[i]))
                return (0);
            i++;
        }
        j++;
    }
    return (1);
}

int int_check(char **arg)
{
    int i;

    i = 0;
    while (arg[i])
    {
        if (!check_valid_num(arg[i]))
            return (0);
        else if (!check_limits(arg[i]))
            return (0);
        else if (!check_double(arg))
            return (0);
        i++;
    }
    return (1);
}

int is_sorted(t_list *lst)
{
    t_list    *tmp;
    t_list    *tmp2;

    tmp = lst;
    while(tmp->next)
    {
        tmp2 = tmp;
        tmp = tmp2->next;
        if (ft_atoi(tmp->content) < ft_atoi(tmp2->content))
            return (0);
    }
    return (1);
}

int is_r_sorted(t_list *lst)
{
    t_list    *tmp;
    t_list    *tmp2;

    tmp = lst;
    while(tmp->next)
    {
        tmp2 = tmp;
        tmp = tmp2->next;
        if (ft_atoi(tmp->content) > ft_atoi(tmp2->content))
            return (0);
    }
    return (1);
}
