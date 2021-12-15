/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 21:47:04 by jbettini          #+#    #+#             */
/*   Updated: 2021/12/15 06:36:35 by jbettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_swap_content(t_list **a, t_list **b)
{
	void *x;

    x = (*a)->content;
	(*a)->content = (*b)->content;
	(*b)->content = x;
}

void    ft_lstdel_content(void *content)
{
    content = NULL;
}

void    ft_swap_str(char **a, char **b)
{
	char *x;

    x = *a;
	*a= *b;
	*b = x;
}

t_ull itb(int nb)
{
    int i;
    t_ull res;
    int tmp[10];

    res = 0;
    i = 0;
    while (nb)
    {
        tmp[i++] = nb % 2;
        nb /= 2;
    }
    while (--i >= 0)
    {
        res *= 10;
        res += tmp[i];
    }
    return (res);
}










void    print_split(char **tab)
{
    int i = -1;
    while(tab[++i])
        printf("SPLIT %s\n", tab[i]);
}

void    print_nb_lst(t_list *lst)
{
    int i = 0;
    while(lst)
    {
        printf("%d\n",ft_atoi(lst->content));
        lst = lst->next;
        i++;
    }
}