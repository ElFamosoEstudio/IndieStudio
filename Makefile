##
## Makefile for Indie Studio in /home/silvy_n/projects/cpp_indie_studio
##
## Made by
## Login   <silvy_n@epitech.net>
##
## Started on  Mon May  8 19:36:54 2017
## Last update Tue Jun  6 15:11:09 2017 Adam Akkari
##

NAME		=		bomber

IRRLICHT_DIR	=		irrlicht-1.8.4

CC		=		g++

RM		=		rm -f

CPPFLAGS	=		-I./irrlicht-1.8.4/include -I./src/component -I./src/gameobject -I./src/ -I./src/scenes

CXXFLAGS	=		-Wall -Wextra -std=c++11
# CXXFLAGS	+=		-std=c++17

LDFLAGS		=		 -L./irrlicht-1.8.4/linux -lIrrlicht  -lGL -lXxf86vm -lXext -lX11 -lXcursor

SRCS		=		src/main.cpp \
				src/component/Transform.cpp \
				src/component/Renderer.cpp \
				src/component/Renderer3D.cpp \
				src/component/RendererCamera.cpp \
				src/component/BoxCollider.cpp \
				src/gameobject/GameObject.cpp \
				src/gameobject/Camera.cpp \
				src/gameobject/RotatingRock.cpp \
				src/gameobject/Character.cpp \
				src/gameobject/Wall.cpp \
				src/Scene.cpp \
				src/RessourcesLocator.cpp \
				src/InputManager.cpp \
				src/scenes/test.cpp

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
