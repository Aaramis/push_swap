/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 10:40:37 by agardett          #+#    #+#             */
/*   Updated: 2022/09/10 14:38:11 by agardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_s(t_stack **begin, int display)
{
	t_stack	*elt2;

	elt2 = (*begin)->next;
	(*begin)->next = elt2->next;
	elt2->next = (*begin);
	(*begin) = elt2;
	if (display == 1)
		write(1, "sa\n", 3);
	else if (display == 2)
		write(1, "sb\n", 3);
}

void	ft_r(t_stack **begin, int display)
{
	t_stack	*last;
	t_stack	*elt;

	last = ft_lstlast_s(*begin);
	last->next = (*begin);
	elt = (*begin);
	(*begin) = ((*begin)->next);
	elt->next = NULL;
	if (display == 1)
		write(1, "ra\n", 3);
	else if (display == 2)
		write(1, "rb\n", 3);
	else if (display == 3)
		write(1, "rr\n", 3);
}

void	ft_rr(t_stack **begin, int display)
{
	t_stack	*last;
	t_stack	*elt;

	elt = (*begin);
	last = ft_lstlast_s(*begin);
	while (elt)
	{
		if (!elt->next->next)
			elt->next = NULL;
		elt = elt->next;
	}
	last->next = (*begin);
	(*begin) = last;
	if (display == 1)
		write(1, "rra\n", 4);
	else if (display == 2)
		write(1, "rrb\n", 4);
	else if (display == 3)
		write(1, "rrr\n", 4);
}

void	ft_p(t_stack **begin_a, t_stack **begin_b, int display)
{
	t_stack	*elt_a;
	t_stack	*elt_b;

	elt_a = (*begin_a)->next;
	elt_b = (*begin_b);
	(*begin_b) = (*begin_a);
	(*begin_b)->next = elt_b;
	(*begin_a) = elt_a;
	if (display == 1)
		write(1, "pa\n", 3);
	else if (display == 2)
		write(1, "pb\n", 3);
}
