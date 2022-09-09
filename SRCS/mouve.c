//
//	HEADER
//

#include "push_swap.h"

void	ft_sa(t_stack ***begin)
{
	t_stack	*elt2;

	elt2 = (**begin)->next;
	(**begin)->next = elt2->next;
	elt2->next = (**begin);
	(*begin) = &elt2;
}
