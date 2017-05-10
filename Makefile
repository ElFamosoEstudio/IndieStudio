##
## Makefile for Indie Studio in /home/silvy_n/projects/cpp_indie_studio
##
## Made by
## Login   <silvy_n@epitech.net>
##
## Started on  Mon May  8 19:36:54 2017
## Last update Mon May  8 19:37:49 2017 
##

NAME		=		bomber

IRRLICHT_DIR	=		irrlicht-1.8.4

CC		=		g++

RM		=		rm -f

CPPFLAGS	=		-I./irrlicht-1.8.4/include

CXXFLAGS	=		-Wall -Wextra
# CXXFLAGS	+=		-std=c++17

LDFLAGS		=		 -L./irrlicht-1.8.4/linux -lIrrlicht  -lGL -lXxf86vm -lXext -lX11 -lXcursor

SRCS		=		main.cpp

OBJS		=		$(SRCS:.cpp=.o)


all:				$(NAME)

$(NAME):			$(OBJS)
				$(CC) -o $(NAME) $(OBJS) $(CXXFLAGS) $(LDFLAGS) $(CPPFLAGS)

clean:
				$(RM) $(OBJS)

fclean:				clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:				all clean fclean re
