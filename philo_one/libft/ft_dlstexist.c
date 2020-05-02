#include "libft.h"
int					ft_dlstexist(t_dlist *lst, void *data, int (*cmp)(void *, void *))
{
    return (ft_dlstfind(lst, data, cmp) != NULL ? 1 : 0);
}