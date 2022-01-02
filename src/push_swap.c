/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:05:53 by jbettini          #+#    #+#             */
/*   Updated: 2022/01/02 09:37:45 by jbettini         ###   ########.fr       */
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
				push_top_pile(b, a, "pa\n");
			else
				rotate_the_pile(a, "rb\n");
		}
		while (ft_lstsize(*b) > 0 )
			push_top_pile(a, b, "pb\n");
	}
	while (ft_lstsize(*b) > 0)
			push_top_pile(a, b, "pb\n");
	return (*a);
}

void    ft_print_nlist(t_list *lst, int n)
{
	int	i;

	i = 0;
    while(lst && i < n)
    {
        ft_putstr(lst->content);
        ft_putchar('\n');
        lst = lst->next;
		i++;
    }

}



void	ft_qs_chunk(t_list **a, t_list **b, char **arg)
{
	t_list	*size_chunk;
	int		new_a_chunk;

	size_chunk = make_chunk(a, b, arg);
	while (ft_lstsize(*b))
	{
		while (size_chunk && size_chunk->next)
		{
			new_a_chunk = b_to_a(a, b, &size_chunk);
			a_to_b(a, b, &size_chunk, new_a_chunk);
			sort_top_chunk(a, b, &size_chunk);
		}
		if (size_chunk)
			remake_chunk(a, b, &size_chunk);
	}
	ft_lstclear(&size_chunk, free);
}

t_list	*big_case(t_list **a, t_list **b, char **arg)
{
	arg = ft_sort_insert(arg);
	ft_qs_chunk(a, b, arg);
	return (*a);
}

void	push_swap(char **arg)
{
	t_list	*a;
	t_list	*b;

	a = create_a(arg);
	b = NULL;
	if (ft_lstsize(a) <= 5 && ft_lstsize(a) >= 1 && !is_sorted(a))
		a = small_case(&a, &b);
	else if (ft_lstsize(a) > 5 && !is_sorted(a))
		a = big_case(&a, &b, arg);

	if (!is_sorted(a))
		printf("is no Sort\n");
	else
		printf("is Sort\n");
		
	ft_lstclear(&a, ft_lstdel_content);
	ft_lstclear(&b, ft_lstdel_content);
}

// `ruby -e "puts (0..499).to_a.shuffle.join(' ')"`
/*if (leak == 2)
		ft_lstclear(&a, free);
	else
		ft_lstclear(&a, ft_lstdel_content);*/
