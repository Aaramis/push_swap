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
		ft_r(begin);
		ft_printf("ra\n");
	}
	s_elt = (*begin)->next;
	if (s_elt->index == indmax)
	{
		ft_rr(begin);
		ft_printf("rra\n");
	}
	s_elt = (*begin)->next;
	if ((*begin)->index > s_elt->index)
	{
		ft_s(begin);
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
			ft_p(begin_a, begin_b);
			write(1, "pb\n", 3);
		}
		else
		{
			ft_r(begin_a);
			write(1, "ra\n", 3);
		}
	}
	while (ft_lstsize_s(*begin_a) > 3)
	{
		ft_p(begin_a, begin_b);
		write(1, "pb\n", 3);
	}
}

void	ft_algo_fin(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*elt;
	int	ca;
	int	cb;

	while ((*stack_b))
	{
	ft_pos_elt(stack_a);
	ft_pos_elt(stack_b);
	ft_target_elt(stack_a, stack_b);
	ft_cost(stack_a, stack_b);
	elt = ft_cos_min(stack_b);
	ca = elt->cost_a;
	cb = elt->cost_b;
	if ((ca - cb) == (cb - ca)) //meme signe
	{
		while (ca < 0 && cb < 0) //alors rrr
		{
			ca++;
			cb++;
			ft_rr(stack_a);
			ft_rr(stack_b);
			write(1, "rrr\n", 4);
		}
		while (ca > 0 && cb > 0) //alors rr
		{
			ca--;
			cb--;
			ft_r(stack_a);
			ft_r(stack_b);
			write(1, "rr\n", 3);
		}
	}
	while (ca < 0)
	{
		ca++;
		ft_rr(stack_a);
		write(1, "rra\n", 4);
	}
	while (cb < 0)
	{
		cb++;
		ft_rr(stack_b);
		write(1, "rrb\n", 4);
	}
	while (ca > 0)
	{
		ca--;
		ft_r(stack_a);
		write(1, "ra\n", 3);
	}
	while (cb > 0)
	{
		cb--;
		ft_r(stack_b);
		write(1, "rb\n", 3);
	}
	if (ca == 0 && cb == 0)
	{
		ft_p(stack_b, stack_a);
		write(1, "pa\n", 3);
	}
	}
}

void	ft_fin_sort(t_stack **beg)
{
	t_stack	*elt;
	int	min;

	elt = (*beg);
	min = ft_val_min(beg);
	while (elt->data != min)
	{
		ft_rr(beg);
		write(1, "rra\n", 4);
		elt = (*beg);
	}
}
