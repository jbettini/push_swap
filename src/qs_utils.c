/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qs_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:05:53 by jbettini          #+#    #+#             */
/*   Updated: 2022/01/02 09:46:56 by jbettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	get_med_value(char **arg)
{
	size_t	i;

	i = ft_double_strlen(arg) / 2;
	return (ft_atoi(arg[i]));
}

void	reroll_the_chunk(t_list **lst, int size, char *instruction)
{
	while (size > 0)
	{
		size--;
		reverse_the_pile(lst, instruction);
	}
}
void	sort_top_of_a(t_list **a)
{
	if (ft_atoi((*a)->content) > ft_atoi((*a)->next->content)) 	
		swap_the_pile(*a, "sa\n");
}

void	sort_top_chunk(t_list **a, t_list **b, t_list **size_chunk)
{
	t_list	*tmp;

	tmp = *size_chunk;
	sort_first_chunk(ft_atoi(tmp->content), b, a);
	tmp = tmp->next;
	sort_second_chunk(ft_atoi(tmp->content), b, a); // opti ??
	del_chunk_sorted(size_chunk, 2);
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
	if (!tmp)
		return (-42);
	med = ft_atoi(tmp[ft_double_strlen(tmp) / 2]);
	ft_free_split(tmp);
	return (med);
}