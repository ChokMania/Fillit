# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: judumay <judumay@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/06 15:32:43 by judumay           #+#    #+#              #
#    Updated: 2018/12/06 15:35:08 by judumay          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = bash

# Executable name, can be change
NAME = fillit

# Sources names
SRCS_NAME = ft_verif.c \
			do_lst.c \
			ft_utilies.c \
			do_it.c \
			ft_coupe_decale.c \
			ft_backtrack.c \
			main.c
INCS_NAMES = ft_header.h

# Sources, objects and includes path
SRCS_PATH = ./srcs/
OBJS_PATH = ./objs/
INCS_PATH = ./includes/

# Sources and objects
SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJS = $(patsubst $(SRCS_PATH)%.c, $(OBJS_PATH)%.o, $(SRCS))
INC = $(addprefix $(INCS_PATH), $(INCS_NAMES))

# Compilation
CC = gcc
CPPFLAGS = -I $(INCS_PATH)
CFLAGS = -Wall -Wextra -Werror $(CPPFLAGS)
LDFLAGS = ./libft/
LDLIBS = libft.a

# Text format
_DEF = $'\033[0m
_GRAS = $'\033[1m
_SOUL = $'\033[4m
_CLIG = $'\033[5m
_SURL = $'\033[7m

# Colors
_BLACK = $'\033[30m
_RED = $'\033[31m
_GREEN = $'\033[32m
_YELLOW = $'\033[33m
_BLUE = $'\033[34m
_PURPLE = $'\033[35m
_CYAN = $'\033[36m
_GREY = $'\033[37m

# Background
_IBLACK = $'\033[40m
_IRED = $'\033[41m
_IGREEN = $'\033[42m
_IYELLOW = $'\033[43m
_IBLUE = $'\033[44m
_IPURPLE = $'\033[45m
_ICYAN = $'\033[46m
_IGREY = $'\033[47m

verif = 0

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $@
	@echo -en "$(_GREEN)\t [OK]\n\n$(_DEF)"

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c $(INC)
	@if [[ $(verif) -eq 0 ]]; then printf "\n$(_GRAS)$(_CYAN)|==========================>  $(NAME)   <==========================|$(_DEF)\n";\
	else printf "\e[1A"; fi
	$(eval FNCT = $(words $(SRCS)))
	$(eval verif = $(shell echo $(verif) + 1 | bc ))
	$(eval PCR = $(shell echo "$(verif) / $(FNCT) * 100" | bc -l))
	@printf " \n$(_GREEN)[%3d%%]\t$(_DEF)%-24s $(_PURPLE)👉$(_GREEN)\t%-24s$(_DEF)" $(shell echo $(PCR) | sed -E "s:\.[0-9]{20}::") $< $@
	@mkdir -p objs
	@printf "$(_DEF)"
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	@echo
	@rm -rf $(OBJS_PATH) 2> /dev/null || true
	@echo -e "$(_YELLOW)Remove :\t$(_RED)" $(OBJS_PATH)
	@echo

fclean: clean
	@rm -f $(NAME)
	@echo -e "$(_YELLOW)Remove :\t$(_RED)" $(NAME)
	@echo



re: fclean all

norme:
	@norminette $(SRCS_PATH)
	@norminette $(INCS_PATH)

.PHONY: all lib_clean lib_fclean clean fclean re  norme