
#include "queue.h"

void	delete_queue(t_queue **self)
{
	if (!self || !*self)
		err_println(EFAULT);
	queue_dtor(self);
	free(*self);
	*self = NULL;
}