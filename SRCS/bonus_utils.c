/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 10:36:35 by agardett          #+#    #+#             */
/*   Updated: 2022/09/10 10:36:54 by agardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	ft_nv_b3(t_stack **stack_a, t_stack **stack_b, char *str)
{
	if (!ft_strncmp(str, "rrr", 3))
	{
		ft_rr(stack_a, 0);
		ft_rr(stack_b, 0);
		return (1);
	}
	else if (!ft_strncmp(str, "rra", 3))
	{
		ft_rr(stack_a, 0);
		return (1);
	}
	else if (!ft_strncmp(str, "rrb", 3))
	{
		ft_rr(stack_b, 0);
		return (1);
	}
	return (0);
}

int	ft_nv_b2(t_stack **stack_a, t_stack **stack_b, char *str)
{
	if (!ft_strncmp(str, "ra", 2))
	{
		ft_r(stack_a, 0);
		return (1);
	}
	else if (!ft_strncmp(str, "rb", 2))
	{
		ft_r(stack_b, 0);
		return (1);
	}
	else if (!ft_strncmp(str, "rr", 2))
	{
		ft_r(stack_a, 0);
		ft_r(stack_b, 0);
		return (1);
	}
	else if (!ft_strncmp(str, "ss", 2))
	{
		ft_s(stack_a, 0);
		ft_s(stack_b, 0);
		return (1);
	}	
	return (0);
}

int	ft_nv_b1(t_stack **stack_a, t_stack **stack_b, char *str)
{
	if (!ft_strncmp(str, "pa", 2))
	{
		ft_p(stack_b, stack_a, 0);
		return (1);
	}
	else if (!ft_strncmp(str, "pb", 2))
	{
		ft_p(stack_a, stack_b, 0);
		return (1);
	}
	else if (!ft_strncmp(str, "sa", 2))
	{
		ft_s(stack_a, 0);
		return (1);
	}
	else if (!ft_strncmp(str, "sb", 2))
	{
		ft_s(stack_b, 0);
		return (1);
	}
	return (0);
}

void	ft_checker_str(t_stack **stack_a, t_stack **stack_b, char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) == 3)
	{
		i += ft_nv_b1(stack_a, stack_b, str);
		i += ft_nv_b2(stack_a, stack_b, str);
	}
	else
		i += ft_nv_b3(stack_a, stack_b, str);
	if (!i)
	{
		i = write(2, "Error\n", 6);
		(void)i;
		exit (1);
	}
}

void	ft_lst_check_b(t_stack **begin)
{
	t_stack	*next;
	t_stack	*first;
	int		i;

	first = (*begin);
	while (first && first->next)
	{
		next = first->next;
		if (next->index < first->index)
			break ;
		first = next;
	}
	if (!first->next)
		i = write(1, "OK\n", 3);
	else
		i = write(1, "KO\n", 3);
	(void)i;
	ft_lstclear_s(begin);
	exit (0);
}
