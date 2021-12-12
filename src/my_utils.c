#include "push_swap.h"

void    ft_free_split(char **tab)
{
    size_t  i;

    i = -1;
    while(tab[++i])
        free(tab[i]);
    free(tab);
    tab = 0;
}

size_t ft_double_strlen(char **arg)
{
    size_t  i;

    i = 0;
    while(arg[i])
        i++;
    return (i);
}

void	ft_list_swap(t_list **a, t_list **b)
{
	void *x;

    x = (*a)->content;
	(*a)->content = (*b)->content;
	(*b)->content = x;
}

void    ft_lstdel_content(void *content)
{
    content = NULL;
}












void    print_split(char **tab)
{
    int i = -1;
    while(tab[++i])
        printf("SPLIT %s\n", tab[i]);
}

void    print_nb_lst(t_list *lst)
{
    int i = 0;
   // printf("size %d\n", ft_lstsize(lst));
    while(lst)
    {
        printf("%d\n",ft_atoi(lst->content));
        lst = lst->next;
        i++;
    }
}