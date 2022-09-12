# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/12 14:31:29 by jfremond          #+#    #+#              #
#    Updated: 2022/09/13 00:47:59 by jfremond         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##################
#   EXECUTABLE   #
##################

NAME		=		interface

################
#   COMMANDS   #
################

CXX			=		c++
RM			=		/usr/bin/rm -rf
MKDIR		=		/usr/bin/mkdir -p

#############
#   FLAGS   #
#############

CXXFLAGS	=		-Wall -Wextra -Werror -g
CXXFLAGS	+=		-std=c++98
CXXFLAGS	+=		-MMD -MP

###################
#   DIRECTORIES   #
###################

OBJS_D		=		objs/

###############
#   SOURCES   #
###############

SRCS		=		main.cpp			\
					AMateria.cpp		\
					Ice.cpp				\
					Cure.cpp			\
					Character.cpp		\
					MateriaSource.cpp	\

###############
#   OBJECTS   #
###############

OBJS	=		$(SRCS:.cpp=.o)
OBJS	:=		$(addprefix $(OBJS_D), $(OBJS))

####################
#   DEPENDENCIES   #
####################

DEP		=		$(OBJS:.o=.d)

#############
#   RULES   #
#############

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CXX) $(CXXFLAGS) $(OBJS) $(OUTPUT_OPTION)

-include 		$(DEP)

$(OBJS_D)%.o:	%.cpp
				$(MKDIR) $(OBJS_D)
				$(CXX) -c $(CXXFLAGS) $(OUTPUT_OPTION) $<

clean:
				$(RM) $(OBJS_D)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
