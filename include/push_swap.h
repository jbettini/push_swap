/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 21:47:13 by jbettini          #+#    #+#             */
/*   Updated: 2021/12/28 06:18:24 by jbettini         ###   ########.fr       */
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
	int	allpa;
	int	allsb;
	int	allrrb;
	int	allpb;
	int	allrb;
	int	allra;
}				t_cpt;

typedef struct s_tmp
{
	int	i;
	int	med;
	int	lst_size;
	int	len_chunk;
}				t_tmp;


void	sort_second_chunk(int size, t_list **b, t_list **a);
void	seconde_chunk_case_three(int size, int med, t_list **b, t_list **a);
void	seconde_chunk_case_four(int size, int med, t_list **b, t_list **a);
void	sort_top_of_a(t_list **a);
void	sort_first_chunk(int size, t_list **b, t_list **a);
t_list	*ft_radix_sort(t_list **a, t_list **b);
int		get_med_chunk(t_list *b, int sizeofchunk);
char	**chunk_to_array(t_list *b, int sizeofchunk);
void	print_cpt(t_cpt cpt);
void	init_cpt(t_cpt *cpt, int mode, int size);
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

#endif