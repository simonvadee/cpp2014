##
## Makefile for Nibbler in /home/roman/Documents/dev/cpp_nibbler
## 
## Made by grout_r
## Login   <roman@epitech.net>
## 
## Started on  Tue Mar 24 16:05:21 2015 grout_r
## Last update Sun Apr  5 20:26:52 2015 simon vadée
##

CC		=		g++

RM		=		rm -f

INC_DIR		=		./includes/

CXXFLAGS	=		-Wall -Werror -Wextra -I./$(INC_DIR)

LDFLAGS		=		-ldl

ALLEGRO_LDFLAGS	=		-I/usr/include/allegro5 -lallegro -lallegro_image -lallegro_primitives -lallegro_font -lallegro_ttf

SFML_LDFLAGS	=		-lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

NDKPP_LDFLAGS	=		-lncurses

SRC_CLA		=		./sources/classes

SRC_DIR		=		./sources

ALLEGRO_DIR	=		allegro

NDKPP_DIR	=		gui_ndkpp

SFML_DIR	=		gui_sfml

SRC		=		$(SRC_CLA)/Map.cpp \
				$(SRC_CLA)/Snake.cpp \
				$(SRC_CLA)/Item.cpp \
				$(SRC_DIR)/main.cpp

SRC_ALLEGRO	=		$(ALLEGRO_DIR)/Allegro.cpp

SRC_NDKPP	=		$(NDKPP_DIR)/NdkGui.cpp

SRC_SFML	=		$(SFML_DIR)/sfml.cpp

OBJ		=		$(SRC:.cpp=.o)

OBJ_ALLEGRO	=		$(SRC_ALLEGRO:.cpp=.o)

OBJ_NDKPP	=		$(SRC_NDKPP:.cpp=.o)

OBJ_SFML	=		$(SRC_SFML:.cpp=.o)

LIB_ALLEGRO	=		$(ALLEGRO_DIR)/liballegro.so

LIB_NDKPP	=		$(NDKPP_DIR)/libnibndk.so

LIB_SFML	=		$(SFML_DIR)/libsfml.so

NAME		=		nibbler

all		:		$(NAME)

$(NAME)		:		$(OBJ)
				$(CC) $(OBJ) -o $(NAME) -ldl

$(LIB_ALLEGRO)	:
				$(CC) -g -c -fPIC $(SRC_ALLEGRO) $(CXXFLAGS) -o $(OBJ_ALLEGRO)
				$(CC) -g -shared $(ALLEGRO_LDFLAGS) -o $(LIB_ALLEGRO) $(OBJ_ALLEGRO)

$(LIB_NDKPP)	:
				$(CC) -g -c -fPIC $(SRC_NDKPP) $(CXXFLAGS) -o $(OBJ_NDKPP)
				$(CC) -g -shared $(NDKPP_LDFLAGS) -o $(LIB_NDKPP) $(OBJ_NDKPP)

$(LIB_SFML)	:
				$(CC) -g -c -fPIC $(SRC_SFML) $(CXXFLAGS) -o $(OBJ_SFML)
				$(CC) -g -shared $(SFML_LDFLAGS) -o $(LIB_SFML) $(OBJ_SFML)

clean		:
				$(RM) $(OBJ) $(OBJ_ALLEGRO) $(OBJ_NDKPP) $(OBJ_SFML)

fclean		:		clean
				$(RM) $(NAME) $(LIB_ALLEGRO) $(LIB_NDKPP) $(LIB_SFML)

re		:		fclean all

.PHONY		:		re all clean fclean
