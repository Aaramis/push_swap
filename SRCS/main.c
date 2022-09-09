#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	stack_a = NULL;
	if (argc > 1)
	{
		stack_a = ft_parsing(argc, argv);
		ft_lst_check_sort(&stack_a);
		if (ft_lstsize_s(stack_a) == 3)
			ft_algo_3(&stack_a);
	}
	//ft_printf("tedt");
	(void)argc;
	(void)argv;
	(void)stack_a;
	return(0);
}
