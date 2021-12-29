/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:05:53 by jbettini          #+#    #+#             */
/*   Updated: 2021/12/29 07:47:08 by jbettini         ###   ########.fr       */
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
	// ft_qs_chunk(a, b , arg);
	//ft_chunk_sort(a, b);
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

//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------

//************RECURSIF QUICK SORT************

// void	remake_the_chunk(t_list **b, t_list **a, int size)
// {
// 	while (size > 0)
// 	{
// 		size--;
// 		push_top_pile(b, a, "pb\n");
// 	}
// }

// void	reroll_the_chunk(t_list **b, int size)
// {
// 	while (size > 0)
// 	{
// 		size--;
// 		reverse_the_pile(b, "rrb\n");
// 	}
// }

// void	*sort_last_chunk(int size, t_list **b, t_list **a)
// {
// 	int	med;
// 	int	pa_move;

// 	pa_move = 0;
// 	if (size <= 2)
// 		return (NULL);
// 	med = get_med_chunk(*b, size);
// 	while (size >= 0)
// 	{
// 		if (ft_atoi((*b)->content) >= med)
// 		{
// 			push_top_pile(a, b, "pa\n");
// 			pa_move++;
// 		}
// 		else
// 			rotate_the_pile(b, "rb\n");	
// 		size--;
// 	}
// 	if (pa_move > 2)
// 		remake_the_chunk(b, a, pa_move);
// 	sort_last_chunk(pa_move, b, a);
// 	return (NULL);
// }

// int	size_mid_chunk(t_list *b, t_list *med_chunk)
// {
// 	int	i;
// 	t_list	*tmp;

// 	while(med_chunk)
// 	{
// 		i = 0;
// 		tmp = b;
// 		while (tmp)
// 		{
// 			if (ft_atoi(med_chunk->content) <= ft_atoi(tmp->content))
// 				i++;
// 			tmp = tmp->next;
// 		}
// 		if (i < ft_lstsize(b) && i > 0)
// 			return (i);
// 		med_chunk = med_chunk->next;
// 	}
// 	return (-1);
// }

// void	cpt_init(t_cpt *cpt, int size, t_list *b)
// {
// 	cpt->pa = 0;
// 	cpt->med = get_med_chunk(b, size);
// 	cpt->rb = 0;
// }

// void	*sort_chunk_rrb(int size, t_list **b, t_list **a)
// {
// 	t_cpt cpt;

// 	cpt_init(&cpt, size, *b);
// 	if (size <= 2)
// 		return (NULL);
// 	while (size >= 0)
// 	{
// 		if (ft_atoi((*b)->content) >= cpt.med)
// 		{
// 			push_top_pile(a, b, "pa\n");
// 			cpt.pa++;
// 		}
// 		else
// 		{
// 			rotate_the_pile(b, "rb\n");
// 			cpt.rb++;
// 		}
// 		size--;
// 	}
// 	if (cpt.pa > 2)
// 		remake_the_chunk(b, a, cpt.pa);
// 	if (cpt.rb > 0)
// 		reroll_the_chunk(b, cpt.rb);
// 	sort_last_chunk(cpt.pa, b, a);
// 	sort_last_chunk(cpt.rb, b, a);
// 	return (NULL);
// }

// void	sort_middle_chunk(int size, t_list **b, t_list **a, t_list *med_chunk)
// {
// 	while (size_mid_chunk(*b, med_chunk) > 4)
// 	{
// 		sort_chunk_rrb(size, b, a);
// 		sort_top_of_a(a);
// 	}
// }

// void	sort_first_chunk(int size, t_list **b, t_list **a)
// {
// 	if (size == 1)
// 		push_top_pile(a, b, "pa\n");
// 	else if (size == 2)
// 	{
// 		if (ft_atoi((*b)->content) < ft_atoi((*b)->next->content))
// 			swap_the_pile(*b, "sb\n");
// 		push_top_pile(a, b, "pa\n");
// 		push_top_pile(a, b, "pa\n");
// 	}
// }

// void	sort_top_of_a(t_list **a)
// {
// 	if (ft_atoi((*a)->content) > ft_atoi((*a)->next->content)) 	
// 		swap_the_pile(*a, "sa\n");
// }

