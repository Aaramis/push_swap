/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 10:41:12 by agardett          #+#    #+#             */
/*   Updated: 2022/09/10 12:23:58 by agardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_ma_list(t_stack **begin)
{
	t_stack	*elt;

	elt = *begin;
	while (elt)
	{
		ft_printf("val: %d - ind: %d - pos: %d - target: %d - costA: %d - costB: %d\n", elt->data, elt->index, elt->pos, elt->target, elt->cost_a, elt->cost_b);
		elt = elt->next;
	}
}

void	ft_index_stack(t_stack **begin)
{
	int	size;
	int	min;
	int	max;
	int	i;

	size = ft_lstsize_s(*begin);
	min = ft_lstmin(*begin);
	max = ft_lstmax(*begin);
	i = 0;
	while (i < size)
	{
		ft_pos_index(*begin, min, ++i);
		ft_pos_index(*begin, max, size--);
		min = ft_lstnb_sup(*begin, min);
		max = ft_lstnb_inf(*begin, max);
	}
}

void	ft_replace(char **str)
{
	int	i;

	i = ft_strlen((*str));
	while (i--)
	{
		if ((*str)[i] == '\n')
			(*str)[i] = ' ';
	}
}

t_stack	*ft_parsing2(char *argv)
{
	char	**tab;
	int		i;
	t_stack	*begin;

	begin = NULL;
	argv = ft_strjoin("A ", argv);
	ft_replace(&argv);
	i = ft_countword(argv, ' ');
	tab = ft_split(argv, ' ');
	begin = ft_parsing(i, tab);
	while (i--)
		free(tab[i]);
	free(tab);
	free(argv);
	return (begin);
}

t_stack	*ft_parsing(int argc, char **argv)
{
	t_stack	*begin;
	t_stack	*newelt;

	newelt = NULL;
	begin = NULL;
	ft_check_argv(argc, argv);
	while (--argc)
	{
		newelt = ft_lstnew_s(ft_atoi(argv[argc]));
		if (newelt)
			ft_lstadd_front_s(&begin, newelt);
		else
		{
			ft_lstclear_s(&begin);
			exit (1);
		}
	}
	ft_index_stack(&begin);
	return (begin);
}
