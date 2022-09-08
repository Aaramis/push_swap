//#############
//## Header ###
//#############

#include "push_swap.h"

int	ft_lstmax(t_stack *lst)
{
	int	max;

	max = lst->data;
	while (lst)
	{
		if (max < lst->data)
			max = lst->data;
		lst = lst->next;
	}
	return (max);
}

int	ft_lstmin(t_stack *lst)
{
	int	min;

	min = lst->data;
	while (lst)
	{
		if (min > lst->data)
			min = lst->data;
		lst = lst->next;
	}
	return (min);
}

int	ft_lstnb_sup(t_stack *lst, int val)
{
	int	sup;

	sup = ft_lstmax(lst);
	while (lst)
	{
		if (lst->data > val && lst->data < sup)
			sup = lst->data;
		lst = lst->next;
	}
	return (sup);
}

int	ft_lstnb_inf(t_stack *lst, int val)
{
	int	inf;

	inf = ft_lstmin(lst);
	while (lst)
	{
		if (lst->data < val && lst->data > inf)
			inf = lst->data;
		lst = lst->next;
	}
	return (inf);
}

void	ft_pos_index(t_stack *lst, int value, int ind)
{
	while (lst->data != value)
		lst = lst->next;
	lst->index = ind;
}
