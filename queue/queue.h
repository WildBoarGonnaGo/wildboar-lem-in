#ifndef QUEUE_H
# define QUEUE_H
# include "../new.h"

typedef struct s_queue
{
	t_list			*node;
	unsigned int	size;
}	t_queue;

t_queue	*new_queue();
void	queue_ctor(t_queue **self);
void	delete_queue(t_queue **self);
void	queue_dtor(t_queue **self);
void	enqueue(t_queue **self, void *data);
void	*dequeue(t_queue **self);
void	*peek(t_queue *self);
int		stack_is_empty(t_queue *self);

#endif