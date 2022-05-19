# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/19 15:27:40 by jfremond          #+#    #+#              #
#    Updated: 2022/05/19 15:58:36 by jfremond         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##################
#   EXECUTABLE   #
##################

NAME	=	megaphone

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

###################
#   DIRECTORIES   #
###################

OBJS_D	=	objs/

###############
#   SOURCES   #
###############

SRCS_L	=	megaphone.cpp	\

###############
#   OBJECTS   #
###############

OBJS_L	=	$(SRCS_L:.cpp=.o)
OBJS_L	:=	$(addprefix $(OBJS_D), $(OBJS_L))

OBJS	=	$(OBJS_L)


#############
#   RULES   #
#############

all:		$(NAME)

$(NAME):	$(OBJS)
			$(LINK) $(OBJS) $(OUTPUT_OPTION)
# Pas de cflags quand il y a link 

$(OBJS_D)%.o:	$(SRCS_L)%.cpp
				$(MKDIR) $(@D)
				$(CC) $(CFLAGS) $(OUTPUT_OPTION) $<

clean:
				$(RM) $(OBJS_D)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
