# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/13 02:51:49 by jfremond          #+#    #+#              #
#    Updated: 2022/09/13 02:51:50 by jfremond         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##################
#   EXECUTABLE   #
##################

NAME	=	Polymorphism

################
#   COMMANDS   #
################

CXX		=	c++
MKDIR	=	/bin/mkdir -p
RM		=	/bin/rm -rf

#############
#   FLAGS   #
#############

CXXFLAGS	=	-c -Wall -Wextra -Werror
CXXFLAGS	+=	-std=c++98
CXXFLAGS	+=	-MMD -MP

###################
#   DIRECTORIES   #
###################

OBJS_D	=	objs/

###############
#   SOURCES   #
###############

SRCS	=	main.cpp		\
			Animal.cpp		\
			Dog.cpp			\
			Cat.cpp			\
			WrongAnimal.cpp	\
			WrongCat.cpp	\

###############
#   OBJECTS   #
###############

OBJS	=	$(SRCS:.cpp=.o)
OBJS	:=	$(addprefix $(OBJS_D), $(OBJS))

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
				$(MKDIR) $(OBJS_D)
				$(CXX) $(CXXFLAGS) $(OUTPUT_OPTION) $<

clean:
				$(RM) $(OBJS_D)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
