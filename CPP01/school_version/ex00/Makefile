# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/23 21:07:38 by jfremond          #+#    #+#              #
#    Updated: 2022/07/23 22:10:07 by jfremond         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##################
#   EXECUTABLE   #
##################

NAME	=	BraiiiiiiinnnzzzZ

################
#   COMMANDS   #
################

CXX		=	c++
MKDIR	=	/bin/mkdir -p
RM		=	/bin/rm -rf

#############
#   FLAGS   #
#############

CXXFLAGS	=	-Wall -Wextra -Werror -c
CXXFLAGS	+=	-std=c++98
CXXFLAGS	+=	-MMD -MP

###################
#   DIRECTORIES   #
###################

OBJS_D	=	objs/

###############
#   SOURCES   #
###############

SRCS_L	=	main.cpp		\
			newZombie.cpp	\
			randomChump.cpp	\
			Zombie.cpp		\

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
			$(CXX) $(OBJS) $(OUTPUT_OPTION)

-include	$(DEP)

$(OBJS_D)%.o:	%.cpp
				$(MKDIR) $(@D)
				$(CC) $(CXXFLAGS) $(OUTPUT_OPTION) $<

clean:
				$(RM) $(OBJS_D)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
