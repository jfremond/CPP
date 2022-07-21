# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/18 15:51:07 by jfremond          #+#    #+#              #
#    Updated: 2022/07/21 16:16:22 by jfremond         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##################
#   EXECUTABLE   #
##################

NAME 		=	TheJobOfYourDreams

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

SRCS_F		=	Account.cpp	\
				tests.cpp	\

###############
#   OBJECTS   #
###############

OBJS_F	=		$(SRCS_F:.cpp=.o)
OBJS_F	:=		$(addprefix $(OBJS_D), $(OBJS_F))

####################
#   DEPENDENCIES   #
####################

DEP_F	=		$(OBJS_F:.o=.d)

#############
#   RULES   #
#############

all:			$(NAME)

$(NAME):		$(OBJS_F)
				$(CXX) $(OBJS_F) $(OUTPUT_OPTION)

-include $(DEP_F)

$(OBJS_D)%.o:	%.cpp
				$(MKDIR) $(OBJS_D)
				$(CXX) $(CXXFLAGS) $(OUTPUT_OPTION) $<

clean:
				$(RM) $(OBJS_D)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re 