//
//	HEADER
//

#include "push_swap.h"

void	ft_s_stack(t_stack ***begin)
{
	t_stack	*elt2;

	elt2 = (**begin)->next;
	(**begin)->next = elt2->next;
	elt2->next = (**begin);
	(*begin) = &elt2;
}

void	ft_r_stack(t_stack ***begin)
{
	t_stack	*last;
	t_stack	*elt;
	t_stack	*pt;

	last = ft_lstlast_s(**begin);

	last->next = (**begin);
	elt = (**begin);
	pt = (**begin)->next;
	(*begin) = &pt;
	elt->next = NULL;
}
