/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 21:47:13 by jbettini          #+#    #+#             */
/*   Updated: 2022/01/02 09:34:43 by jbettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <stdio.h>

typedef struct s_cpt
{
	int	pa;
	int	pb;
	int	rb;
	int	ra;
	int	i;
	int	med;
	int	size;
}				t_cpt;

// init

void	b_to_a_init(t_cpt *cpt, int size, t_list **b);
void	a_to_b_init(t_cpt *cpt, int size, t_list **a);
void	make_chunk_init(t_cpt *cpt, t_list *a, char **arg);
void	remake_init(t_cpt *cpt, t_list **a, t_list **b, int size);

// qs_chunk
void	del_chunk_sorted(t_list **lst, int to_del);
t_list	*make_chunk(t_list **a, t_list **b, char **arg);
int		b_to_a(t_list **a, t_list **b, t_list **size_chunk);
void	a_to_b(t_list **a, t_list **b, t_list **size_chunk, int new_chunk_size);
void	remake_chunk(t_list **a, t_list **b, t_list **size_chunk);

// qs_utils
int		get_min_stack(t_list *b);
int		get_med_value(char **arg);
void	reroll_the_chunk(t_list **lst, int size, char *instruction);
void	sort_top_of_a(t_list **a);
void	sort_top_chunk(t_list **a, t_list **b, t_list **size_chunk);

//qs_first chunk
int		get_med_chunk(t_list *b, int sizeofchunk);
void	sort_first_chunk(int size, t_list **b, t_list **a);
void	sort_second_chunk(int size, t_list **b, t_list **a);
void	seconde_chunk_case_four(int size, int med, t_list **b, t_list **a);
void	seconde_chunk_case_three(int size, int med, t_list **b, t_list **a);

t_list	*ft_radix_sort(t_list **a, t_list **b);
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

#endif