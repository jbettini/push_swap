/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qs_chunk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:05:53 by jbettini          #+#    #+#             */
/*   Updated: 2022/01/02 09:33:29 by jbettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del_chunk_sorted(t_list **lst, int to_del)
{
	int		i;
	t_list	*tmp;

	i = 0;
	while (i < to_del)
	{
		tmp = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		*lst = tmp;
		i++;
	}
}

t_list	*make_chunk(t_list **a, t_list **b, char **arg)
{
	t_list	*size_chunk;
	t_cpt	cpt;

	size_chunk = NULL;
	while (ft_lstsize(*a) > 2)
	{
		make_chunk_init(&cpt, *a, arg);
		arg = &arg[ft_double_strlen(arg) / 2];
		while (cpt.i--)
		{
			if (ft_atoi((*a)->content) < cpt.med)
			{
				push_top_pile(b, a, "pa\n");
				cpt.pa++;
			}
			else if (ft_atoi((*a)->content) >= cpt.med)
				rotate_the_pile(a, "ra\n");
		}
		ft_lstadd_front(&size_chunk, ft_lstnew(ft_itoa(cpt.pa)));
	}
	sort_top_of_a(a);
	sort_top_chunk(a, b, &size_chunk);
	return (size_chunk);
}

int	b_to_a(t_list **a, t_list **b, t_list **size_chunk)
{
	t_cpt	cpt;

	b_to_a_init(&cpt, ft_atoi((*size_chunk)->content), b);
	while (cpt.i < cpt.size)
	{
		if (ft_atoi((*b)->content) >= cpt.med)
			push_top_pile(a, b, "pb\n");
		else if (ft_atoi((*b)->content) < cpt.med)
		{
			rotate_the_pile(b, "rb\n");
			cpt.rb++;
		}
		cpt.i++;
	}
	del_chunk_sorted(size_chunk, 1);
	reroll_the_chunk(b, cpt.rb, "rrb\n");
	ft_lstadd_front(size_chunk, ft_lstnew(ft_itoa(cpt.rb)));
	return (cpt.size - cpt.rb);
}

void	a_to_b(t_list **a, t_list **b, t_list **size_chunk, int new_chunk_size)
{
	t_cpt	cpt;
	t_list	*new_b_chunk;

	new_b_chunk = NULL;
	a_to_b_init(&cpt, new_chunk_size, a);
	while (cpt.size > 2)
	{
		while (cpt.i < cpt.size)
		{
			if (ft_atoi((*a)->content) < cpt.med)
			{
				push_top_pile(b, a, "pa\n");
				cpt.pa++;
			}
			else if (ft_atoi((*a)->content) >= cpt.med)
			{
				rotate_the_pile(a, "ra\n");
				cpt.ra++;
			}
			cpt.i++;
		}
		reroll_the_chunk(a, cpt.ra, "rra\n");
		ft_lstadd_front(size_chunk, ft_lstnew(ft_itoa(cpt.pa)));
		a_to_b_init(&cpt, cpt.ra, a);
	}
	sort_top_of_a(a);
}

void	remake_chunk(t_list **a, t_list **b, t_list **size_chunk)
{
	int	new_size;
	t_cpt	cpt;

	remake_init(&cpt, a, b, ft_atoi((*size_chunk)->content));
	while (cpt.i < cpt.size)
	{
		if (ft_atoi((*b)->content) >= cpt.med)
		{
			push_top_pile(a, b, "pb\n");
			cpt.pb++;
		}
		else if (ft_atoi((*b)->content) < cpt.med)
		{
			rotate_the_pile(b, "rb\n");
			cpt.rb++;
		}
		cpt.i++;
	}
	del_chunk_sorted(size_chunk, 1);
	ft_lstadd_front(size_chunk, ft_lstnew(ft_itoa(cpt.rb)));
	a_to_b(a, b, size_chunk, cpt.pb);
}