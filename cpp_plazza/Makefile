##
## Makefile for myftp in /home/girard_r/rendu/PSU_2014_myftp
## 
## Made by Aurélien GIRARDEAU
## Login   <girard_r@epitech.net>
## 
## Started on  Tue Mar 10 19:19:52 2015 Aurélien GIRARDEAU
## Last update Sun Apr 26 17:50:59 2015 Aurélien GIRARDEAU
##

NAME		=		plazza

CC		=		g++

RM		=		rm -f

CORE_INCL	=		core/includes

CLASS_INCL	=		classes/includes

CLASS_SRC	=		classes/sources

CORE_SRC	=		core/sources

CXXFLAGS	=		-Wall -Wextra -Werror -I./$(CLASS_INCL) -I./$(CORE_INCL)

SFML_LDFLAGS	=		-lpthread -lsfml-graphics -lsfml-window -lsfml-system -lX11

SRCS		=		$(CLASS_SRC)/Mutex.cpp \
				$(CLASS_SRC)/CondVar.cpp \
				$(CLASS_SRC)/Correspondance.cpp \
				$(CLASS_SRC)/ScopedLock.cpp \
				$(CLASS_SRC)/Gui.cpp \
				$(CLASS_SRC)/Input.cpp \
				$(CLASS_SRC)/Console.cpp \
				$(CLASS_SRC)/NamedPipe.cpp \
				$(CLASS_SRC)/Pizza.cpp \
				$(CLASS_SRC)/Time.cpp \
				$(CLASS_SRC)/Reception.cpp \
				$(CLASS_SRC)/Kitchen.cpp \
				$(CLASS_SRC)/Cook.cpp \
				$(CLASS_SRC)/SafeStock.cpp \
				$(CORE_SRC)/routine.cpp \
				$(CORE_SRC)/main.cpp

OBJS		=		$(SRCS:.cpp=.o)

all:				$(NAME)

$(NAME):			$(OBJS)
				$(CC) -o $(NAME) $(OBJS) $(SFML_LDFLAGS)

clean:
				$(RM) $(OBJS)

fclean:				clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:				all clean fclean re
