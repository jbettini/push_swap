#include "push_swap.h"

int check_valid_num(char *arg)
{
    int i;
    int j;

    i = 0;
    j = 0;
    if (arg[i] == '-')
        i++;
    while (arg[i])
    {
        if (ft_isdigit(arg[i]))
            j++;
        else
            return (0);
        i++;
    }
    if (j > 10)
        return 0;
    return (1);
}

int check_limits(char *arg)
{
    long long   nb;

    nb = ft_atoll(arg);
    if (nb > 2147483647)
        return (0);
    else if (nb < -2147483648)
        return (0);
    return (1);
}

int check_double(char **arg)
{
    int i;
    int j;

    j = 0;
    i = j + 1;
    while (arg[j])
    {
        i = j + 1;
        while (arg[i])
        {
            if (!ft_strcmp(arg[j], arg[i]))
                return (0);
            i++;
        }
        j++;
    }
    return (1);
}

int int_check(char **arg)
{
    int i;

    i = 0;
    while (arg[i])
    {
        if (!check_valid_num(arg[i]))
            return (0);
        else if (!check_limits(arg[i]))
            return (0);
        else if (!check_double(arg))
            return (0);
        i++;
    }
    return (1);
}