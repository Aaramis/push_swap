/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 10:38:03 by agardett          #+#    #+#             */
/*   Updated: 2022/09/10 17:50:08 by agardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		if (argc > 2)
			stack_a = ft_parsing(argc, argv);
		else
			stack_a = ft_parsing2(argv[1]);
		ft_lst_check_sort(&stack_a);
		if (ft_lstsize_s(stack_a) == 2)
			ft_r(&stack_a, 1);
		else if (ft_lstsize_s(stack_a) == 3)
			ft_algo_3(&stack_a);
		else if (ft_lstsize_s(stack_a) > 3)
		{
			ft_sort_by_median(&stack_a, &stack_b);
			ft_algo_3(&stack_a);
			ft_algo_fin(&stack_a, &stack_b);
			ft_fin_sort(&stack_a);
		}
	}
	ft_lstclear_s(&stack_a);
	return (0);
}
