
#include "queue.h"

void	enqueue(t_queue **self, void *data)
{
	t_list	*new_lst;

	new_lst = ft_lstnew(data);
	ft_lstadd_back(&(*self)->node, new_lst);
	++(*self)->size;
}