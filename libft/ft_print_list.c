/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:24:10 by jbettini          #+#    #+#             */
/*   Updated: 2021/12/27 05:14:39 by jbettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_print_list(t_list *lst)
{
    while(lst)
    {
        ft_putstr(lst->content);
        ft_putchar('\n');
        lst = lst->next;
    }
}