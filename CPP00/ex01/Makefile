# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/19 15:27:40 by jfremond          #+#    #+#              #
#    Updated: 2022/05/20 10:30:28 by jfremond         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##################
#   EXECUTABLE   #
##################

NAME	=	MyAwesomePhoneBook

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

CFLAGS	=	-Wall -Wextra -Werror -c -g
CFLAGS	+=	-std=c++98 
CFLAGS	+=	-MMD -MP

###################
#   DIRECTORIES   #
###################

OBJS_D	=	objs/

###############
#   SOURCES   #
###############

SRCS_L	=	PhoneBook.cpp	\

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

-include	$(DEP)

$(OBJS_D)%.o:	$(SRCS_L)%.cpp
				$(MKDIR) $(@D)
				$(CC) $(CFLAGS) $(OUTPUT_OPTION) $<

clean:
				$(RM) $(OBJS_D)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
