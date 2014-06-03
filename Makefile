# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npineau <npineau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/08 10:39:32 by npineau           #+#    #+#              #
#    Updated: 2014/06/03 16:07:27 by jvincent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	fckoff
CLIENT	:=	client
SERVEUR	:=	serveur
GFX		:=	gfx

### DIRECTORIES ###

DIRSRC	:=	sources
DIRSRV	:=	$(DIRSRC)/$(SERVEUR)
DIRCLI	:=	$(DIRSRC)/$(CLIENT)
DIRGFX	:=	$(DIRSRC)/$(GFX)
DIROBJ	:=	objects
DIRINC	:=	includes
DIRLIB	:=	libft
DIRSDL	:=	SDL2

### FILES ###

SRCCLI	:=	client.c

SRCSRV	:=	serveur.c

SRCGFX	:=	gfx.c

OBJCLI	:=	$(SRCCLI:.c=.o)
OBJSRV	:=	$(SRCSRV:.c=.o)
OBJGFX	:=	$(SRCGFX:.c=.o)

HEADCLI	:=	client.h
HEADSRV	:=	$(SERVEUR).h
HEADGFX	:=	gfx.h
LIB		:=	libft.a
SLIB	:=	libSDL2.a
SILIB	:=	SDL2_image.a

### PATHS ###

POBJCLI		:=	$(addprefix $(DIROBJ)/, $(OBJCLI))
POBJSRV		:=	$(addprefix $(DIROBJ)/, $(OBJSRV))
POBJGFX		:=	$(addprefix $(DIROBJ)/, $(OBJGFX))

PHEADCLI	:=	$(DIRINC)/$(HEADCLI)
PHEADSRV	:=	$(DIRINC)/$(HEADSRV)
PHEADGFX	:=	$(DIRINC)/$(HEADGFX)
PLIB		:=	$(DIRLIB)/$(LIB)
PSDL		:=	$(DIRSDL)/lib/$(SLIB)

### COMPILATION VARIABLES ###

CC		:=	llvm-gcc
C_FLAG	:=	-Wall -Wextra -Werror
O_FLAG	:=	-O3
L_FLAG	:=	-L $(DIRLIB) -lft -L $(DIRSDL)/lib -lSDL2 -lSDL2_image
C_INC	:=	-I $(DIRINC) -I $(DIRLIB)/$(DIRINC) -I $(DIRSDL)/include/$(DIRSDL)/

COMPIL	=	$(CC) -o $@ -c $< $(C_INC) $(C_FLAG) $(O_FLAG)
LINK	=	$(CC) -o $@ $^ $(L_FLAG)

### RULES ###

.PHONY: all clean fclean re

all: $(PSDL) $(PLIB) $(SERVEUR) $(CLIENT) $(GFX)

### SDL2.0 ###

$(PSDL):
	mkdir -p $(DIRSDL)/junk
	curl -O http://www.libsdl.org/release/SDL2-2.0.3.tar.gz
	tar xf SDL2-2.0.3.tar.gz
	( cd SDL2-2.0.3 \
		&& ./configure CC=clang --prefix=$(shell pwd)/$(DIRSDL)/ \
		&& $(MAKE) && $(MAKE) install )
	mv SDL2-2.0.3.tar.gz SDL2-2.0.3 SDL2/junk
	curl -O https://www.libsdl.org/projects/SDL_image/release/SDL2_image-2.0.0.tar.gz
	tar xf SDL2_image-2.0.0.tar.gz
	( cd SDL2_image-2.0.0 \
		&& ./configure CC=clang OBJC=clang --prefix=$(shell pwd)/$(DIRSDL)/ \
		&& $(MAKE) && $(MAKE) install )
	mv SDL2_image-2.0.0.tar.gz SDL2_image-2.0.0 SDL2/junk

### LIBFT ###

$(PLIB):
	make -C $(DIRLIB)

### OBJECTS ###

$(DIROBJ):
	mkdir $(DIROBJ)

$(POBJSRV): |$(DIROBJ)

$(POBJCLI): |$(DIROBJ)

$(POBJGFX): |$(DIROBJ)

$(DIROBJ)/%.o: $(DIRCLI)/%.c $(PHEADCLI)
	$(COMPIL)

$(DIROBJ)/%.o: $(DIRSRV)/%.c $(PHEADSRV)
	$(COMPIL)

$(DIROBJ)/%.o: $(DIRGFX)/%.c $(PHEADGFX)
	$(COMPIL)

### EXECUTABLE ###

$(NAME):
	echo $(NAME)

$(CLIENT): $(POBJCLI)
	$(LINK)

$(SERVEUR): $(POBJSRV)
	$(LINK)

$(GFX): $(POBJGFX)
	$(LINK)

### CLEAN UP ###

clean:
	rm -rf $(DIROBJ)

fclean: clean
	rm -f $(CLIENT) $(SERVEUR) $(GFX)

re: fclean all
