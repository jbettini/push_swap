/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qs_pt1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 09:57:33 by jbettini          #+#    #+#             */
/*   Updated: 2021/12/28 08:22:20 by jbettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_med_value(char **arg)
{
	size_t	i;

	i = ft_double_strlen(arg) / 2;
	return (ft_atoi(arg[i]));
}

int	med_index(char **arg, int med)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (ft_atoi(arg[i]) == med)
			return (i);
		i++;
	}
	return (-1);
}

t_tmp	init_var(t_tmp *tmp, char **arg, t_list **a)
{
		tmp->i = -1;
		tmp->len_chunk = 0;
		tmp->med = get_med_value(arg);
		tmp->lst_size = ft_lstsize(*a);
		return (*tmp);
}

int	get_min_stack(t_list *b)
{
	int	i;

	i = ft_atoi(b->content);
	while (b)
	{
		if (ft_atoi(b->content) <= i)
			i = ft_atoi(b->content);
		b = b->next;
	}
	return (i);
}

t_list	*make_chunk(t_list **a, t_list **b, char **arg)
{
	t_tmp	tmp;
	t_list	*med_chunk;
	
	med_chunk = NULL;
	while (ft_lstsize(*a) > 2)
	{
		tmp = init_var(&tmp, arg, a);
		arg = &arg[med_index(arg, tmp.med)];
		while (tmp.i++ < tmp.lst_size)
		{
			if (ft_atoi((*a)->content) < tmp.med)
				push_top_pile(b, a, "pb\n");
			else
				rotate_the_pile(a, "ra\n");
		}
		ft_lstadd_front(&med_chunk, ft_lstnew(ft_itoa(tmp.med)));
	}	
	small_case(a, b);
	ft_lstadd_back(&med_chunk, ft_lstnew(ft_itoa(get_min_stack(*b))));
	return (med_chunk);
}

t_list	*get_size_chunk(t_list *b, t_list *med)
{
	int	i;
	t_list	*size_chunk;

	size_chunk = NULL;
	med = med->next;
	while (b && med)
	{
		i = 0;
		while (b && med && ft_atoi(b->content) >= ft_atoi(med->content))
		{
			i++;
			b = b->next;
		}
		med = med->next;
		ft_lstadd_back(&size_chunk, ft_lstnew(ft_itoa(i)));
	}
	return (size_chunk);
}