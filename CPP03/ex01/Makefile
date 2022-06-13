# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/13 12:23:48 by jfremond          #+#    #+#              #
#    Updated: 2022/06/13 16:36:20 by jfremond         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##################
#   EXECUTABLE   #
##################

NAME	=	ScavTrap

################
#   COMMANDS   #
################

CC		=	c++
LINK	=	c++
MKDIR	=	/bin/mkdir -p
RM		=	/bin/rm -rf

#############
#   FLAGS   #
#############

CFLAGS	=	-Wall -Wextra -Werror -c
CFLAGS	+=	-std=c++98
CFLAGS	+=	-MMD -MP

###################
#   DIRECTORIES   #
###################

OBJS_D	=	objs/

###############
#   SOURCES   #
###############

SRCS_L	=	ClapTrap.cpp	\
			main.cpp		\

###############
#   OBJECTS   #
###############

OBJS_L	=	$(SRCS_L:.cpp=.o)
OBJS_L	:=	$(addprefix $(OBJS_D), $(OBJS_L))

OBJS	=	$(OBJS_L)

####################
#   DEPENDENCIES   #
####################

DEP		=	$(OBJS:.o=.d)

#############
#   RULES   #
#############

all:		$(NAME)

$(NAME):	$(OBJS)
			$(LINK) $(OBJS) $(OUTPUT_OPTION)
# Pas de cflags quand il y a link 

-include	$(DEP)

$(OBJS_D)%.o:	%.cpp
				$(MKDIR) $(@D)
				$(CC) $(CFLAGS) $(OUTPUT_OPTION) $<

clean:
				$(RM) $(OBJS_D)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
