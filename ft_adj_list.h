//
// Created by WildBoarGonnaGo on 10.04.2022.
//

#ifndef WILDBOAR_LEM_IN_FT_ADJ_LIST_H
#define WILDBOAR_LEM_IN_FT_ADJ_LIST_H

#include "./libft/libft.h"
#include <string.h>

typedef struct s_bag {
	t_list* list;
	int size;
} t_bag;

typedef struct s_graph {
	int edges;
	int verts;
	t_bag* adj_array;
} t_graph;

void bag_add(void *data);
t_graph *adj_list_pseudo_constructor(int v);
t_graph *adj_list_pseudo_constructor(int fd);
int adj_list_get_verts(const t_graph *src);
int adj_list_get_edges(const t_graph *src);
void adj_list_deep_copy(t_graph **this, t_graph **that);
void adj_list_delete_adj_array(t_graph **this);

#endif //WILDBOAR_LEM_IN_FT_ADJ_LIST_H
