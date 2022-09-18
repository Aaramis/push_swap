//
//	HEADER
//

#include "bonus.h"

int	ft_nv_b3(t_stack **stack_a, t_stack **stack_b, char *str)
{
	if (!ft_strncmp(str, "rrr", 2))
	{
		ft_rr(stack_a, 0);
		ft_rr(stack_b, 3);
		return (1);
	}
	if (!ft_strncmp(str, "rr", 3))
	{
		ft_r(stack_a, 0);
		ft_r(stack_b, 3);
		return (1);
	}
	if (!ft_strncmp(str, "ss", 3))
	{
		ft_s(stack_a, 0);
		ft_s(stack_b, 3);
		return (1);
	}	
	return (0);
}

int	ft_nv_b2(t_stack **stack_a, t_stack **stack_b, char *str)
{
	if (!ft_strncmp(str, "ra", 2))
	{
		ft_r(stack_a, 1);
		return (1);
	}
	if (!ft_strncmp(str, "rb", 2))
	{
		ft_r(stack_b, 2);
		return (1);
	}
	if (!ft_strncmp(str, "rra", 3))
	{
		ft_rr(stack_a, 1);
		return (1);
	}
	if (!ft_strncmp(str, "rrb", 3))
	{
		ft_rr(stack_b, 2);
		return (1);
	}
	return (0);
}

int	ft_nv_b1(t_stack **stack_a, t_stack **stack_b, char *str)
{
	if (!ft_strncmp(str, "pa", 2))
	{
		ft_p(stack_a, stack_b, 1);
		return (1);
	}
	if (!ft_strncmp(str, "pb", 2))
	{
		ft_p(stack_b, stack_a, 2);
		return (1);
	}
	if (!ft_strncmp(str, "sa", 2))
	{
		ft_s(stack_a, 1);
		return (1);
	}
	if (!ft_strncmp(str, "sb", 2))
	{
		ft_s(stack_b, 2);
		return (1);
	}
	return (0);
}


void	ft_checker_str(t_stack **stack_a, t_stack **stack_b, char *str)
{
	int	i;

	i = 0;
	i += ft_nv_b1(stack_a, stack_b, str);
	i += ft_nv_b2(stack_a, stack_b, str);
	i += ft_nv_b3(stack_a, stack_b, str);
	if (!i)
	{
		i = write(1, "Error\n", 6);
		(void)i;
		exit (1);
	}
}

void	ft_lst_check_b(t_stack **begin)
{
	t_stack	*next;
	t_stack	*first;

	first = (*begin);
	while (first && first->next)
	{
		next = first->next;
		if (next->index < first->index)
			break ;
		first = next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*str;
	int 	i;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		if (argc > 2)
			stack_a = ft_parsing(argc, argv);
		else
			stack_a = ft_parsing2(argv[1]);
	}
	while (get_next_line(0, &str) == 1)
	{
		ft_printf("%s\n", str);
		ft_checker_str(&stack_a, &stack_b, str);
		ft_print_ma_list(&stack_a);
		free(str);
	}
	(void)i;
	(void)str;
	ft_lst_check_sort(&stack_a);
	ft_print_ma_list(&stack_a);
	ft_printf("\n");
	ft_print_ma_list(&stack_b);
	ft_lstclear_s(&stack_a);
	ft_lstclear_s(&stack_b);
	return (0);
}
