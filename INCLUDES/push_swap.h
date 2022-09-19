/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 10:31:52 by agardett          #+#    #+#             */
/*   Updated: 2022/09/10 18:28:35 by agardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

typedef struct s_stack
{
	int				data;
	int				index;
	int				pos;
	int				target;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

//parsing
t_stack		*ft_parsing2(char *argv);
t_stack		*ft_parsing(int argc, char **argv);
void		ft_replace(char **str);
void		ft_index_stack(t_stack **begin);

//checker
void		ft_check_nbr(char *str);
void		ft_check_argv(int argc, char **argv);
long int	ft_l_atoi(const char *nptr);
int			ft_check_overflow(char **argv, int pos);
void		ft_lst_check_sort(t_stack **begin);

//lst
int			ft_lstsize_s(t_stack *lst);
t_stack		*ft_lstnew_s(int content);
void		ft_lstadd_front_s(t_stack **lst, t_stack *new);
t_stack		*ft_lstlast_s(t_stack *lst);
void		ft_lstclear_s(t_stack **lst);

//index
int			ft_lstmin(t_stack *lst);
int			ft_lstmax(t_stack *lst);
int			ft_lstnb_inf(t_stack *lst, int val);
int			ft_lstnb_sup(t_stack *lst, int val);
void		ft_pos_index(t_stack *lst, int value, int ind);

// algo
void		ft_algo_3(t_stack **begin);
void		ft_param_sort(t_stack **begin_a, int *size, int *n, int *m);
void		ft_sort_by_median(t_stack **begin_a, t_stack **begin_b);

//algo_fin
void		ft_fin_mv(t_stack **stack_a, t_stack **stack_b, int *ca, int *cb);
void		ft_fin_mv2(t_stack **stack_a, t_stack **stack_b, int *ca, int *cb);
void		ft_algo_fin(t_stack **stack_a, t_stack **stack_b);
void		ft_fin_sort(t_stack **beg);

// mouve
void		ft_s(t_stack **begin, int display);
void		ft_r(t_stack **begin, int display);
void		ft_rr(t_stack **begin, int display);
void		ft_p(t_stack **begin_a, t_stack **begin_b, int display);

//pos
void		ft_pos_elt(t_stack **begin);
int			ft_val_min(t_stack **beg);
void		ft_target_elt(t_stack **beg_a, t_stack **beg_b);
int			ft_cost_fin(int size_a, int size_b, t_stack *elt);

//cos
int			ft_cos_tot(int ca, int cb);
t_stack		*ft_cos_min(t_stack **begin);
int			ft_cost_to_top(int size, int value);
void		ft_cost(t_stack **beg_a, t_stack **beg_b);

#endif
