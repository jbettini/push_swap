
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <stdio.h>

int check_valid_num(char *arg);
int check_limits(char *arg);
int int_check(char **arg);
int check_double(char **arg);

void    print_nb_lst(t_list *lst);
void    ft_free_split(char **tab);
size_t ft_double_strlen(char **arg);

#endif

