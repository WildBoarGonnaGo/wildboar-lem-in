
#include "queue.h"

void	queue_ctor(t_queue **self)
{
	(*self)->node = NULL;
	(*self)->size = 0;
}