//
//	HEADER
//

#include "bonus.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		stack_a = ft_parsing(argc, argv);
		ft_lst_check_sort(&stack_a);
	}
	ft_print_ma_list(&stack_a);
	ft_printf("\n");
	ft_print_ma_list(&stack_b);
	(void)argc;
	(void)argv;
	ft_printf("Hello World!\n");
	return (0);
}
