//
//	HEADER
//


#include "push_swap.h"


t_stack	*ft_lstnew_s(int content)
{
	t_stack	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->data = content;
	list->next = NULL;
	return (list);
}

void	ft_lstadd_back_s(t_stack **lst, t_stack *new)
{
	t_stack	*lst_last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	lst_last = ft_lstlast_s(*lst);
	lst_last->next = new;
}

t_stack	*ft_lstlast_s(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstclear_s(t_stack **lst)
{
	t_stack	*elt;

	if (!lst || !(*lst))
		return ;
	while (*lst)
	{
		elt = (*lst)->next;
		free(*lst);
		*lst = elt;
	}
	*lst = NULL;
}


