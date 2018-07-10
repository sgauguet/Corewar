# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jebossue <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/09 17:54:20 by jebossue          #+#    #+#              #
#    Updated: 2018/07/10 09:28:18 by sgauguet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN =		\033[1;32m

RED =		\033[1;31m

RES =		\033[0m

#------------------------------------------------------------------------------#

NAME =		corewar

SRC =		vm_main.c \
			vm_initialization.c \
			vm_options.c \
			vm_create_players.c \
			vm_check_players.c \
			vm_load_players.c \
			vm_exec_process.c \
			vm_destroy_process.c \
			vm_process_stack.c \
			vm_instructions.c \
			vm_exec_instructions.c \
			vm_exec_functions.c \
			vm_display_arena.c \
			vm_display_messages.c \
			vm_display_errors.c \
			vm_debug.c \
			exec_st.c \
			exec_zjmp.c \
			exec_sti.c \
			exec_fork.c \
			exec_lfork.c \
			exec_aff.c

SRCDIR =	./srcs

OBJ =		$(SRC:%.c=$(OBJDIR)/%.o)

OBJDIR =	./objs

HEADER =	$(INCDIR)/corewar.h \
		$(INCDIR)/op.h \

#------------------------------------------------------------------------------#

INCDIR =	./includes

LIBINCDIR =	./libft/includes

LIBDIR =	./libft

#------------------------------------------------------------------------------#

CC =		gcc

CFLAGS =	-Wall \
			-Wextra \
			-Werror \
			-fsanitize=address

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
	@$(CC) -g $(FLAGS) $(OBJ) -o $@ $(LFLAGS)
	@echo "Compilation done !"

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADER)
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
