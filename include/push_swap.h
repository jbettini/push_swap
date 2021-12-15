/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 21:47:13 by jbettini          #+#    #+#             */
/*   Updated: 2021/12/15 18:58:46 by jbettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <stdio.h>
# define SB swap_the_pile(b, "sb\n");
# define SA swap_the_pile(a, "sa\n");
# define SS swap_all_pile(a, b);
# define RA rotate_the_pile(&a, "ra\n");
# define RB rotate_the_pile(&b, "rb\n");
# define RR rotate_all_pile(a, b);
# define RRA reverse_the_pile(&a, "rra\n");
# define RRB reverse_the_pile(&b, "rrb\n");
# define RRR reverse_all_pile(a, b);
# define PB push_top_pile(&b, &a, "pb\n");
# define PA push_top_pile(&a, &b, "pa\n");
# define A a->content
# define NEXT a->next->content
# define ALAST (ft_lstlast(a))->content
# define B b->content
# define NEXTB b->next->content
# define BLAST (ft_lstlast(b))->content

t_ull   itb(int nb);
int     check_valid_num(char *arg);
int     check_limits(char *arg);
int     int_check(char **arg);
int     check_double(char **arg);
int     is_sorted(t_list *a);

void    push_swap(char **arg, int ac);
t_list  *create_a(char **arg);

void    swap_the_pile(t_list *pile, char *instruction);
void    swap_all_pile(t_list *a, t_list *b);
void    push_top_pile(t_list **dst, t_list **src, char *instruction);
void    rotate_the_pile(t_list **pile, char *instruction);
void    reverse_the_pile(t_list **pile, char *instruction);
void    swap_all_pile(t_list *a, t_list *b);
void    reverse_all_pile(t_list *a, t_list *b);

int     smallest_case(t_list *a);
t_list  *smallest_sort(t_list *a, t_list *b);
int     get_position(int b, t_list *a);
t_list  *small_case(t_list **a, t_list **b);
t_list  *do_small(t_list **a, t_list **b);
t_list  *small_sort(t_list **a, t_list **b);

void    insert_swap(char **arg);
char    **ft_sort_insert(char **arg);
char    *index_pos(int nb, char **arg);
t_list  *convert_to_pos(t_list  **a, char **arg);

void    print_nb_lst(t_list *lst);
void    print_split(char **tab);

#endif

