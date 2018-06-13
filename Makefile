# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jebossue <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/09 17:54:20 by jebossue          #+#    #+#              #
#    Updated: 2018/03/09 17:55:29 by jebossue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN =		\033[1;32m

RED =		\033[1;31m

RES =		\033[0m

#------------------------------------------------------------------------------#

NAME =		lem-in

SRC =		main.c pars.c parsing_rooms.c parsing_pipes.c save_paths.c	\
			save_paths_tools.c save_paths_tools2.c send_ants.c del.c		\
			delpars.c checkintmax.c checkrooms.c

SRCDIR =	./srcs

OBJ =		$(SRC:%.c=$(OBJDIR)/%.o)

OBJDIR =	./objs

#------------------------------------------------------------------------------#

INCDIR =	./includes

LIBINCDIR =	./libft/includes

LIBDIR =	./libft

#------------------------------------------------------------------------------#

CC =		gcc

CFLAGS =	-Wall			\
			-Wextra			\
			-Werror

INCFLAGS =	-I $(INCDIR)	\
			-I $(LIBINCDIR)

LFLAGS =	-L $(LIBDIR) -lft

FLAGS =		$(CFLAGS)		\
			$(INCFLAGS)

#------------------------------------------------------------------------------#

all: libft

libft:
	@$(MAKE) -C ./libft all
	@$(MAKE) $(NAME)

$(NAME): $(OBJ)
	@echo "[$(GREEN)Ok$(RES)] Compiling : "$@
	@$(CC) -g $(FLAGS) $(LFLAGS) $(OBJ) -o $@
	@echo "Compilation done !"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@echo "[$(GREEN)Ok$(RES)] Compiling : "$@
	@$(CC) -g $(FLAGS) -o $@ -c $<

clean:
	@echo "Cleaning"
	rm -rf $(OBJDIR)
	@$(MAKE) -C ./libft clean

fclean: clean
	rm -rf $(NAME)
	@$(MAKE) -C ./libft fclean

re: fclean
	@$(MAKE) all

#------------------------------------------------------------------------------#

norm:
	@echo "Passage de la norminette : $(RED)"
	@norminette $(SRCDIR) $(INCDIRS) $(LIBDIR) | grep -B1 Error | cat

git:
	@git add Makefile $(SRCDIR) $(INCDIR) auteur libft

.PHONY: all clean re fclean git no printf check libft
