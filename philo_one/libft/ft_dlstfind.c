#include "libft.h"


t_dlstelment		*ft_dlstfind(t_dlist *lst, void *data, int (*cmp)(void *, void *))
{
    t_dlstelment *node;

    node = lst->head;
    while (node)
    {
        if (cmp(data, node->data))
        {
            return (node);
        }
        node = node->next;
    }
    return (NULL);
}