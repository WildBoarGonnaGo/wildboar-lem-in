
#include "queue.h"

t_queue	*new_queue()
{
	t_queue	*res;

	res = (t_queue *)malloc(sizeof(t_queue));
	if (!res)
		err_println(ENOMEM);
	queue_ctor(&res);
	return (res);
}