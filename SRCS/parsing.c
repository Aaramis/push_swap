//#############
//## Header ###
//#############

#include "push_swap.h"

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
			ft_lstclear_s(&begin);
		printf(" %d",newelt->data);
	}
	return (begin);
}
