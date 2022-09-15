//
//	header
//

#include "push_swap.h"

int	ft_cos_tot(int ca, int cb)
{
	if ((ca - cb) == (cb - ca))
	{
		if (ca > cb)
			return (ft_abs(ca));
		return (ft_abs(cb));
	}
	else
		return ((ft_abs(ca) + ft_abs(cb)));
}

t_stack	*ft_cos_min(t_stack **begin)
{
	t_stack	*elt;
	t_stack	*ret;
	int		n;

	elt = (*begin);
	ret = (*begin);
	n = ft_cos_tot((*begin)->cost_a, (*begin)->cost_b);
	while (elt)
	{
		if (n > ft_cos_tot(elt->cost_a, elt->cost_b))
		{
			n = ft_cos_tot(elt->cost_a, elt->cost_b);
			ret = elt;
		}
		if (n == 0)
			return (ret);
		elt = elt->next;
	}
	return (ret);
}

int	ft_cost_to_top(int size, int value)
{
	if ((size / 2) < value)
		return (value - size);
	else
		return (value);
}

void	ft_cost(t_stack **beg_a, t_stack **beg_b)
{
	t_stack	*elt;
	int		size_a;
	int		size_b;

	elt = (*beg_b);
	size_a = ft_lstsize_s(*beg_a);
	size_b = ft_lstsize_s(*beg_b);
	while (elt)
	{
		elt->cost_b = ft_cost_to_top(size_b, elt->pos);
		elt->cost_a = ft_cost_to_top((size_a), elt->target);
		elt = elt->next;
	}
}
