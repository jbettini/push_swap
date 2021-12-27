/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:05:53 by jbettini          #+#    #+#             */
/*   Updated: 2021/12/27 14:48:20 by jbettini         ###   ########.fr       */
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

void	sort_top_chunk(int size_chunk, t_list **a, t_list **b)
{
	if (size_chunk == 1)
		push_top_pile(a, b, "pa\n");
	else if (size_chunk == 2)
	{
		if (ft_atoi((*b)->content) < ft_atoi((*b)->next->content))
			swap_the_pile(*b, "sb\n");
		push_top_pile(a, b, "pa\n");
		push_top_pile(a, b, "pa\n");
	}
}

char	**chunk_to_array(t_list *b, int sizeofchunk)
{
	int		i;
	char	**tmp;

	i = 0;
	if (sizeofchunk <= 0)
		return (NULL);
	tmp = malloc(sizeof(char *) * sizeofchunk);
	if (!tmp)
		return (NULL);
	while (i < sizeofchunk)
	{
		tmp[i] = ft_strdup(b->content);
		b = b->next;
		i++;
	}
	tmp[i] = NULL;
	tmp = ft_sort_insert(tmp); 
	return (tmp);
}

int	get_med_chunk(t_list *b, int sizeofchunk)
{
	char	**tmp;
	int		med;

	tmp = chunk_to_array(b, sizeofchunk);
	med = ft_atoi(tmp[ft_double_strlen(tmp) / 2]);
	if (tmp != NULL)
	{
		med = ft_atoi(tmp[ft_double_strlen(tmp) / 2]);
	//	ft_free_split(tmp);
	}
	return (med);
}

void	init_cpt(t_cpt *cpt, int mode, int size)
{
	if (mode == 1)
	{
		cpt->pa = 0;
		cpt->i = 0;
	}
	else
	{
		cpt->rb = 0;
		cpt->size = size;
	}
}

void	sort_the_chunk(t_list **a, t_list **b, t_cpt *cpt)
{
	while (cpt->size != 2 && cpt->size != 1)
	{
		init_cpt(cpt, 1, 0);
		cpt->med = get_med_chunk(*b, cpt->size);
		while (cpt->i < cpt->size)
		{
			if (ft_atoi((*b)->content) >= cpt->med)
			{
				cpt->pa++;
				push_top_pile(a, b, "pa\n");
			}
			else
			{
				cpt->rb++;
				rotate_the_pile(b, "rb\n");
			}
			cpt->i++;
		}
		cpt->size = cpt->pa;
		while (cpt->pa--)
			push_top_pile(b, a, "pb\n");
	}
}

void	move_rb_on_top(t_cpt *cpt, t_list **b)
{
	cpt->size = cpt->rb;
	while(cpt->rb != 0)
	{
		cpt->rb--;
		reverse_the_pile(b, "rrb\n");
	}
}

void	do_qs_chunk(t_list **a, t_list **b, t_list *med_chunk, t_list *size_chunk)
{
	t_cpt	cpt;

	while (size_chunk && ft_atoi(size_chunk->content) <= 2)
	{
		sort_top_chunk(ft_atoi(size_chunk->content), a, b);
		size_chunk = size_chunk->next;
	}
	while (size_chunk)
	{
		if (size_chunk)
			init_cpt(&cpt, 2, ft_atoi(size_chunk->content));
		while (cpt.size != 0)
		{
			sort_the_chunk(a, b, &cpt);
			sort_top_chunk(cpt.size, a, b);
			move_rb_on_top(&cpt, b);
		}
		size_chunk = size_chunk->next;
	}
	//ft_print_list(*a);
	//sort_top_chunk(cpt.size, a, b);
	//sort_top_chunk(cpt.size, a, b);	
	/*while (cpt.size != 0)
	{
		printf("size %d\n", cpt.size);
		sort_the_chunk(a, b, &cpt);
		sort_top_chunk(cpt.size, a, b);
		//move_rb_on_top(cpt.rb, b);
		cpt.size = cpt.rb;
	}*/
	//ft_print_list(*b);
}

void	ft_qs_chunk(t_list **a, t_list **b, char **arg)
{
	t_list	*size_chunk;
	t_list	*med_chunk;

	med_chunk = make_chunk(a, b, arg);
	size_chunk = get_size_chunk(*b, med_chunk);
	do_qs_chunk(a, b, med_chunk, size_chunk);
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