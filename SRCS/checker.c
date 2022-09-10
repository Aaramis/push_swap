/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 10:38:37 by agardett          #+#    #+#             */
/*   Updated: 2022/09/10 14:29:45 by agardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lst_check_sort(t_stack **begin)
{
	t_stack	*next;
	t_stack	*first;

	first = *begin;
	// ft_print_ma_list(begin);
	while (first && first->next)
	{
		next = first->next;
//		ft_printf("%d %d\n",next->index, first->index);
		if (next->index < first->index)
			break ;
		first = next;
		next = next->next;
	}
//	printf("%p %d\n",first->next, first->index);
	if (!first->next)
		exit (0);
}

void	ft_check_nbr(char *str)
{
	if (*str == 45)
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
		{
			write(2, "Error\n", 6);
			exit (1);
		}
		str++;
	}
}

// ne check pas encore les overflow
void	ft_check_argv(int argc, char **argv)
{
	int	pos;
	int	pos2;

	pos = argc;
	while (--pos)
	{
		pos2 = pos;
		ft_check_nbr(argv[pos]);
		while (--pos2)
		{
			if (ft_atoi(argv[pos]) == ft_atoi(argv[pos2]))
			{
				write(2, "Error\n", 6);
				exit (1);
			}
		}
	}
}
