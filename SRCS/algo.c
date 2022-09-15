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
	int		indmax;

	indmax = (*begin)->index;
	s_elt = (*begin);
	while (s_elt)
	{
		if (s_elt->index > indmax)
			indmax = s_elt->index;
		s_elt = s_elt->next;
	}
	if ((*begin)->index == indmax)
		ft_r(begin, 1);
	s_elt = (*begin)->next;
	if (s_elt->index == indmax)
		ft_rr(begin, 1);
	s_elt = (*begin)->next;
	if ((*begin)->index > s_elt->index)
		ft_s(begin, 1);
}

void	ft_sort_by_median(t_stack **begin_a, t_stack **begin_b)
{
	int	size;
	int	i;

	size = ft_lstsize_s(*begin_a);
	i = ft_lstsize_s(*begin_a);
	while (i--)
	{
		if ((*begin_a)->index < (size / 2))
			ft_p(begin_a, begin_b, 2);
		else
			ft_r(begin_a, 1);
	}
	while (ft_lstsize_s(*begin_a) > 3)
		ft_p(begin_a, begin_b, 2);
}
