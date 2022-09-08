//############
//## Header ##
//############

#include "push_swap.h"

int	ft_check_nbr(char *str)
{
	if (*str == 45)
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	ft_check_db(t_stack **begin, int content)
{
//	t_stack	*lst;

	while ((*begin)->data)
	{
		if ((*begin)->data == content)
			return (0);
	/*	lst = *begin->next;
		while (lst->data)
		{
			if (begin->data == lst->data)
				return (0);
			lst = lst->next;
		}*/
		*begin = (*begin)->next;
	}
	return (1);
}
