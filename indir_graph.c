//
// Created by WildBoarGonnaGo on 10.04.2022.
//

#include <stdlib.h>
#include "./libft/libft.h"

const int v_num(t_graph *that) { return that->verts; }

t_graph *simple_graph(char *name) {
	t_graph *graph = (t_graph *)malloc(sizeof(t_graph));
	if (!graph) return NULL;
	graph->name = name;
	return graph;
}



int main(int argc, char *argv[]) {
	return 0;
}