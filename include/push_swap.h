/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 21:47:13 by jbettini          #+#    #+#             */
/*   Updated: 2021/12/27 10:41:32 by jbettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <stdio.h>

typedef struct s_cpt
{
	int	pa;
	int	rb;
	int	i;
	int	med;
	int	size;
}				t_cpt;

typedef struct s_tmp
{
	int	i;
	int	med;
	int	lst_size;
	int	len_chunk;
}				t_tmp;

t_tmp	init_var(t_tmp *tmp, char **arg, t_list **a);
int		get_med_value(char **arg);
int		med_index(char **arg, int med);
t_list	*make_chunk(t_list **a, t_list **b, char **arg);
t_list	*get_size_chunk(t_list *b, t_list *med);
int		check_valid_num(char *arg);
int		check_limits(char *arg);
int		int_check(char **arg);
int		check_double(char **arg);
int		is_sorted(t_list *a);
void	push_swap(char **arg);
t_list	*create_a(char **arg);
void	swap_the_pile(t_list *pile, char *instruction);
void	swap_all_pile(t_list *a, t_list *b);
void	push_top_pile(t_list **dst, t_list **src, char *instruction);
void	rotate_the_pile(t_list **pile, char *instruction);
void	reverse_the_pile(t_list **pile, char *instruction);
void	swap_all_pile(t_list *a, t_list *b);
void	reverse_all_pile(t_list *a, t_list *b);
int		smallest_case(t_list *a);
t_list	*smallest_sort(t_list *a);
int		get_position(int b, t_list *a);
t_list	*small_case(t_list **a, t_list **b);
t_list	*do_small(t_list **a, t_list **b);
t_list	*small_sort(t_list **a, t_list **b);
void	insert_swap(char **arg);
char	**ft_sort_insert(char **arg);
char	*index_pos(int nb, char **arg);
t_list	*convert_to_pos(t_list **a, char **arg);
void	print_nb_lst(t_list *lst);
void	print_split(char **tab);

#endif