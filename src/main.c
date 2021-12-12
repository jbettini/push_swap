/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 15:39:19 by jbettini          #+#    #+#             */
/*   Updated: 2021/12/12 21:14:37 by jbettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int main(int ac, char **av)
{
    char **arg;

    arg = &av[1];
    if (ac == 2)
        arg = ft_split(av[1], ' ');
    if (ac > 1 && int_check(arg) && ft_double_strlen(arg) > 1)
        push_swap(arg, ac);
    else if (ft_double_strlen(arg) <= 1 || !int_check(arg))
    {
        if (ac == 2)
            ft_free_split(arg);
        ft_putstr_fd("Error", 2);
    }
    if (ac == 2)
        ft_free_split(arg);
    
    //system("leaks Push_swap");
    return (0);
}
