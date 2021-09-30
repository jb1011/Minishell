NAME    = minishell

HEAD    = includes

SRCDIR  = srcs/

LIB             = ./lib/

FILES   =       minishell.c \
				fonctions.c	\
				setting_ending.c \
				parsing.c \
				free.c \
				utils.c \
				builtins.c \
				orders_utils.c \
				env.c \
				env_builtins.c \
				list_init.c \
				orders_treatment.c \
				redirections.c \
				signals.c \
				pipes.c \
				parsing_utils3.c \
				parsing_utils1.c \
				parsing_utils2.c \
				parsing_del.c \
				treatment.c

SRCS    = $(addprefix $(SRCDIR), $(FILES))

OBJS    = ${SRCS:.c=.o} 

CC              = gcc 

RM              = rm -f

CFLAGS  = -Wall -Wextra  -g3  -I $(HEAD)

FLAGS = -L $(LIB)libft -lft -L/usr/includes -lcurses 

MACOS_MACRO = -D MACOS 
LINUX_MACRO = -D LINUX 

MACOS_FLAGS = 

LINUX_FLAGS = -L/usr/includes -lreadline

UNAME := $(shell uname)

ifeq ($(UNAME),Darwin)
        CFLAGS += $(MACOS_MACRO)
        FLAGS += $(MACOS_FLAGS)
endif
ifeq ($(UNAME),Linux)
        CFLAGS += $(LINUX_MACRO)
        FLAGS += $(LINUX_FLAGS)
endif

${NAME}:	${OBJS}
		make -C $(LIB)libft
		${CC} ${CFLAGS} $(OBJS) $(FLAGS) -o ${NAME}

all:            ${NAME}

clean:
		make clean -C $(LIB)libft
		${RM} ${OBJS}

fclean:         clean
		make fclean -C $(LIB)libft
		${RM} ${NAME}

re:                     fclean all

PHONY:          all clean fclean re