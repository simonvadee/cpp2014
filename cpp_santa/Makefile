# names
NAME		= SantaClaus

# cmds
CC		= g++
RM		= rm -f

# directories
SRCSDIR		= Sources

CLASSESDIR	= $(SRCSDIR)/Classes
MAINDIR		= $(SRCSDIR)/Main
INCDIR		= Includes

MAININCDIRS	= $(MAINDIR)/$(INCDIR)
CLASSESINCDIR	= $(CLASSESDIR)/$(INCDIR)

# sources
SRCS		= $(MAINDIR)/$(SRCSDIR)/main.cpp \
		  $(MAINDIR)/$(SRCSDIR)/Create.cpp \
		  $(MAINDIR)/$(SRCSDIR)/MyUnitTests.cpp \
		  $(CLASSESDIR)/$(SRCSDIR)/Object.cpp \
		  $(CLASSESDIR)/$(SRCSDIR)/Box.cpp \
		  $(CLASSESDIR)/$(SRCSDIR)/TableRand.cpp \
		  $(CLASSESDIR)/$(SRCSDIR)/TablePePeNoel.cpp \
		  $(CLASSESDIR)/$(SRCSDIR)/MagicTypeSource.cpp \
		  $(CLASSESDIR)/$(SRCSDIR)/Teddy.cpp \
		  $(CLASSESDIR)/$(SRCSDIR)/LittlePony.cpp \
		  $(CLASSESDIR)/$(SRCSDIR)/Playmobil.cpp \
		  $(CLASSESDIR)/$(SRCSDIR)/Barbie.cpp \
		  $(CLASSESDIR)/$(SRCSDIR)/GiftPaper.cpp \
		  $(CLASSESDIR)/$(SRCSDIR)/ElfOfPepeNoel.cpp \
		  $(CLASSESDIR)/$(SRCSDIR)/IElf.cpp \
		  $(CLASSESDIR)/$(SRCSDIR)/ConveyorBeltRand.cpp \
		  $(CLASSESDIR)/$(SRCSDIR)/ConveyorBeltPePeNoel.cpp \
		  $(CLASSESDIR)/$(SRCSDIR)/Wrap.cpp \
		  $(CLASSESDIR)/$(SRCSDIR)/Toy.cpp \
		  $(CLASSESDIR)/$(SRCSDIR)/ITable.cpp \
		  $(CLASSESDIR)/$(SRCSDIR)/IConveyorBelt.cpp \

# object files
OBJS		= $(SRCS:.cpp=.o)

# flags
CXXFLAGS	+= -I./$(MAININCDIRS) -I./$(CLASSESINCDIR)
CXXFLAGS	+= -W -Wall -Wextra -Werror -g

all:		$(NAME)

$(NAME): 	$(OBJS)
		$(CC) -o $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean: 	clean
		$(RM) $(NAME)

re: 		fclean all

.PHONY: 	all clean fclean re
