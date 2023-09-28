# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrichard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/29 16:05:39 by lrichard          #+#    #+#              #
#    Updated: 2021/10/08 22:50:28 by lrichard         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCSDIR			= sources

SRCS			= main.c make_list.c push_swap.c actions.c

OBJS			= $(addprefix $(SRCSDIR)/, $(SRCS:.c=.o))

HDIR			= includes

HEADERS			= $(HDIR)/pushswap.h

$(SRCSDIR)/%.o:	$(SRCSDIR)/%.c $(HEADERS)
				$(CC) $(CFLAGS) -I $(HDIR) -I $(LIBFTDIR) -c $< -o $@

LIBFTDIR		= LIBFT

LIBFTA			= $(LIBFTDIR)/libft.a

NAME			= push_swap

CFLAGS			= -Wall -Wextra -Werror -O3 -march=native

CC				= gcc

RM				= rm -f

all:			mklibfta $(NAME)

mklibfta:
				$(MAKE) -C ./LIBFT

$(NAME):		$(OBJS) $(LIBFTA) $(HEADERS)
				$(CC) $(CFLAGS) -I $(HDIR) -I $(LIBFTDIR) $(OBJS) $(LIBFTA) -o $@

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			mklibfta all clean fclean re
