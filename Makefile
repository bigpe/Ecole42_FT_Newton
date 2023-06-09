# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrorscha <lrorscha@student.21-school.ru>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/07 14:21:44 by lrorscha          #+#    #+#              #
#    Updated: 2023/03/21 11:33:51 by lrorscha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED		= \033[031m
GREEN	= \033[032m
CYAN	= \033[036m
RESET	= \033[0m

NAME = ft_newton

CLASSES=	\
All			\
Collider	\
Display		\
Event		\
Game		\
Line		\
Matrix		\
Object		\
OpenGL		\
Time		\
Utils		\

CLASSES_HEADERS= $(addsuffix .hpp, $(CLASSES))
CLASSES_SRCS= $(addsuffix .cpp, $(CLASSES))

HEADERS = $(CLASSES_HEADERS) \
General.hpp	\

SRC_FILES = $(CLASSES_SRCS)	\
vec3.cpp	\
main.cpp	\


CC = g++

ifeq ($(uname), Darwin)
	CC = clang++
endif


FL_OPTI = -O3 -flto
FLAGS = -Wall -Wextra -Wconversion -Wunused -std=c++11 $(FL_OPTI) \
-D 'GL_SILENCE_DEPRECATION'


CFLAGS = -c $(FLAGS)

FRAMEWORKS = -lSDL2 -LLibrary/lib -ldl -lpthread -framework OpenGL


CINCLUDE = -I include -I Library/include/SDL2

SRC_DIR = src/
SRC := $(addprefix $(SRC_DIR), $(SRC_FILES))

INCLUDE_DIR = include/
INCLUDE := $(addprefix $(INCLUDE_DIR), $(HEADERS))

OBJ_FILES = $(patsubst %.cpp, %.o, $(SRC_FILES))
OBJ_DIR = obj/
OBJ := $(addprefix $(OBJ_DIR), $(OBJ_FILES))

all: $(NAME)
	@echo "$(CYAN)$(NAME) ready sir !$(RESET)"

$(NAME): $(OBJ_DIR) $(OBJ)
	@echo "$(GREEN)objects done sir !$(RESET)"
	@$(CC)  $(OBJ) $(FRAMEWORKS) -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled sir !$(RESET)"

$(OBJ_DIR)%.o : $(SRC_DIR)%.cpp $(INCLUDE)
	@$(CC) $(CINCLUDE) $(CFLAGS) -o $@ $<
	@echo -n '.'

$(OBJ_DIR) :
	@mkdir $(OBJ_DIR)
	@echo "$(GREEN)Object directory created sir !$(RESET)"

clean:
	@rm -f $(OBJ)
	@echo "$(RED)Objects deleted sir !$(RESET)"
	@rm -rf $(OBJ_DIR)
	@#echo "$(RED)Object directory deleted sir !$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)$(NAME) deleted sir !$(RESET)"

re: fclean all
