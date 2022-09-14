
#include "queue.h"

void	*dequeue(t_queue **self)
{
	t_list	*member;
	void	*item;

	member = (*self)->node;
	item = (*self)->node->content;
	if (queue_is_empty(*self))
		err_println(EFAULT);
	if ((*self)->node->next)
		(*self)->node = (*self)->node->next;
	else
	{
		free((*self)->node);
		(*self)->node = NULL;
	}
	--(*self)->size;
	if ((*self)->node)
		ft_lstdelone(member, del_list);
	return (item);
}