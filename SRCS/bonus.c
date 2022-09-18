//
//	HEADER
//

#include "bonus.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*str;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		if (argc > 2)
			stack_a = ft_parsing(argc, argv);
		else
			stack_a = ft_parsing2(argv[1]);
	}
	while (get_next_line(0, &str) == 1 && str)
	{
		ft_checker_str(&stack_a, &stack_b, str);
		free(str);
	}
	ft_lstclear_s(&stack_b);
	ft_lst_check_b(&stack_a);
	return (0);
}
