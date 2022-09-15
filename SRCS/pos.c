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
	t_stack	*elt;
	int		i;

	i = 0;
	elt = (*begin);
	while (elt)
	{
		elt->pos = i++;
		elt = elt->next;
	}
}

int	ft_val_min(t_stack **beg)
{
	t_stack	*elt;
	int		val;

	elt = (*beg);
	val = elt->data;
	while (elt)
	{
		if (elt->data < val)
			val = elt->data;
		elt = elt->next;
	}
	return (val);
}

void	ft_target_elt(t_stack **beg_a, t_stack **beg_b)
{
	t_stack	*elt_a;
	t_stack	*elt_b;
	int		target;

	elt_b = (*beg_b);
	while (elt_b)
	{
		elt_a = (*beg_a);
		target = ft_val_min(beg_a);
		while (elt_a)
		{
			if (elt_a->data < elt_b->data && elt_a->data > target)
				target = elt_a->data;
			elt_a = elt_a->next;
		}
		elt_a = (*beg_a);
		while (elt_a->data != target)
			elt_a = elt_a->next;
		if (elt_a->data < elt_b->data)
			elt_b->target = elt_a->pos + 1;
		else
			elt_b->target = elt_a->pos;
		elt_b = elt_b->next;
	}
}
