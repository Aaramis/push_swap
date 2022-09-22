# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agardett <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/03 17:38:06 by agardett          #+#    #+#              #
#    Updated: 2022/09/10 10:45:02 by agardett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###############
#  VARIABLES  #
###############

# 	FILES
SRC_F		= ./SRCS/
LIBFT_F		= ./libft
FILES		= parsing checker lst index algo algo_fin mouve pos cos
BONUS_F		= bonus_utils

SRCS		= $(addsuffix .c,$(FILES))
OBJS		= $(addprefix $(SRC_F),$(addsuffix .o,$(FILES)))
SRCS_B		= $(addsuffix .c,$(BONUS_F))
OBJS_B		= $(addprefix $(SRC_F), $(addsuffix .o,$(BONUS_F)))

#	INCLUDES
INC		= ./INCLUDES
INC_L		= $(LIBFT_F)/INCS
PUSH_H		= push_swap.h
BONUS_H		= bonus.h
NAME_LIB	= libft.a
LIB_F		= $(LIBFT_F)/$(NAME_LIB)

#	COMPILER
CC		= cc -g
SANITIZE	= -fsanitize=address
RM		= rm -f
LINKER		= ar rcs 
WFLAGS		= -Wall -Werror -Wextra
IFLAGS		= -I $(INC) -I $(INC_L)
IFLAGS2		= -I .$(INC) -I .$(INC_L)
OFLAGS		= -O2 -funroll-loops
GFLAGS		= $(WFLAGS) $(IFLAGS) $(OFLAGS)
LIB		= $(LIBFT_F)/$(NAME_LIB)

#	OUTPUT
NAME_EX		= push_swap
NAME_B		= checker

############
#  COLORS  #
############

BLACK		= "\033[1;30m"
RED		= "\033[1;31m"
GREEN		= "\033[1;32m"
CYAN		= "\033[1;36m"
PURPLE		= "\033[1;35m"
WHITE		= "\033[1;37m"
EOC		= "\033[0;0m"

##############
#  COMMANDS  #
##############

all:		$(NAME_EX)

$(NAME_EX):
		@echo $(CYAN) "\n"					\
		"#######################################\n"		\
		"   Compilation des fichiers en cours   \n"	 	\
		"#######################################\n"		\
		$(EOC)
		@cd $(LIBFT_F) && $(MAKE) all
		@cd $(SRC_F) && $(CC) $(WFLAGS) $(IFLAGS2) -c $(SRCS)
		@$(CC) $(GFLAGS) $(SRC_F)main.c $(OBJS) $(LIB_F) -o $(NAME_EX)
		@echo $(CYAN) "\n"					\
		"------- Succeeded : fully compiled -------\n"		\
		$(EOC)

clean:
		@$(RM) $(OBJS) $(OBJS_B)
		@cd $(LIBFT_F) && $(MAKE) clean


fclean:		clean
		@echo $(CYAN) "\n"					\
		"#######################################\n"		\
		"Nettoyage Complet des fichiers en cours\n"	 	\
		"#######################################\n"		\
		$(EOC)
		@cd $(LIBFT_F) && $(MAKE) fclean
		@$(RM) $(NAME_EX) $(NAME_B)
		@echo $(CYAN) "\n"					\
		"------- Succeeded : fully cleaned -------\n"		\
		$(EOC)

re: 		fclean
		@$(MAKE) all
		@$(MAKE) bonus

bonus:		$(NAME_EX) $(NAME_B)


$(NAME_B):
		@echo $(CYAN) "\n"					\
		"####################################\n"		\
		"   Compilation des fichiers bonus   \n"	 	\
		"####################################\n"		\
		$(EOC)
		@cd $(SRC_F) && $(CC) $(WFLAGS) $(IFLAGS2) -c $(SRCS_B)
		@$(CC) $(GFLAGS) $(SRC_F)bonus.c $(OBJS_B) $(OBJS) $(LIB_F) -o $(NAME_B)
		@echo $(CYAN) "\n"					\
		"---- Succeeded : fully compiled ----\n"		\
		$(EOC)

.PHONY: 	all clean fclean re bonus
.SILENT:	all
