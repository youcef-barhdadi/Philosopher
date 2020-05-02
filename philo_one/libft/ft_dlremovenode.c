#include "libft.h"


void 				ft_dlstremovenode(t_dlist *lst,void *data ,int (*cmp)(void *, void *))
{
    t_dlstelment *node;
    node = lst->head;
    while (node)
    {
        if (cmp(node->data, data))
        {
            if (node == lst->head)
            {
                lst->head = node->next;
                return ;
            }
            node->prv->next = node->next;
            node = NULL;
            lst->size--;
            break;
        }
        node  = node->next;
    }
}