// void	seconde_chunk_case_four(int size, int med, t_list **b, t_list **a)
// {
// 	while (size != 2)
// 		{
// 			if (ft_atoi((*b)->content) >= med)
// 			{
// 				push_top_pile(a, b, "pa\n");	
// 				size--;
// 			}
// 			else if (ft_atoi((*b)->content) < med && ft_atoi((*b)->next->content) >= med) 
// 				swap_the_pile(*b, "sb\n");
// 			else
// 			{
// 				rotate_the_pile(b, "rb\n");
// 				if (ft_atoi((*b)->content) < med && ft_atoi((*b)->next->content) >= med) 
// 					swap_the_pile(*b, "sb\n");
// 				else
// 				{
// 					push_top_pile(a, b, "pa\n");	
// 					size--;
// 				}
// 				reverse_the_pile(b, "rrb\n");
// 			}
// 		}	
// }

// void	seconde_chunk_case_three(int size, int med, t_list **b, t_list **a)
// {
// 	while (size != 1)
// 	{
// 		if (ft_atoi((*b)->content) >= med)
// 		{
// 			push_top_pile(a, b, "pa\n");	
// 			size--;
// 		}
// 		else
// 			swap_the_pile(*b, "sb\n");	
// 	}
// 	sort_top_of_a(a);
// 	sort_first_chunk(1, b, a);	
// }

// void	sort_second_chunk(int size, t_list **b, t_list **a)
// {
// 	int	med;

// 	med = get_med_chunk(*b, size);
// 	if (size == 4)
// 	{
// 		seconde_chunk_case_four(size, med, b, a);
// 		sort_top_of_a(a);
// 		sort_first_chunk(2, b, a);
// 	}
// 	if (size == 3)
// 		seconde_chunk_case_three(size, med, b, a);
// 	if (size == 2)
// 		sort_first_chunk(2, b, a);	
// }

// void	do_qs_chunk(t_list **a, t_list **b, t_list *med_chunk, t_list *size_chunk)
// {
// 	sort_first_chunk(ft_atoi(size_chunk->content), b, a);
// 	size_chunk = size_chunk->next;
// 	sort_second_chunk(ft_atoi(size_chunk->content), b, a);
// 	size_chunk = size_chunk->next;
// 	while (size_chunk->next)
// 	{
// 		sort_middle_chunk(ft_atoi(size_chunk->content), b, a, med_chunk);
// 		sort_top_of_a(a);
// 		sort_second_chunk(size_mid_chunk(*b, med_chunk), b, a);	
// 		size_chunk = size_chunk->next;
// 	}
// 	while (ft_lstsize(*b) > 4)
// 	{
// 		sort_last_chunk(ft_lstsize(*b), b, a);
// 	  	sort_top_of_a(a);	
// 	}
// 	sort_second_chunk(ft_lstsize(*b), b, a);
// }

// void	ft_qs_chunk(t_list **a, t_list **b, char **arg)
// {
// 	t_list	*size_chunk;
// 	t_list	*med_chunk;

// 	med_chunk = make_chunk(a, b, arg);
// 	size_chunk = get_size_chunk(*b, med_chunk);
// 	do_qs_chunk(a, b, med_chunk, size_chunk);
// 	ft_lstclear(&med_chunk, free);
// 	ft_lstclear(&size_chunk, free);
// }

//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//************CHUNK SORT************
// int	get_min_value(t_list *a, int n)
// {
// 	int	i;;
// 	int	min;

// 	i = 0;
// 	min = ft_atoi(a->content);
// 	while (a && i < n)
// 	{
// 		if (ft_atoi(a->content) <= min)
// 			min = ft_atoi(a->content);
// 		a = a->next;
// 		i++;
// 	}
// 	return (min);
// }

// int	get_max_value(t_list *a, int n)
// {
// 	int	i;
// 	int	max;

// 	i = 0;
// 	max = ft_atoi(a->content);
// 	while (a && i < n)
// 	{
// 		if (ft_atoi(a->content) >= max)
// 			max = ft_atoi(a->content);
// 		a = a->next;
// 		i++;
// 	}
// 	return (max);
// }

// void	move_by_rra(t_list **a, t_list **b, int nb)
// {
// 	while (ft_atoi((*a)->content) != nb)
// 		reverse_the_pile(a, "rra\n");
// 	push_top_pile(b, a, "pa\n");
// }

// void	move_by_ra(t_list **a, t_list **b, int nb)
// {
// 	while (ft_atoi((*a)->content) != nb)
// 		rotate_the_pile(a, "ra\n");
// 	push_top_pile(b, a, "pa\n");
// }

// int	pos_in_chunk(t_list *tmp, int nb)
// {
// 	int	i;

