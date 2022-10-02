/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 10:38:37 by agardett          #+#    #+#             */
/*   Updated: 2022/10/02 16:43:50 by agardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lst_check_sort(t_stack **begin)
{
	t_stack	*next;
	t_stack	*first;

	first = *begin;
	while (first && first->next)
	{
		next = first->next;
		if (next->index < first->index)
			break ;
		first = next;
	}
	if (!first->next)
	{
		ft_lstclear_s(begin);
		exit (0);
	}
}

void	ft_check_nbr(char *str, char **tab, char *argv, int j)
{
	if (*str == 45)
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
		{
			if (j)
				ft_free_tab(tab, argv);
			write(2, "Error\n", 6);
			exit (1);
		}
		str++;
	}
}

long int	ft_l_atoi(const char *nptr)
{
	long int	value;
	long int	neg;
	long int	i;

	if (!nptr)
		return (0);
	value = 0;
	i = 0;
	neg = 1;
	while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-')
	{
		i++;
		neg = -1;
	}
	if (nptr[i] == '+' && neg == 1)
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9' && nptr)
	{
		value = value * 10 + nptr[i] - '0';
		i++;
	}
	return (value * neg);
}

int	ft_check_overflow(char **argv, int pos)
{
	int	i;

	i = 0;
	if (ft_strlen(argv[pos]) > ft_strlen("21474836470"))
		i = 1;
	if (ft_l_atoi(argv[pos]) > 2147483647)
		i = 1;
	if (ft_l_atoi(argv[pos]) < -2147483648)
		i = 1;
	return (i);
}

void	ft_check_argv(int argc, char **argv, char *argv2, int j)
{
	int	pos;
	int	pos2;
	int	i;

	pos = argc;
	i = 0;
	while (--pos)
	{
		pos2 = pos;
		ft_check_nbr(argv[pos], argv, argv2, j);
		i = ft_check_overflow(argv, pos);
		while (--pos2 && !i)
		{
			if (ft_atoi(argv[pos]) == ft_atoi(argv[pos2]))
				i = 1;
		}
		if (i && j)
			ft_free_tab(argv, argv2);
		if (i)
		{
			write(2, "Error\n", 6);
			exit (1);
		}
	}
}
