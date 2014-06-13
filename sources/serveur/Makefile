# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/05/18 04:15:01 by gdefrait          #+#    #+#              #
#    Updated: 2014/05/18 04:15:02 by gdefrait         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ftp

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I includes/ -I ../

OBJ1 =		server_/check_fd.o \
			server_/clean_fd.o \
			server_/client_read.o \
			server_/client_write.o \
			server_/do_select.o \
			server_/get_opt.o \
			server_/init_env.o \
			server_/init_fd.o \
			server_/main.o \
			server_/main_loop.o \
			server_/srv_accept.o \
			server_/srv_create.o \
			server_/x.o \
			server_/command.o \
			server_/command_.o \
			server_/functions.o \
			common/libft/ft_atoi.o \
			common/libft/ft_memdel.o \
			common/libft/ft_strcmp.o \
			common/libft/ft_strncmp.o \
			common/libft/ft_bzero.o \
			common/libft/ft_memmove.o \
			common/libft/ft_strcpy.o \
			common/libft/ft_strncpy.o \
			common/libft/ft_isalnum.o \
			common/libft/ft_memset.o \
			common/libft/ft_strdel.o \
			common/libft/ft_strnequ.o \
			common/libft/ft_isalpha.o \
			common/libft/ft_putchar.o \
			common/libft/ft_strdup.o \
			common/libft/ft_strnew.o \
			common/libft/ft_isascii.o \
			common/libft/ft_putchar_fd.o \
			common/libft/ft_strequ.o \
			common/libft/ft_strnstr.o \
			common/libft/ft_isdigit.o \
			common/libft/ft_putendl.o \
			common/libft/ft_striter.o \
			common/libft/ft_strrchr.o \
			common/libft/ft_isprint.o \
			common/libft/ft_putendl_fd.o \
			common/libft/ft_striteri.o \
			common/libft/ft_strsplit.o \
			common/libft/ft_itoa.o \
			common/libft/ft_putnbr.o \
			common/libft/ft_strjoin.o \
			common/libft/ft_strstr.o \
			common/libft/ft_lstmap.o \
			common/libft/ft_putnbr_fd.o \
			common/libft/ft_strlcat.o \
			common/libft/ft_strsub.o \
			common/libft/ft_memalloc.o \
			common/libft/ft_putstr.o \
			common/libft/ft_strlen.o \
			common/libft/ft_strtrim.o \
			common/libft/ft_memccpy.o \
			common/libft/ft_putstr_fd.o \
			common/libft/ft_strlen_const.o \
			common/libft/ft_tolower.o \
			common/libft/ft_memchr.o \
			common/libft/ft_strcat.o \
			common/libft/ft_strmap.o \
			common/libft/ft_toupper.o \
			common/libft/ft_memcmp.o \
			common/libft/ft_strchr.o \
			common/libft/ft_strmapi.o \
			common/libft/ft_memcpy.o \
			common/libft/ft_strclr.o \
			common/libft/ft_strncat.o \
			common/send_data.o \
			common/get_data.o \
			common/libft/getval.o \
			common/libft/is_capable.o \
			common/libft/is_scapable.o \
			common/libft/rec.o \
			common/libft/recah.o \
			common/libft/recnm.o \
			common/libft/src.o \
			common/libft/srchah.o \
			common/libft/srcnm.o \

OBJ2 =		guest_/client.o \
			guest_/handle.o \
			guest_/client_cmds.o \
			server_/do_select.o \
			server_/check_fd.o \
			common/libft/ft_atoi.o \
			common/libft/ft_memdel.o \
			common/libft/ft_strcmp.o \
			common/libft/ft_strncmp.o \
			common/libft/ft_bzero.o \
			common/libft/ft_memmove.o \
			common/libft/ft_strcpy.o \
			common/libft/ft_strncpy.o \
			common/libft/ft_isalnum.o \
			common/libft/ft_memset.o \
			common/libft/ft_strdel.o \
			common/libft/ft_strnequ.o \
			common/libft/ft_isalpha.o \
			common/libft/ft_putchar.o \
			common/libft/ft_strdup.o \
			common/libft/ft_strnew.o \
			common/libft/ft_isascii.o \
			common/libft/ft_putchar_fd.o \
			common/libft/ft_strequ.o \
			common/libft/ft_strnstr.o \
			common/libft/ft_isdigit.o \
			common/libft/ft_putendl.o \
			common/libft/ft_striter.o \
			common/libft/ft_strrchr.o \
			common/libft/ft_isprint.o \
			common/libft/ft_putendl_fd.o \
			common/libft/ft_striteri.o \
			common/libft/ft_strsplit.o \
			common/libft/ft_itoa.o \
			common/libft/getuntil.o \
			common/libft/ft_putnbr.o \
			common/libft/ft_strjoin.o \
			common/libft/ft_strstr.o \
			common/libft/ft_lstmap.o \
			common/libft/ft_putnbr_fd.o \
			common/libft/ft_strlcat.o \
			common/libft/ft_strsub.o \
			common/libft/ft_memalloc.o \
			common/libft/ft_putstr.o \
			common/libft/ft_strlen.o \
			common/libft/ft_strtrim.o \
			common/libft/ft_memccpy.o \
			common/libft/ft_putstr_fd.o \
			common/libft/ft_strlen_const.o \
			common/libft/ft_tolower.o \
			common/libft/ft_memchr.o \
			common/libft/ft_strcat.o \
			common/libft/ft_strmap.o \
			common/libft/ft_toupper.o \
			common/libft/ft_memcmp.o \
			common/libft/ft_strchr.o \
			common/libft/ft_strmapi.o \
			common/libft/ft_memcpy.o \
			common/libft/ft_strclr.o \
			common/libft/ft_strncat.o \
			common/send_data.o \
			common/get_data.o \
			common/libft/getval.o \
			common/libft/is_capable.o \
			common/libft/is_scapable.o \
			common/libft/rec.o \
			common/libft/recah.o \
			common/libft/recnm.o \
			common/libft/src.o \
			common/libft/srchah.o \
			common/libft/srcnm.o \

MAIN1 = serveur

MAIN2 = client

.PHONY: clean all re fclean

all: $(MAIN1) $(MAIN2)

$(NAME):

$(MAIN1): $(OBJ1)
		$(CC) $(CFLAGS) -o $(MAIN1) $(OBJ1)

$(MAIN2): $(OBJ2)
		$(CC) $(CFLAGS) -o $(MAIN2) $(OBJ2)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

fclean: clean
	@rm -f $(NAME) $(MAIN1) $(MAIN2)

re: fclean all

clean:
	@rm -f $(OBJ1) $(OBJ2) $(OBJ3)

depend: $(SRCS)
	makedepend $(INCLUDES1) $^ $(INCLUDES2) $^ $(INCLUDES3)
