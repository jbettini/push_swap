/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:05:53 by jbettini          #+#    #+#             */
/*   Updated: 2021/12/28 03:29:07 by jbettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_cpt(t_cpt *cpt, int mode, int size)
{
	if (mode == -1)
	{
	cpt->allpa = 0;
	cpt->allsb = 0;
	cpt->allrrb = 0;
	cpt->allrb = 0;
	cpt->allpb = 0;
	cpt->allra = 0;
	}
	else if (mode == 1)
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

void	print_cpt(t_cpt cpt)
{
	printf("PA : %d\n", cpt.allpa);
	printf("PB : %d\n", cpt.allpb);
	printf("RRB : %d\n", cpt.allrrb);
	printf("RB : %d\n", cpt.allrb);
	printf("SB : %d\n", cpt.allsb);
	printf("RA : %d\n", cpt.allra);
}

char	**chunk_to_array(t_list *b, int sizeofchunk)
{
	int		i;
	char	**tmp;

	i = 0;
	if (sizeofchunk <= 0)
		return (NULL);
	tmp = malloc(sizeof(char *) * sizeofchunk + 1);
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
	if (tmp[0] != NULL)
	{
		med = ft_atoi(tmp[ft_double_strlen(tmp) / 2]);
		ft_free_split(tmp);
	}
	return (med);
}

t_list	*ft_radix_sort(t_list **a, t_list **b)
{
	int	i;
	int	j;
	int	lst_size;
	t_cpt cpt; 
	init_cpt(&cpt, -1, 0);

	lst_size = ft_lstsize(*a);
	i = -1;
	while (++i < ft_bytes_len(ft_lstsize(*a)))
	{
		j = -1;
		while (++j < lst_size)
		{
			if (((ft_atoi((*a)->content) >> i) & 1) == 0)
			{
				push_top_pile(b, a, "pb\n");
				cpt.allpb++;
			}
			else
			{
				cpt.allra++;
				rotate_the_pile(a, "ra\n");
			}
		}
		while (ft_lstsize(*b) > 0)
		{
			cpt.allpa++;
			push_top_pile(a, b, "pa\n");
		}
		print_cpt(cpt);
	}
	return (*a);
}