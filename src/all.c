/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:53:59 by jbettini          #+#    #+#             */
/*   Updated: 2021/12/16 15:54:22 by jbettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_all_pile(t_list *a, t_list *b)
{
	rotate_the_pile(&a, NULL);
	rotate_the_pile(&b, "rr\n");
}

void	swap_all_pile(t_list *a, t_list *b)
{
	swap_the_pile(a, NULL);
	swap_the_pile(b, "ss\n");
}

void	reverse_all_pile(t_list *a, t_list *b)
{
	reverse_the_pile(&a, NULL);
	reverse_the_pile(&b, "rr\n");
}
