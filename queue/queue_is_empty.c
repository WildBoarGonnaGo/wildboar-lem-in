
#include "queue.h"

int	queue_is_empty(t_queue *self)
{
	return (!self->size);
}