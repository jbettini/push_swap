/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 15:39:19 by jbettini          #+#    #+#             */
/*   Updated: 2021/12/11 19:57:03 by jbettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list  *create_a(char **arg, int ac)
{
    size_t  i;
    t_list  *a;

    i = 0;
    a = ft_lstnew(arg[i]);
    while(arg[++i])
        ft_lstadd_back(&a, ft_lstnew(arg[i]));
    if (ac == 2)
    {
        ft_free_split(arg);
        arg = 0;
    }
    return (a);
}

void    ft_free_split(char **tab)
{
    size_t  i;

    i = -1;
    while(tab[++i])
        free(tab[i]);
    free(tab);
    tab = 0;
}

size_t ft_double_strlen(char **arg)
{
    size_t  i;

    i = 0;
    while(arg[i])
        i++;
    return (i);
}

int main(int ac, char **av)
{
    char **arg;

    arg = &av[1];
    if (ac == 2)
        arg = ft_split(av[1], ' ');
    if (ac > 1 && int_check(arg) && ft_double_strlen(arg) > 1)
    {
        t_list  *a = create_a(arg, ac);
        t_list  *b = ft_lstnew(NULL);
    }
    else if (ft_double_strlen(arg) <= 1 || !int_check(arg))
    {
        if (ac == 2)
            ft_free_split(arg);
        ft_putstr_fd("Error", 2);
    }
    return (0);
}
