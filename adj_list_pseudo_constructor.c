//
// Created by WildBoarGonnaGo on 10.04.2022.
//

#include "ft_adj_list.h"

t_graph *adj_list_pseudo_constructor(int v) {
	if (v < 0) {
		perror(" lem-in: adj_list_pseudo_constructor: v: illegal argument");
		ft_putnbr_fd(v, 2);
		return NULL;
	}
	t_graph *dst = (t_graph *)malloc(sizeof(t_graph));
	if (!dst) {
		perror("lem-in: adj_list_pseudo_constructor: dst: memory can't be assigned");
		return NULL;
	}
	dst->verts = v;
	dst->edges = 0;
	dst->adj_array = (t_bat *)malloc(sizeof(t_bag) * v);
	int i = -1;
	while (++i < v) {
		dst->adj_array[i].list = (t_list *) malloc(sizeof(t_list));
		if (!dst->adj_array[i].list) {
			write(2, "lem-in: adj_list_pseudo_constructor: dst->adj_array[",
				  ft_strlen("lem-in: adj_list_pseudo_constructor: dst->adj_array["));
			ft_putnbr_fd(i, 2);
			write(2, "]: memory can't be assigned");
			adj_list_delete_adj_array(&dst);
			return NULL;
		}
	}
	return dst;
}

t_graph *adj_list_pseudo_constructor(int fd) {

}