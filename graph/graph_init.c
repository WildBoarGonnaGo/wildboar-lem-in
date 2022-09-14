

#include "graph_ctor_in.h"

void	graph_init(t_graph **me, int *num)
{
	(*me)->v = 0;
	(*me)->e = 0;
	(*me)->start = -2;
	(*me)->end = -2;
	(*me)->ants = 0;
	(*me)->adj = NULL;
	(*me)->size = 0;
	*num = 0;
	(*me)->state = 0;
}