/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:05:53 by jbettini          #+#    #+#             */
/*   Updated: 2022/01/02 06:19:23 by jbettini         ###   ########.fr       */
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

// t_list	*ft_radix_sort(t_list **a, t_list **b)
// {
// 	int	i;
// 	int	j;
// 	int	lst_size;

// 	lst_size = ft_lstsize(*a);
// 	i = -1;
// 	while (++i < ft_bytes_len(ft_lstsize(*a)))
// 	{
// 		j = -1;
// 		while (++j < lst_size)
// 		{
// 			if (((ft_atoi((*a)->content) >> i) & 1) == 0)
// 				push_top_pile(b, a, "pb\n");
// 			else
// 				rotate_the_pile(a, "ra\n");
// 		}
// 		while (ft_lstsize(*b) > 0 )
// 			push_top_pile(a, b, "pa\n");
// 	}
// 	while (ft_lstsize(*b) > 0)
// 			push_top_pile(a, b, "pa\n");
// 	return (*a);
// }

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

void	make_chunk_init(t_cpt *cpt, t_list *a, char **arg)
{
	cpt->i = ft_lstsize(a);
	cpt->pa = 0;
	cpt->med = get_med_value(arg);
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

void	b_to_a_init(t_cpt *cpt, int size, t_list **b)
{
	cpt->size = size;
	cpt->rb = 0;
	cpt->i = 0;
	cpt->med = get_med_chunk(*b, size);
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
	reroll_the_chunk(b, cpt.rb, "rrb\n");
	del_chunk_sorted(size_chunk, 1);
	ft_lstadd_front(size_chunk, ft_lstnew(ft_itoa(cpt.rb)));
	return (cpt.size - cpt.rb);
}

void	a_to_b_init(t_cpt *cpt, int size, t_list **a)
{
	cpt->i = 0;
	cpt->size = size;
	cpt->med = get_med_chunk(*a, size);
	cpt->pa = 0;
	cpt->ra = 0;
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

void	ft_qs_chunk(t_list **a, t_list **b, char **arg)
{
	t_list	*size_chunk;
	int		new_a_chunk;

	size_chunk = make_chunk(a, b, arg);
	while (ft_lstsize(*b))
	{
		new_a_chunk = b_to_a(a, b, &size_chunk);
		a_to_b(a, b, &size_chunk, new_a_chunk);
		sort_top_chunk(a, b, &size_chunk);
	}
	printf("\n---A----\n");
	ft_print_list(*a);
	printf("\n---B----\n");
	ft_print_nlist(*b, 10);
	printf("\n---size chunk----\n");
	ft_print_list(size_chunk);
	ft_lstclear(&size_chunk, free);
}

t_list	*big_case(t_list **a, t_list **b, char **arg)
{
	arg = ft_sort_insert(arg);
	// *a = convert_to_pos(a, arg);
	ft_qs_chunk(a, b, arg);
	// if (ft_lstsize(*a) <= 100)
	// 	*a = ft_radix_sort(a, b);
	// else
	// ft_print_list(*a);
	// 	ft_chunk_sort(a, b);
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
	if (ft_lstsize(a) <= 5 && ft_lstsize(a) >= 1 && !is_sorted(a))
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
	ft_lstclear(&a, ft_lstdel_content);
	ft_lstclear(&b, ft_lstdel_content);
}

// `ruby -e "puts (0..499).to_a.shuffle.join(' ')"`
/*if (leak == 2)
		ft_lstclear(&a, free);
	else
		ft_lstclear(&a, ft_lstdel_content);*/
