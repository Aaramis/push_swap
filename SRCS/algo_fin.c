//
//	Header
//

#include "push_swap.h"

void	ft_fin_mv(t_stack **stack_a, t_stack **stack_b, int *ca, int *cb)
{
	if ((*ca - *cb) == (*cb - *ca))
	{
		while (*ca < 0 && *cb < 0)
		{
			(*ca)++;
			(*cb)++;
			ft_rr(stack_a, 0);
			ft_rr(stack_b, 3);
		}
		while (*ca > 0 && *cb > 0)
		{
			(*ca)--;
			(*cb)--;
			ft_r(stack_a, 0);
			ft_r(stack_b, 3);
		}
	}
}

void	ft_fin_mv2(t_stack **stack_a, t_stack **stack_b, int *ca, int *cb)
{
	while (*ca < 0)
	{
		(*ca)++;
		ft_rr(stack_a, 1);
	}
	while (*cb < 0)
	{
		(*cb)++;
		ft_rr(stack_b, 2);
	}
	while (*ca > 0)
	{
		(*ca)--;
		ft_r(stack_a, 1);
	}
	while (*cb > 0)
	{
		(*cb)--;
		ft_r(stack_b, 2);
	}
	if (*ca == 0 && *cb == 0)
		ft_p(stack_b, stack_a, 1);
}

void	ft_algo_fin(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*elt;
	int		ca;
	int		cb;

	while ((*stack_b))
	{
		ft_pos_elt(stack_a);
		ft_pos_elt(stack_b);
		ft_target_elt(stack_a, stack_b);
		ft_cost(stack_a, stack_b);
		elt = ft_cos_min(stack_b);
		ca = elt->cost_a;
		cb = elt->cost_b;
		ft_fin_mv(stack_a, stack_b, &ca, &cb);
		ft_fin_mv2(stack_a, stack_b, &ca, &cb);
	}
	ft_fin_sort(stack_a);
}

void	ft_fin_sort(t_stack **beg)
{
	t_stack	*elt;
	int		i;
	int		min;

	elt = (*beg);
	min = ft_val_min(beg);
	while (elt->data != min)
		elt = elt->next;
	i = (elt->index < ft_lstsize_s(*beg));
	elt = (*beg);
	while (elt->data != min)
	{
		if (i)
			ft_rr(beg, 1);
		else
			ft_r(beg, 1);
		elt = (*beg);
	}
}
