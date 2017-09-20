# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymukmar <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/14 21:01:42 by ymukmar           #+#    #+#              #
#    Updated: 2017/09/14 23:07:50 by ymukmar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = g++
FLAGS = -Wno-deprecated -Wall -Wextra -Werror
NAME = Nibbler
INC = -I ./includes
FRAME = -framework OpenGL -framework GLUT

SRC_FOLDER = ./sources
SRC = $(wildcard $(SRC_FOLDER)/*.cpp)

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(INC) $(FLAGS) $(FRAME) -o $@ $^

lib:
	g++ -shared -o ./libs/lib_check.so -I ./libs ./libs/library.cpp -framework OpenGL -framework GLUT

clean:
	@rm $(NAME)

.PHONY: all
