/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_pt2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:16:14 by jbettini          #+#    #+#             */
/*   Updated: 2021/12/16 20:01:53 by jbettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*do_small(t_list **a, t_list **b)
{
	int	i;

	i = get_position(ft_atoi((*b)->content), *a);
	push_top_pile(a, b, "pa\n");
	if (i == ft_lstsize(*a))
		rotate_the_pile(a, "ra\n");
	else if (i == ft_lstsize(*a) - 1)
	{
		reverse_the_pile(a, "rra\n");
		swap_the_pile(*a, "sa\n");
		rotate_the_pile(a, "ra\n");
		rotate_the_pile(a, "ra\n");
	}
	else if (i == 2)
		swap_the_pile(*a, "sa\n");
	else if (ft_lstsize(*a) == 5 && i == 3)
	{
		swap_the_pile(*a, "sa\n");
		rotate_the_pile(a, "ra\n");
		swap_the_pile(*a, "sa\n");
		reverse_the_pile(a, "rra\n");
	}
	return (*a);
}

t_list	*small_sort(t_list **a, t_list **b)
{
	while (get_position(ft_atoi((*a)->content), *a) == 3 \
			|| get_position(ft_atoi((*a)->content), *a) == 4)
		rotate_the_pile(a, "ra\n");
	while (get_position(ft_atoi((*a)->next->content), *a) == 3 \
			|| get_position(ft_atoi((*a)->next->content), *a) == 4)
	{
		swap_the_pile(*a, "sa\n");
		rotate_the_pile(a, "ra\n");
	}
	while (ft_lstsize(*a) >= 4)
		push_top_pile(b, a, "pb\n");
	while (!is_sorted(*a) || ft_lstsize(*b) > 0)
	{
		if (ft_lstsize(*a) == 3)
			*a = smallest_sort(*a);
		while (ft_lstsize(*b) > 0)
			*a = do_small(a, b);
	}
	return (*a);
}

t_list	*small_case(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) <= 3)
		*a = smallest_sort(*a);
	else
		*a = small_sort(a, b);
	return (*a);
}