// 	i = 0;
// 	while (ft_atoi(tmp->content) != nb && tmp)
// 	{
// 		tmp =tmp->next;
// 		i++;
// 	}
// 	return (i);
// }

// int	get_nb_chunk(t_list *a, int min, int max)
// {
// 	while (a && (ft_atoi(a->content) < min || ft_atoi(a->content) >= max))
// 		a = a->next;
// 	if (a)
// 		return (ft_atoi(a->content));
// 	return (-1);
// }

// void	move_the_nb(t_list **a, t_list **b, int chunk, int size_chunk)
// {
// 	int		i;
// 	int		nb;
// 	int		min;
// 	int		max;
// 	t_list	*tmp;

// 	i = 0;
// 	tmp = *a;
// 	min = chunk * size_chunk;
// 	max = (chunk + 1) * size_chunk;
// 	nb = get_nb_chunk(*a, min, max);
// 	while (ft_atoi(tmp->content) != nb)
// 	{
// 		i++;
// 		tmp = tmp->next;
// 	}
// 	if (i >= ft_lstsize(*a) / 2)
// 		move_by_rra(a, b, nb);
// 	else
// 		move_by_ra(a, b, nb);
// }

// void	chunk_make(t_list **a, t_list **b, int chunk_nb)
// {
// 	int	i;
// 	int	tmp;
// 	int	size_chunk;

// 	i = 0;
// 	size_chunk = ft_lstsize(*a) / chunk_nb;
// 	while (i < chunk_nb -1)
// 	{
// 		tmp = size_chunk;
// 		while (tmp--)
// 			move_the_nb(a, b, i, size_chunk);
// 		i++;
// 	}
// }

// void	insert_sort_first_chunk(t_list **a, t_list **b, int size)
// {
// 	int	i;
// 	int	min;
// 	int	size_tmp;

// 	size_tmp = size;
// 	while (size != 0)
// 	{
// 		min = get_min_value(*a, ft_lstsize(*a));		
// 		i = pos_in_chunk(*a, min);
// 		if (i >= ft_lstsize(*a) / 2)
// 			move_by_rra(a, b, min);
// 		else
// 			move_by_ra(a, b, min);
// 		size--;
// 	}
// 	while (size_tmp-- && b)
// 		push_top_pile(a, b, "pb\n");
// }

// void	insert_sort_last_chunk(t_list **a, t_list **b, int size)
// {
// 	int	i;
// 	int	min;
// 	int	size_tmp;

// 	size_tmp = size;
// 	while (size != 0)
// 	{
// 		min = get_max_value(*a, ft_lstsize(*a));		
// 		i = pos_in_chunk(*a, min);
// 		if (i >= ft_lstsize(*a) / 2)
// 			move_by_rra(a, b, min);
// 		else
// 			move_by_ra(a, b, min);
// 		size--;
// 	}
// }

// void	move_and_reroll(t_list **a, t_list **b, int nb)
// {
// 	int	rb;

// 	rb = 0;
// 	while (*b && ft_atoi((*b)->content) != nb)
// 	{
// 		rb++;
// 		rotate_the_pile(b, "rb\n");
// 	}
// 	push_top_pile(a, b, "pb\n");
// 	while (rb != 0 && b)
// 	{
// 		rb--;
// 		reverse_the_pile(b, "rrb\n");
// 	}	
// }

// void	chunk_sort(t_list **a, t_list **b, int size)
// {
// 	int		max;
	
// 	while (*b && size > 0)
// 	{
// 		max = get_max_value(*b, size);		
// 		move_and_reroll(a, b, max);
// 		size--;
// 	}	
// }
// void	ft_chunk_sort(t_list **a, t_list **b)
// {
// 	int	size;

// 	size = ft_lstsize(*a) / 5;
// 	chunk_make(a, b, 5);
// 	insert_sort_first_chunk(a, b, size);
// 	while (ft_lstsize(*b) > size)
// 		chunk_sort(a, b, size);
// 	insert_sort_last_chunk(b, a, size);
// }
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//************ITERATIVE QUICK SORT************


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

//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//************UTILS FOR QS************

// void	init_cpt(t_cpt *cpt, int mode, int size)
// {
// 	if (mode == -1)
// 	{
// 	cpt->allpa = 0;
// 	cpt->allsb = 0;
// 	cpt->allrrb = 0;
// 	cpt->allrb = 0;
// 	cpt->allpb = 0;
// 	cpt->allra = 0;
// 	}
// 	else if (mode == 1)
// 	{
// 		cpt->pa = 0;
// 		cpt->i = 0;
// 	}
// 	else
// 	{
// 		cpt->rb = 0;
// 		cpt->size = size;
// 	}
// }

