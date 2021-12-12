
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <stdio.h>

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
void	ft_list_swap(t_list **a, t_list **b);

#endif

