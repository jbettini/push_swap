/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 21:47:13 by jbettini          #+#    #+#             */
/*   Updated: 2021/12/12 22:16:58 by jbettini         ###   ########.fr       */
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

int check_valid_num(char *arg);
int check_limits(char *arg);
int int_check(char **arg);
int check_double(char **arg);

void    swap_the_pile(t_list *pile, char *instruction);
void    swap_all_pile(t_list *a, t_list *b);
void    push_swap(char **arg, int ac);
t_list  *create_a(char **arg);
void    push_top_pile(t_list **dst, t_list **src, char *instruction);
void    rotate_the_pile(t_list **pile, char *instruction);
void    reverse_the_pile(t_list **pile, char *instruction);







void    ft_lstdel_content(void *content);
void    print_nb_lst(t_list *lst);
void    ft_free_split(char **tab);
size_t  ft_double_strlen(char **arg);
void    print_split(char **tab);
void	ft_swap_content(t_list **a, t_list **b);

#endif

