/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:08:17 by jbettini          #+#    #+#             */
/*   Updated: 2021/12/29 11:06:37 by jbettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	smallest_case(t_list *a)
{
	int	first;
	int	between;
	int	last;

	first = ft_atoi(a->content);
	between = ft_atoi(a->next->content);
	last = ft_atoi(a->next->next->content);
	if (first > between && between < last && last > first)
		return (1);
	if (first > between && between > last && last < first)
		return (2);
	if (first > between && between < last && last < first)
		return (3);
	if (first < between && between > last && last > first)
		return (4);
	if (first < between && between > last && last < first)
		return (5);
	return (6);
}

t_list	*smallest_sort(t_list *a)
{
	int	i;

	i = smallest_case(a);
	while (!is_sorted(a))
	{
		if (i == 1)
			swap_the_pile(a, "sa\n");
		else if (i == 2)
		{
			swap_the_pile(a, "sa\n");
			reverse_the_pile(&a, "rra\n");
		}
		else if (i == 3)
			rotate_the_pile(&a, "ra\n");
		else if (i == 4)
		{
			swap_the_pile(a, "sa\n");
			rotate_the_pile(&a, "ra\n");
		}
		else if (i == 5)
			reverse_the_pile(&a, "rra\n");
	}
	return (a);
}

int	get_position(int b, t_list *a)
{
	int	pos;

	pos = 1;
	while (a->next)
	{
		if (b > ft_atoi(a->content))
			pos++;
		a = a->next;
	}
	if (a->next == NULL && ft_atoi((ft_lstlast(a))->content) < b)
		++pos;
	return (pos);
}
