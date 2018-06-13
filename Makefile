# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jebossue <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/09 17:54:20 by jebossue          #+#    #+#              #
#    Updated: 2018/06/13 16:10:23 by sgauguet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN =		\033[1;32m

RED =		\033[1;31m

RES =		\033[0m

#------------------------------------------------------------------------------#

NAME =		corewar

SRC =		main.c \

SRCDIR =	./srcs

OBJ =		$(SRC:%.c=$(OBJDIR)/%.o)

OBJDIR =	./objs

HEADER =	./includes/corewar.h

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

$(NAME): $(OBJ) $(HEADER)
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
