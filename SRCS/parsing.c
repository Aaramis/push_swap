//#############
//## Header ###
//#############

#include "push_swap.h"

t_stack  	*ft_parsing(int argc,char **argv)
{
	t_stack	*begin_a;
	t_stack	*newelt_a;
	int	size;

	begin_a = NULL;
	newelt_a = NULL;
	size = argc - 1;  //possibilité suppression size en desincrementant directement argc
	ft_check_argv(argc, argv);
	while (size)
	{
/*		
		if (ft_check_nbr(argv[size]))
		{
			newelt_a = ft_lstnew_s(ft_atoi(argv[size]));
			if (newelt_a && ft_check_db(&begin_a, ft_atoi(argv[size])))
			{
				ft_lstadd_back_s(&begin_a, newelt_a);
			}
				ft_printf(" %d -", newelt_a->data);
		}
		else*
		{
			ft_lstclear(begin_a, del) del to do
			return (NULL);
		}
		*/
		ft_printf(" %d", ft_atoi(argv[size]));
		size--;
	}
//	if(ft_check_db(begin_a))
//			ft_lstclear(begin_a, del) del to do
	(void)argv;
	(void)newelt_a;
	return (begin_a);
}
