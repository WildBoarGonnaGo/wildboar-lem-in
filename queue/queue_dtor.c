
#include "queue.h"

void	queue_dtor(t_queue **self)
{
	ft_lstclear(&(*self)->node, del_list);
	(*self)->size = 0;
}