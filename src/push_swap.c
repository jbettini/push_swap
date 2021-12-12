/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 20:09:58 by jbettini          #+#    #+#             */
/*   Updated: 2021/12/12 21:13:27 by jbettini         ###   ########.fr       */
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
    print_nb_lst(a);
    printf("-------\n");
    reverse_the_pile(&a, "rra\n");
    print_nb_lst(a);
    printf("-------\n");
    rotate_the_pile(&a, "ra\n");
    print_nb_lst(a);
    printf("-------\n");
    swap_the_pile(a, "sa\n");
    print_nb_lst(a);
    printf("----B---\n");
    push_top_pile(&b, &a, "pb\n");
    print_nb_lst(b);
    printf(" --A-- \n"); 
    print_nb_lst(a);
    printf("---A---\n");
    push_top_pile(&a, &b, "pa\n");
    print_nb_lst(a);
    printf(" --B-- \n"); 
    print_nb_lst(b); 
    ft_lstclear(&a, ft_lstdel_content);
    ft_lstclear(&b, ft_lstdel_content);
}