/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:04:04 by jbettini          #+#    #+#             */
/*   Updated: 2021/12/16 16:05:26 by jbettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_the_pile(t_list *pile, char *instruction)
{
	if (pile && pile->next && ft_lstsize(pile) > 0)
	{
		ft_swap_content(&pile, &(pile->next));
		if (instruction != NULL)
			ft_putstr(instruction);
	}
}

void	push_top_pile(t_list **dst, t_list **src, char *instruction)
{
	t_list	*tmp;

	if (*src)
	{
		tmp = ft_lstnew((*src)->content);
		ft_lstadd_front(dst, tmp);
		tmp = *src;
		*src = (*src)->next;
		tmp->content = NULL;
		free(tmp);
		tmp = NULL;
		ft_putstr(instruction);
		if (ft_lstsize(*src) == 0)
			(*src) = NULL;
	}
}

void	rotate_the_pile(t_list **pile, char *instruction)
{
	t_list	*tmp;

	if (*pile && (*pile)->next)
	{
		tmp = *pile;
		*pile = tmp->next;
		tmp->next = NULL;
		ft_lstadd_back(pile, tmp);
		if (instruction != NULL)
			ft_putstr(instruction);
	}
}

void	reverse_the_pile(t_list **pile, char *instruction)
{
	t_list	*tmp;
	t_list	*tmp2;
	t_list	*new;

	if (*pile && (*pile)->next)
	{
		tmp = ft_lstlast(*pile);
		new = ft_lstnew((ft_lstlast(*pile)->content));
		ft_lstadd_front(pile, new);
		tmp = *pile;
		while (tmp->next)
		{
			tmp2 = tmp;
			tmp = tmp->next;
		}
		tmp->content = NULL;
		free(tmp2->next);
		tmp2->next = NULL;
		if (instruction != NULL)
			ft_putstr(instruction);
	}
}
