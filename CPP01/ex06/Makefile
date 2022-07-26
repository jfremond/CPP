# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/22 04:58:45 by jfremond          #+#    #+#              #
#    Updated: 2022/07/25 13:43:48 by jfremond         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##################
#   EXECUTABLE   #
##################

NAME 		=	HarlFilter

################
#   COMMANDS   #
################

CXX			=	c++
MKDIR		=	/bin/mkdir -p
RM			=	/bin/rm -rf

#############
#   FLAGS   #
#############

CXXFLAGS	=	-Wall -Wextra -Werror -c
CXXFLAGS	+=	-std=c++98 -g
CXXFLAGS	+=	-MMD -MP

###################
#   DIRECTORIES   #
###################

OBJS_D		=	objs/

###############
#   SOURCES   #
###############

SRCS_L		=	main.cpp	\
				Harl.cpp	\

###############
#   OBJECTS   #
###############

OBJS_L	=		$(SRCS_L:.cpp=.o)
OBJS_L	:=		$(addprefix $(OBJS_D), $(OBJS_L))

####################
#   DEPENDENCIES   #
####################

DEP_L	=		$(OBJS_L:.o=.d)

#############
#   RULES   #
#############

all:			$(NAME)

$(NAME):		$(OBJS_L)
				$(CXX) $(OBJS_L) $(OUTPUT_OPTION)

-include $(DEP_L)

$(OBJS_D)%.o:	%.cpp
				$(MKDIR) $(OBJS_D)
				$(CXX) $(CXXFLAGS) $(OUTPUT_OPTION) $<

clean:
				$(RM) $(OBJS_D)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re 