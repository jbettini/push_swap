/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:05:53 by jbettini          #+#    #+#             */
/*   Updated: 2021/12/28 05:26:37 by jbettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_first_chunk(int size, t_list **b, t_list **a)
{
	if (size == 1)
		push_top_pile(a, b, "pa\n");
	else if (size == 2)
	{
		if (ft_atoi((*b)->content) < ft_atoi((*b)->next->content))
			swap_the_pile(*b, "sb\n");
		push_top_pile(a, b, "pa\n");
		push_top_pile(a, b, "pa\n");
	}
}

void	sort_top_of_a(t_list **a)
{
	if (ft_atoi((*a)->content) > ft_atoi((*a)->next->content)) 	
		swap_the_pile(*a, "sa\n");
}

void	seconde_chunk_case_four(int size, int med, t_list **b, t_list **a)
{
	while (size != 2)
		{
			if (ft_atoi((*b)->content) >= med)
			{
				push_top_pile(a, b, "pa\n");	
				size--;
			}
			else if (ft_atoi((*b)->content) < med && ft_atoi((*b)->next->content) >= med) 
				swap_the_pile(*b, "sb\n");
			else
			{
				rotate_the_pile(b, "rb\n");
				if (ft_atoi((*b)->content) < med && ft_atoi((*b)->next->content) >= med) 
					swap_the_pile(*b, "sb\n");
				else
				{
					push_top_pile(a, b, "pa\n");	
					size--;
				}
				reverse_the_pile(b, "rrb\n");
			}
		}	
}

void	seconde_chunk_case_three(int size, int med, t_list **b, t_list **a)
{
	while (size != 1)
	{
		if (ft_atoi((*b)->content) >= med)
		{
			push_top_pile(a, b, "pa\n");	
			size--;
		}
		else
			swap_the_pile(*b, "sb\n");	
	}
	sort_top_of_a(a);
	sort_first_chunk(1, b, a);	
}

void	sort_second_chunk(int size, t_list **b, t_list **a)
{
	int	med;

	med = get_med_chunk(*b, size);
	if (size == 4)
	{
		seconde_chunk_case_four(size, med, b, a);
		sort_top_of_a(a);
		sort_first_chunk(2, b, a);
	}
	if (size == 3)
		seconde_chunk_case_three(size, med, b, a);
	if (size == 2)
		sort_first_chunk(2, b, a);	
}