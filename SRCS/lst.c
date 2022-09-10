/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 10:36:35 by agardett          #+#    #+#             */
/*   Updated: 2022/09/10 10:36:54 by agardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize_s(t_stack *lst)
{
	size_t	len;

	if (!lst)
		return (0);
	len = 1;
	while (lst->next)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}

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

void	ft_lstadd_front_s(t_stack **lst, t_stack *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	(*lst) = new;
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
