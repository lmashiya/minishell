# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmashiya <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/07 16:06:12 by lmashiya          #+#    #+#              #
#    Updated: 2017/09/07 16:06:20 by lmashiya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = minishell

SOURCES = srcs/exe.c srcs/ft_path_finder.c srcs/get_line.c srcs/l_shell.c \
          srcs/main.c srcs/env_module.c srcs/ft_set_env.c srcs/ft_cd.c \
		  srcs/ft_echo.c srcs/ft_putecho.c srcs/ft_do_e.c srcs/ft_unsetenv.c \
		 srcs/ft_echo_quo.c srcs/ft_inhibitors.c srcs/ft_odds.c 

HEADER = -I include

LFLAGS = -L./libft/ -lft

FLAGS = -o minishell -Wall -Werror -Wextra

all:
	@make -C libft/
	@gcc $(FLAGS) $(SOURCES) $(HEADER) $(LFLAGS)

clean:
	@rm $(NAME)
	@make -C libft/ clean

fclean: clean
	@rm -rf $(NAME)
	@rm -rf libft/libft.a

re: fclean all
