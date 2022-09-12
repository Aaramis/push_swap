/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 10:36:07 by agardett          #+#    #+#             */
/*   Updated: 2022/09/10 15:51:01 by agardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_ma_list(t_stack **begin)
{
	t_stack	*elt;

	elt = *begin;
	while (elt)
	{
		//ft_printf("val: %d - ind: %d - pos: %d - ad: %p - pt: %p \n", elt->data, elt->index, elt->pos, elt, elt->next);
		ft_printf("val: %d - ind: %d - pos: %d - target: %d - costA: %d - costB: %d\n", elt->data, elt->index, elt->pos, elt->target, elt->cost_a, elt->cost_b);
		elt = elt->next;
	}
}

void	ft_algo_3(t_stack **begin)
{
	t_stack	*s_elt;
	int	indmax;

	indmax = (*begin)->index;
	s_elt = (*begin);
	while (s_elt)
	{
		if (s_elt->index > indmax)
			indmax = s_elt->index;
		s_elt = s_elt->next;
	}
	if ((*begin)->index == indmax)
	{
		ft_r_stack(begin);
		ft_printf("ra\n");
	}
	s_elt = (*begin)->next;
	if (s_elt->index == indmax)
	{
		ft_rr_stack(begin);
		ft_printf("rra\n");
	}
	s_elt = (*begin)->next;
	if ((*begin)->index > s_elt->index)
	{
		ft_s_stack(begin);
		ft_printf("sa\n");
	}
}

void	ft_sort_by_median(t_stack **begin_a, t_stack **begin_b)
{
	int	size;
	int	i;

	size = ft_lstsize_s(*begin_a);
	i = ft_lstsize_s(*begin_a);
	while (i--)
	{
		if ((*begin_a)->index < (size/2))
		{
			ft_p_stack(begin_a, begin_b);
			write(1, "pb\n", 3);
		}
		else
		{
			ft_r_stack(begin_a);
			write(1, "ra\n", 3);
		}
	}
	while (ft_lstsize_s(*begin_a) > 3)
	{
		ft_p_stack(begin_a, begin_b);
		write(1, "pb\n", 3);
		
	}
//	ft_print_ma_list(begin_a);
//	printf("\n");
//	ft_print_ma_list(begin_b);
}
