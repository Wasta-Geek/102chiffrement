##
## Makefile for  in /home/ducate_c/rendu/102chiffrement
## 
## Made by Corentin Ducatez
## Login   <ducate_c@epitech.net>
## 
## Started on  Mon Nov 24 16:34:27 2014 Corentin Ducatez
## Last update Wed Apr 29 20:06:52 2015 Corentin Ducatez
##

CC	= gcc

RM	= rm -f

NAME	= 102chiffrement

SRCS	= la_crypto_c_cool.c	\
	  my_putnbr_base.c	\
	  check.c		\

OBJS	= $(SRCS:.c=.o)


all:	 $(NAME)

$(NAME): $(OBJS)
	 $(CC) -o $(NAME) $(OBJS) -Wall -Wextra -lm

clean:
	 $(RM) $(OBJS)

fclean:	 clean
	 $(RM) $(NAME)

re:	 fclean all