// void	print_cpt(t_cpt cpt)
// {
// 	printf("PA : %d\n", cpt.allpa);
// 	printf("PB : %d\n", cpt.allpb);
// 	printf("RRB : %d\n", cpt.allrrb);
// 	printf("RB : %d\n", cpt.allrb);
// 	printf("SB : %d\n", cpt.allsb);
// 	printf("RA : %d\n", cpt.allra);
// }

// char	**chunk_to_array(t_list *b, int sizeofchunk)
// {
// 	int		i;
// 	char	**tmp;

// 	i = 0;
// 	if (sizeofchunk <= 0)
// 		return (NULL);
// 	tmp = malloc(sizeof(char *) * sizeofchunk + 1);
// 	if (!tmp)
// 		return (NULL);
// 	while (i < sizeofchunk)
// 	{
// 		tmp[i] = ft_strdup(b->content);
// 		b = b->next;
// 		i++;
// 	}
// 	tmp[i] = NULL;
// 	tmp = ft_sort_insert(tmp);
// 	return (tmp);
// }

// int	get_med_chunk(t_list *b, int sizeofchunk)
// {
// 	char	**tmp;
// 	int		med;

// 	tmp = chunk_to_array(b, sizeofchunk);
// 	med = ft_atoi(tmp[ft_double_strlen(tmp) / 2]);
// 	if (tmp[0] != NULL)
// 	{
// 		med = ft_atoi(tmp[ft_double_strlen(tmp) / 2]);
// 		ft_free_split(tmp);
// 	}
// 	return (med);
// }
// int	get_med_value(char **arg)
// {
// 	size_t	i;

// 	i = ft_double_strlen(arg) / 2;
// 	return (ft_atoi(arg[i]));
// }

// int	med_index(char **arg, int med)
// {
// 	int	i;

// 	i = 0;
// 	while (arg[i])
// 	{
// 		if (ft_atoi(arg[i]) == med)
// 			return (i);
// 		i++;
// 	}
// 	return (-1);
// }

// t_tmp	init_var(t_tmp *tmp, char **arg, t_list **a)
// {
// 		tmp->i = -1;
// 		tmp->len_chunk = 0;
// 		tmp->med = get_med_value(arg);
// 		tmp->lst_size = ft_lstsize(*a);
// 		return (*tmp);
// }

// int	get_min_stack(t_list *b)
// {
// 	int	i;

// 	i = ft_atoi(b->content);
// 	while (b)
// 	{
// 		if (ft_atoi(b->content) <= i)
// 			i = ft_atoi(b->content);
// 		b = b->next;
// 	}
// 	return (i);
// }

// t_list	*make_chunk(t_list **a, t_list **b, char **arg)
// {
// 	t_tmp	tmp;
// 	t_list	*med_chunk;
	
// 	med_chunk = NULL;
// 	while (ft_lstsize(*a) > 2)
// 	{
// 		tmp = init_var(&tmp, arg, a);
// 		arg = &arg[med_index(arg, tmp.med)];
// 		while (tmp.i++ < tmp.lst_size)
// 		{
// 			if (ft_atoi((*a)->content) < tmp.med)
// 				push_top_pile(b, a, "pb\n");
// 			else
// 				rotate_the_pile(a, "ra\n");
// 		}
// 		ft_lstadd_front(&med_chunk, ft_lstnew(ft_itoa(tmp.med)));
// 	}	
// 	small_case(a, b);
// 	ft_lstadd_back(&med_chunk, ft_lstnew(ft_itoa(get_min_stack(*b))));
// 	return (med_chunk);
// }

// t_list	*get_size_chunk(t_list *b, t_list *med)
// {
// 	int	i;
// 	t_list	*size_chunk;

// 	size_chunk = NULL;
// 	med = med->next;
// 	while (b && med)
// 	{
// 		i = 0;
// 		while (b && med && ft_atoi(b->content) >= ft_atoi(med->content))
// 		{
// 			i++;
// 			b = b->next;
// 		}
// 		med = med->next;
// 		ft_lstadd_back(&size_chunk, ft_lstnew(ft_itoa(i)));
// 	}
// 	return (size_chunk);
// }