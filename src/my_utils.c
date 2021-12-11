#include "push_swap.h"

void    print_nb_lst(t_list *lst)
{
    int i = 0;
    while(lst)
    {
        printf("%d\n",ft_atoi(lst->content));
        lst = lst->next;
    }
}