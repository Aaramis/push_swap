/* ############# */
/* ## Header  ## */
/* ############# */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"


typedef struct	s_stack
{
	int				data;
	struct s_stack	*next;
}	t_stack;

int	main(int argc, char **argv);
t_stack	*ft_parsing(int argc,char **argv);
t_stack *ft_lstnew_s(int content);
void	ft_check_nbr(char *str);
void	ft_check_argv(int argc, char **argv);
void	ft_lstadd_back_s(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast_s(t_stack *lst);
void	ft_lstclear_s(t_stack **lst);

#endif
