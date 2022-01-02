/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:05:53 by jbettini          #+#    #+#             */
/*   Updated: 2022/01/02 09:34:41 by jbettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_chunk_init(t_cpt *cpt, t_list *a, char **arg)
{
	cpt->i = ft_lstsize(a);
	cpt->pa = 0;
	cpt->med = get_med_value(arg);
}

void	b_to_a_init(t_cpt *cpt, int size, t_list **b)
{
	cpt->size = size;
	cpt->rb = 0;
	cpt->i = 0;
	cpt->med = get_med_chunk(*b, size);
}

void	a_to_b_init(t_cpt *cpt, int size, t_list **a)
{
	cpt->i = 0;
	cpt->size = size;
	cpt->med = get_med_chunk(*a, size);
	cpt->pa = 0;
	cpt->ra = 0;
}

void	remake_init(t_cpt *cpt, t_list **a, t_list **b, int size)
{
	cpt->pb = 0;
	cpt->rb = 0;
	cpt->i = 0;
	cpt->size = size;
	cpt->med = get_med_chunk(*b, size);
}