/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:54:50 by jbettini          #+#    #+#             */
/*   Updated: 2021/12/16 17:01:16 by jbettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_swap(char **arg)
{
	size_t	i;
	size_t	pos;
	int		min;

	i = 0;
	pos = 0;
	min = ft_atoi(arg[i]);
	while (arg[i])
	{
		if (ft_atoi(arg[i]) < min)
		{
			min = ft_atoi(arg[i]);
			ft_swap_str(&arg[0], &arg[i]);
		}
		i++;
	}
}

char	**ft_sort_insert(char **arg)
{
	size_t	i;

	i = -1;
	while (arg[++i])
		insert_swap(&arg[i]);
	return (arg);
}

char	*index_pos(int nb, char **arg)
{
	int	i;

	i = -1;
	while (arg[++i])
	{
		if (ft_atoi(arg[i]) == nb)
			return (ft_itoa(i));
	}
	return (NULL);
}

t_list	*convert_to_pos(t_list	**a, char **arg)
{
	t_list	*tmp;

	tmp = *a;
	while (tmp)
	{
		tmp->content = index_pos(ft_atoi(tmp->content), arg);
		tmp = tmp->next;
	}
	return (*a);
}
