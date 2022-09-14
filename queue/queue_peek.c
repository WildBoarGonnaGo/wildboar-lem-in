
#include "queue.h"

void	*queue_peek(t_queue *self)
{
	return (self->node->content);
}