#ifndef NEW_H
# define NEW_H
# include "bag.h"
# include <sys/errno.h>
# include <string.h>

void				err_println(int errnum);
void				err_println_str(char *msg);
t_st_bag			*new_bag(void);
void				delete_bag(t_st_bag **item, void (*del)(void *));
t_st_bag_iterator	*new_bag_iterator(const t_st_bag *item);
void				delete_bag_iterator(t_st_bag_iterator **item);

#endif