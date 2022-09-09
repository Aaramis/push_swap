//
//	HEADER
//

#include "push_swap.h"

void	ft_print_ma_list(t_stack **begin)
{
	t_stack	*elt;

	elt = *begin;
	while (elt)
	{
		ft_printf("value: %d - index : %d\n",elt->data, elt->index);
		elt = elt->next;
	}
}

void	ft_algo_3(t_stack **begin)
{
	t_stack	*s_elt;

	if ((*begin)->index == 3)
	{
		ft_print_ma_list(begin);
		ft_printf("\n");
		ft_r_stack(&begin);
		ft_print_ma_list(begin);
		ft_printf("ra\n");
	}
	s_elt = (*begin)->next;
	if (s_elt->index == 3)
		ft_printf("rra\n");
	if ((*begin)->index > s_elt->index)
	{
		ft_print_ma_list(begin);
		ft_printf("\n");
		ft_s_stack(&begin);
		ft_print_ma_list(begin);
		ft_printf("sa\n");
	}
}

//fct deja triée

