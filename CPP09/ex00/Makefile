# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/07 03:46:44 by jfremond          #+#    #+#              #
#    Updated: 2023/03/07 04:19:35 by jfremond         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##################
#   EXECUTABLE   #
##################

NAME	=	btc

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