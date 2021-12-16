/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:05:53 by jbettini          #+#    #+#             */
/*   Updated: 2021/12/16 19:59:40 by jbettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_a(char **arg)
{
	size_t	i;
	t_list	*a;

	i = 0;
	a = ft_lstnew(arg[i]);
	while (arg[++i])
		ft_lstadd_back(&a, ft_lstnew(arg[i]));
	return (a);
}

int	only_one(t_list *a, int i)
{
	while (a)
	{
		if (((ft_atoi((a)->content) >> i) & 1) == 0)
			return (0);
		a = a->next;
	}
	return (1);
}

t_list	*ft_radix_sort(t_list **a, t_list **b)
{
	int	i;
	int	j;
	int	lst_size;

	lst_size = ft_lstsize(*a);
	i = -1;
	while (++i < ft_bytes_len(ft_lstsize(*a)))
	{
		j = -1;
		while (++j < lst_size)
		{
			if (((ft_atoi((*a)->content) >> i) & 1) == 0)
				push_top_pile(b, a, "pb\n");
			else
				rotate_the_pile(a, "ra\n");
		}
		while (ft_lstsize(*b) > 0)
			push_top_pile(a, b, "pa\n");
	}
	return (*a);
}

t_list	*big_case(t_list **a, t_list **b, char **arg)
{
	arg = ft_sort_insert(arg);
	*a = convert_to_pos(a, arg);
	*a = ft_radix_sort(a, b);
	return (*a);
}

void	push_swap(char **arg)
{
	t_list	*a;
	t_list	*b;
	int		leak;

	leak = 0;
	a = create_a(arg);
	b = NULL;
	if (ft_lstsize(a) <= 5 && ft_lstsize(a) >= 2 && !is_sorted(a))
		a = small_case(&a, &b);
	else if (ft_lstsize(a) > 5)
	{
		leak++;
		a = big_case(&a, &b, arg);
	}
	if (!is_sorted(a))
		printf("is no Sort\n");
	else
		printf("is Sort\n");
	if (leak == 1)
		ft_lstclear(&a, free);
	else
		ft_lstclear(&b, ft_lstdel_content);
	ft_lstclear(&b, ft_lstdel_content);
}

// `ruby -e "puts (0..499).to_a.shuffle.join(' ')"`
