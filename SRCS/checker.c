//############
//## Header ##
//############

#include "push_swap.h"

void	ft_check_nbr(char *str)
{
	if (*str == 45)
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
		{
			write(2,"Error\n",6);
			exit(1);
		}
		str++;
	}
}

void	ft_check_argv(int argc, char **argv)
{
	int	pos;
	int	pos2;

	pos = argc;
	while (--pos)
	{
		pos2 = pos;
		ft_check_nbr(argv[pos]);
		while (--pos2)
		{
			if (ft_atoi(argv[pos]) == ft_atoi(argv[pos2]))
			{
				write(2,"Error\n",6);
				exit(1);
			}
		}
	}
}
