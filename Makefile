# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbourgeo <hbourgeo@student.19.be>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 07:55:41 by hbourgeo          #+#    #+#              #
#    Updated: 2022/03/25 09:54:33 by hbourgeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a
DEPS = ft_printf.h

SRC =	ft_printf.c	\
		ft_printf_c.c\
		ft_printf_d.c\
		ft_printf_i.c\
		ft_printf_p.c\
		ft_printf_per.c\
		ft_printf_s.c\
		ft_printf_u.c\
		ft_printf_x_low.c\
		ft_printf_x_up.c\
		

OBJ = $(SRC:.c=.o)

%.o : %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)
	
$(NAME) : $(OBJ)
	make -C libft
	cp libft/libft.a $(NAME)
	ar rs $(NAME) $(OBJ)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)
	make fclean -C libft

re : fclean all

.PHONY : clean fclean all re