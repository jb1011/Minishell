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
				fct_utils.c

SRCS    = $(addprefix $(SRCDIR), $(FILES))

OBJS    = ${SRCS:.c=.o} 

CC              = gcc 

RM              = rm -f

CFLAGS  = -Wall -Wextra -g3 -fsanitize=address  -I $(HEAD) -D NUM_THREADS=$(NUM_THREADS)

FLAGS = -L $(LIB)libft -lft -L/usr/includes -lcurses 

MACOS_MACRO = -D MACOS 
LINUX_MACRO = -D LINUX 

MACOS_FLAGS = 

LINUX_FLAGS = -L/usr/includes -lreadline -lpthread

UNAME := $(shell uname)

ifeq ($(UNAME),Darwin)
        NUM_THREADS = $(shell sysctl -n hw.ncpu)
        CFLAGS += $(MACOS_MACRO)
        FLAGS += $(MACOS_FLAGS)
endif
ifeq ($(UNAME),Linux)
        NUM_THREADS = $(shell nproc --all)
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