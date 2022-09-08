//#############
//## Header ###
//#############

#include "push_swap.h"

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
		//ft_printf(" %d min : %d - %d max : %d \n", i, min, size, max);
		ft_pos_index(*begin, max, size--);
		min = ft_lstnb_sup(*begin, min);
		max = ft_lstnb_inf(*begin, max);
	}
}

t_stack  	*ft_parsing(int argc,char **argv)
{
	t_stack	*begin;
	t_stack	*newelt;

	begin = NULL;
	newelt = NULL;
	ft_check_argv(argc, argv); //overflow pas géré
	while (--argc)
	{
		newelt = ft_lstnew_s(ft_atoi(argv[argc]));
		if (newelt)
			ft_lstadd_back_s(&begin, newelt);
		else
		{
			ft_lstclear_s(&begin);
			exit(1);
		}
	}
	ft_index_stack(&begin);
	return (begin);
}
