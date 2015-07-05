##
## Makefile for Makefile in /home/girard_r/rendu/cpp_abstractvm
## 
## Made by Aurélien GIRARDEAU
## Login   <girard_r@epitech.net>
## 
## Started on  Mon Feb 23 14:26:41 2015 Aurélien GIRARDEAU
## Last update Sun Mar  1 20:13:50 2015 Aurélien GIRARDEAU
##

NAME		=		avm

CC		=		g++

RM		=		rm -f

CLASS_DIR	=		classes/sources

CLASS_INCL	=		classes/includes/

SOURCE_DIR	=		sources

CXXFLAGS	=		-Wall -Wextra -Werror -I./$(CLASS_INCL)

SRCS		=		$(CLASS_DIR)/Operand.cpp \
				$(CLASS_DIR)/OperandFactory.cpp \
				$(CLASS_DIR)/pileMachine.cpp \
				$(SOURCE_DIR)/main.cpp

OBJS		=		$(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		clean all

.PHONY:		all clean re
