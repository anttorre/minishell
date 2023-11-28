#//= Colors =//#
BOLD	:= \033[1m
BLACK	:= \033[30;1m
RED		:= \033[31;1m
GREEN	:= \033[32;1m
YELLOW	:= \033[33;1m
BLUE	:= \033[34;1m
MAGENTA	:= \033[35;1m
CYAN	:= \033[36;1m
WHITE	:= \033[37;1m
RESET	:= \033[0m

NAME = minishell

#NAME_BONUS = pipex_bonus

CC = gcc

CFLAGS = -g -Wall -Werror -Wextra

LIBFT_PATH = ./libft

LIBFT = $(LIBFT_PATH)/libft.a

MINISHELL = minishell.a

INCLUDES = -lreadline

#PIPEX_BONUS = pipex_bonus.a

LIB = ar rcs

SRCS =  src/main.c src/minishell_utils.c src/free_program.c src/init_struct.c \
		src/split_quotes_utils.c src/minishell_utils_2.c src/builtins/builtins.c \
		src/builtins/env_utils.c src/builtins/export_utils.c src/builtins/export_utils_2.c \
		

OBJS = $(SRCS:.c=.o)

#SRCS_BONUS =

#OBJS_BONUS = $(SRCS_BONUS:.c=.o)

$(NAME) :	$(OBJS) $(LIBFT)
			@echo "$(MAGENTA)$(BOLD)Compiling minishell...$(RESET)"
			@$(LIB) $(MINISHELL) $(OBJS)
			@$(CC) $(CFLAGS) $(INCLUDES) $(LIBFT) $(MINISHELL) -o $(NAME)
			@echo "$(CYAN)$(BOLD)Done$(RESET)"

$(OBJS):	src/%.o : src/%.c 
			@$(CC) $(CFLAGS) -c $< -o $@

#$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT)
#			@echo "$(YELLOW)$(BOLD)Compiling pipex bonus...$(RESET)"
#			@$(LIB) $(PIPEX_BONUS) $(OBJS_BONUS)
#			@$(CC) $(CFLAGS) $(PIPEX_BONUS) $(LIBFT) -o $(NAME_BONUS)
#			@echo "$(CYAN)$(BOLD)Done$(RESET)"

#$(OBJS_BONUS):	srcb/%.o : srcb/%.c
#			@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
			@make -s -C $(LIBFT_PATH)
			@make bonus -s -C $(LIBFT_PATH)

all : $(NAME)

bonus : $(NAME_BONUS)

clean:
			@echo "$(RED)$(BOLD)Cleaning objects from minishell...$(RESET)"
			@rm -f $(OBJS) $(OBJS_BONUS)
			@echo "$(GREEN)$(BOLD)Done.$(RESET)"
			@make clean -s -C $(LIBFT_PATH)

fclean:
			@echo "$(RED)$(BOLD)Cleaning all files from minishell...$(RESET)"
			@rm -f $(NAME) $(NAME_BONUS) $(OBJS) $(OBJS_BONUS) $(LIBFT) $(MINISHELL) $(PIPEX_BONUS)
			@echo "$(GREEN)$(BOLD)Done.$(RESET)"
			@make fclean -s -C $(LIBFT_PATH)

re : fclean all

pipe : all clean

.PHONY : all re fclean clean bonus