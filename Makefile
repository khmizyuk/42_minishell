MINISHELL = minishell

C_FILES = main.c lexer.c
H_FILES = minishell.h
O_FILES = $(C_FILES:.c=.o)

LIB_DIR = libft/

CC = gcc
Flags = -Wall -Wextra -Werror
RM = rm -f

all: $(MINISHELL)

$(MINISHELL): $(O_FILES)
	make -C $(LIB_DIR) --silent
	$(CC) -Ireadline -Lreadline -o $(MINISHELL) $(O_FILES) -L $(LIB_DIR) -lft

%.o: %.c $(H_FILES)
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	make -C $(LIB_DIR) clean
	$(RM) $(O_FILES)

fclean: clean
	make -C $(LIB_DIR) fclean
	$(RM) $(MINISHELL)

re: fclean all

.PHONY: all clean fclean re