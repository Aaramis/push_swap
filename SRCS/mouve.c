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

void	ft_s_stack(t_stack **begin)
{
	t_stack	*elt2;

	elt2 = (*begin)->next;
	(*begin)->next = elt2->next;
	elt2->next = (*begin);
	(*begin) = elt2;
}

void	ft_r_stack(t_stack **begin)
{
	t_stack	*last;
	t_stack	*elt;

	last = ft_lstlast_s(*begin);
	last->next = (*begin);
	elt = (*begin);
	(*begin) = ((*begin)->next);
	elt->next = NULL;
}

void	ft_rr_stack(t_stack **begin)
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
}

void	ft_p_stack(t_stack **begin_a, t_stack **begin_b)
{
	t_stack	*elt_a;
	t_stack	*elt_b;

	elt_a = (*begin_a)->next;
	elt_b = (*begin_b);

//	ft_print_ma_list(begin_a);
//	printf("\n");
	(*begin_b) = (*begin_a);
	(*begin_b)->next = elt_b;
	(*begin_a) = elt_a;
}
