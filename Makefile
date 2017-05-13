##
## Makefile for Indie Studio in /home/silvy_n/projects/cpp_indie_studio
##
## Made by
## Login   <silvy_n@epitech.net>
##
## Started on  Mon May  8 19:36:54 2017
## Last update Sat May 13 21:26:57 2017 Adam Akkari
##

NAME		=		bomber

IRRLICHT_DIR	=		irrlicht-1.8.4

CC		=		g++

RM		=		rm -f

CPPFLAGS	=		-I./irrlicht-1.8.4/include -I./src/component -I./src/gameobject

CXXFLAGS	=		-Wall -Wextra -std=c++11
# CXXFLAGS	+=		-std=c++17

LDFLAGS		=		 -L./irrlicht-1.8.4/linux -lIrrlicht  -lGL -lXxf86vm -lXext -lX11 -lXcursor

SRCS		=		src/main.cpp \
				src/component/Transform.cpp \
				src/gameobject/GameObject.cpp

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
