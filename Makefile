# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/18 19:13:31 by tvermeil          #+#    #+#              #
#    Updated: 2017/09/27 21:26:48 by tvermeil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL := /bin/bash -O extglob
MAKEFLAGS += --no-print-directory

NAME = dr_quine

SUB_MAKEFILES_PATH = 

SRC_PATH = .

ROOT = .

CC = gcc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = 
LDFLAGS = 
LDLIBS = 

COLLEEN_DST =	Colleen/Colleen
GRACE_DST =		Grace/Grace
SULLY_DST =		Sully/Sully

ALL_DST = $(COLLEEN_DST) $(GRACE_DST) $(SULLY_DST)

COLLEEN_PRODUCTS = 
GRACE_PRODUCTS = Grace/Grace_kid.c
SULLY_PRODUCTS = Sully/Sully_+([0-9])?(.c)

ALL_PRODUCTS = $(COLLEEN_PRODUCTS) $(GRACE_PRODUCTS) $(SULLY_PRODUCTS)

all: $(ALL_DST)

$(ALL_DST): %: %.c
	@$(CC) $(CFLAGS) $(CPPFLAGS) $< -o $@
	@echo -e ". \033[32m$@\033[0m done"

clean: delete_products

fclean: clean
	@-cd $(ROOT) && rm -fv $(ALL_DST)

re: fclean all

ac: all clean

delete_products:
	@-cd $(ROOT) && rm -fv $(ALL_PRODUCTS)

.PHONY: all clean fclean re ac delete_products
