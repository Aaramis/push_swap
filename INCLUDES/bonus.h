/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 10:31:52 by agardett          #+#    #+#             */
/*   Updated: 2022/09/10 18:28:35 by agardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include "libft.h"
# include "ft_printf.h"
# include "push_swap.h"

//	bonus_utils
int		ft_nv_b3(t_stack **stack_a, t_stack **stack_b, char *str);
int		ft_nv_b2(t_stack **stack_a, t_stack **stack_b, char *str);
int		ft_nv_b1(t_stack **stack_a, t_stack **stack_b, char *str);
void	ft_checker_str(t_stack **stack_a, t_stack **stack_b, char *str);
void	ft_lst_check_b(t_stack **begin);

#endif
