/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:05:53 by jbettini          #+#    #+#             */
/*   Updated: 2021/12/28 09:58:32 by jbettini         ###   ########.fr       */
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

void	remake_the_chunk(t_list **b, t_list **a, int size)
{
	while (size > 0)
	{
		size--;
		push_top_pile(b, a, "pb\n");
	}
}

void	reroll_the_chunk(t_list **b, int size)
{
	while (size > 0)
	{
		size--;
		reverse_the_pile(b, "rrb\n");
	}
}

void	*sort_last_chunk(int size, t_list **b, t_list **a)
{
	int	med;
	int	pa_move;

	pa_move = 0;
	if (size <= 2)
		return (NULL);
	med = get_med_chunk(*b, size);
	while (size >= 0)
	{
		if (ft_atoi((*b)->content) >= med)
		{
			push_top_pile(a, b, "pa\n");
			pa_move++;
		}
		else
			rotate_the_pile(b, "rb\n");	
		size--;
	}
	if (pa_move > 2)
		remake_the_chunk(b, a, pa_move);
	sort_last_chunk(pa_move, b, a);
	return (NULL);
}

int	size_mid_chunk(t_list *b, t_list *med_chunk)
{
	int	i;
	t_list	*tmp;

	while(med_chunk)
	{
		i = 0;
		tmp = b;
		while (tmp)
		{
			if (ft_atoi(med_chunk->content) <= ft_atoi(tmp->content))
				i++;
			tmp = tmp->next;
		}
		if (i < ft_lstsize(b) && i > 0)
			return (i);
		med_chunk = med_chunk->next;
	}
	return (-1);
}

void	cpt_init(t_cpt *cpt, int size, t_list *b)
{
	cpt->pa = 0;
	cpt->med = get_med_chunk(b, size);
	cpt->rb = 0;
}

void	*sort_chunk_rrb(int size, t_list **b, t_list **a)
{
	t_cpt cpt;

	cpt_init(&cpt, size, *b);
	if (size <= 2)
		return (NULL);
	while (size >= 0)
	{
		if (ft_atoi((*b)->content) >= cpt.med)
		{
			push_top_pile(a, b, "pa\n");
			cpt.pa++;
		}
		else
		{
			rotate_the_pile(b, "rb\n");
			cpt.rb++;
		}
		size--;
	}
	if (cpt.pa > 2)
		remake_the_chunk(b, a, cpt.pa);
	if (cpt.rb > 0)
		reroll_the_chunk(b, cpt.rb);
	sort_last_chunk(cpt.pa, b, a);
	sort_last_chunk(cpt.rb, b, a);
	return (NULL);
}

void	sort_middle_chunk(int size, t_list **b, t_list **a, t_list *med_chunk)
{
	while (size_mid_chunk(*b, med_chunk) > 4)
	{
		sort_chunk_rrb(size, b, a);
		sort_top_of_a(a);
	}
}
void	do_qs_chunk(t_list **a, t_list **b, t_list *med_chunk, t_list *size_chunk)
{
	sort_first_chunk(ft_atoi(size_chunk->content), b, a);
	size_chunk = size_chunk->next;
	sort_second_chunk(ft_atoi(size_chunk->content), b, a);
	size_chunk = size_chunk->next;
	while (size_chunk->next)
	{
		sort_middle_chunk(ft_atoi(size_chunk->content), b, a, med_chunk);
		sort_top_of_a(a);
		sort_second_chunk(size_mid_chunk(*b, med_chunk), b, a);	
		size_chunk = size_chunk->next;
	}
	while (ft_lstsize(*b) > 4)
	{
		sort_last_chunk(ft_lstsize(*b), b, a);
	  	sort_top_of_a(a);	
	}
	sort_second_chunk(ft_lstsize(*b), b, a);
}

void	ft_qs_chunk(t_list **a, t_list **b, char **arg)
{
	t_list	*size_chunk;
	t_list	*med_chunk;

	med_chunk = make_chunk(a, b, arg);
	size_chunk = get_size_chunk(*b, med_chunk);
	do_qs_chunk(a, b, med_chunk, size_chunk);
	printf("\n-----A----\n");
	ft_print_list(*a);
	printf("\n-----B----\n");
	ft_print_list(*b);
	printf("\n---------\n");
	ft_lstclear(&med_chunk, free);
	ft_lstclear(&size_chunk, free);
}

t_list	*big_case(t_list **a, t_list **b, char **arg)
{
	arg = ft_sort_insert(arg);
	ft_qs_chunk(a, b , arg);
	//*a = convert_to_pos(a, arg);
	//*a = ft_radix_sort(a, b);
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

// void	sort_top_chunk(int size_chunk, t_list **a, t_list **b, t_cpt *cpt)
// {
// 	if (size_chunk == 1)
// 	{
// 		push_top_pile(a, b, "pa\n");
// 		cpt->allpa++;
// 	}
// 	else if (size_chunk == 2)
// 	{
// 		if (ft_atoi((*b)->content) < ft_atoi((*b)->next->content))
// 		{
// 			swap_the_pile(*b, "sb\n");
// 			cpt->allsb++;
// 		}
// 		push_top_pile(a, b, "pa\n");
// 		push_top_pile(a, b, "pa\n");
// 		cpt->allpa +=2;
// 	}
// }

// void	sort_the_chunk(t_list **a, t_list **b, t_cpt *cpt)
// {
// 	while (cpt->size != 2 && cpt->size != 1)
// 	{
// 		init_cpt(cpt, 1, 0);
// 		cpt->med = get_med_chunk(*b, cpt->size);
// 		while (cpt->i < cpt->size)
// 		{
// 			if (ft_atoi((*b)->content) >= cpt->med)
// 			{
// 				cpt->pa++;
// 				push_top_pile(a, b, "pa\n");
// 				cpt->allpa++;
// 			}
// 			else
// 			{
// 				cpt->rb++;
// 				rotate_the_pile(b, "rb\n");
// 				cpt->allrb++;
// 			}
// 			cpt->i++;
// 		}
// 		cpt->size = cpt->pa;
// 		if (cpt->pa > 2)
// 			while (cpt->pa--)
// 			{
// 				push_top_pile(b, a, "pb\n");
// 				cpt->allpb++;
// 			}
// 		else
// 			cpt->pa = 0;
// 	}
// }

// void	move_rb_on_top(t_cpt *cpt, t_list **b)
// {
// 	cpt->size = cpt->rb;
// 	while(cpt->rb != 0)
// 	{
// 		cpt->rb--;
// 		reverse_the_pile(b, "rrb\n");
// 	cpt->allrrb++;
// 	}
// }
// void	do_qs_chunk(t_list **a, t_list **b, t_list *med_chunk, t_list *size_chunk)
// {
// 	t_cpt	cpt;

// 	init_cpt(&cpt, -1, 0);
// 	while (size_chunk && ft_atoi(size_chunk->content) <= 2)
// 	{
// 		sort_top_chunk(ft_atoi(size_chunk->content), a, b, &cpt);
// 		size_chunk = size_chunk->next;
// 	}
// 	while (size_chunk)
// 	{
// 		if (size_chunk)
// 			init_cpt(&cpt, 2, ft_atoi(size_chunk->content));
// 		while (cpt.size != 0)
// 		{
// 			sort_the_chunk(a, b, &cpt);
// 			sort_top_chunk(cpt.size, a, b, &cpt);
// 			move_rb_on_top(&cpt, b);
// 		}
// 		size_chunk = size_chunk->next;
// 	}
// 	print_cpt(cpt);
// }