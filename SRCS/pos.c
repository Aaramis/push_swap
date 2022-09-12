/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:18:38 by agardett          #+#    #+#             */
/*   Updated: 2022/09/10 18:29:11 by agardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pos_elt(t_stack **begin)
{
	int	i;
	t_stack	*elt;

	i = 0;
	elt = (*begin);
	while(elt)
	{
		elt->pos = i++;
		elt = elt->next;
	}
}

void	ft_target_elt(t_stack **beg_a, t_stack **beg_b)
{
	t_stack	*elt_a;
	t_stack	*elt_b;

	elt_b = (*beg_b);
	while (elt_b)
	{
		elt_a = (*beg_a);
		while (elt_a && elt_b->index > elt_a->index)
			elt_a = elt_a->next;
		if (elt_a)
			elt_b->target = elt_a->pos;
		else
			elt_b->target = ft_lstlast_s(*beg_a)->pos + 1;
		elt_b = elt_b->next;
	}
}

int	ft_cost_to_top(int size, int value)
{
	if ((size / 2) < value)
		return (value - size);
	else
		return (value);
}

int	ft_cost_fin(int size_a, int size_b, t_stack *elt)
{
	int	na;
	int	nb;

	nb = ft_cost_to_top(size_b, elt->pos);
	na = ft_cost_to_top((size_a + 1), elt->target);
//	printf("size a %d  a %d b %d \n",size_a, na, nb);
	if ((na - nb) == (nb - na))
	{
		if (na > nb)
			return (ft_abs(na));
		return (ft_abs(nb));
	}
	else
		return ((ft_abs(na) + ft_abs(nb)));
}

void	ft_cost(t_stack **beg_a, t_stack **beg_b)
{
	t_stack	*elt_b;
	int	size_a;
	int	size_b;

	elt_b = (*beg_b);
	size_a = ft_lstsize_s(*beg_a);
	size_b = ft_lstsize_s(*beg_b);
	while (elt_b)
	{
		elt_b->cost = ft_cost_fin(size_a, size_b, elt_b);
		elt_b = elt_b->next;
	}
}
