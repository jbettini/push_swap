/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 20:09:58 by jbettini          #+#    #+#             */
/*   Updated: 2021/12/12 23:32:01 by jbettini         ###   ########.fr       */
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

void    push_swap(char **arg, int ac)
{
    t_list  *a;
    t_list  *b;

    a = create_a(arg);
    b = NULL;
 //   if (ft_lstsize(a) <= 5 && ft_lstsize(a) >= 2 && !is_sorted(a))
   //     small_sort(a,b);
    //else if (ft_lstsize(a) >= 6 && !is_sorted(a))
   //     big_sort(a, b);
   
    if (is_sorted(a))
        printf("is Sort\n");
    else if (!is_sorted(a))
        printf("is no Sort\n");

    ft_lstclear(&a, ft_lstdel_content);
    ft_lstclear(&b, ft_lstdel_content);
}