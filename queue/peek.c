
#include "queue.h"

void	*peek(t_queue *self)
{
	return (self->node->content);
}