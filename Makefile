NAME = serverclient.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
PRINTF = ft_printf/libftprintf.a

CLIENT = client
SERVER = server

SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

SRCS = server.c client.c
BONUS_SRCS = server_bonus.c client_bonus.c

BONUS_OBJS = $(BONUS_SRCS:.c=.o)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(SERVER) $(CLIENT) $(OBJS)

$(SERVER): $(OBJS)
	make -C ./ft_printf
	$(CC) $(CFLAGS) server.c $(PRINTF) -o $@

$(CLIENT): $(OBJS)
	$(CC) $(CFLAGS) client.c $(PRINTF) -o $@
	@echo "\033[33m             _       _ _        _ _    "
	@echo "\033[33m  _ __ ___ (_)_ __ (_) |_ __ _| | | __"
	@echo "\033[33m | '_ \` _ \| | '_ \| | __/ _\` | | |/ /"
	@echo "\033[34m | | | | | | | | | | | || |_| | |   < "
	@echo "\033[34m |_| |_| |_|_|_| |_|_|\__\__,_|_|_|\_\\"
	@echo "\033[0m"

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)  $(BONUS_OBJS)

$(SERVER_BONUS): $(BONUS_OBJS)
	make -C ./ft_printf
	$(CC) $(CFLAGS) server_bonus.c $(PRINTF) -o $@

$(CLIENT_BONUS): $(BONUS_OBJS)
	$(CC) $(CFLAGS) client_bonus.c $(PRINTF) -o $@
	@echo "\033[33m            _       _ _        _ _      _                           "
	@echo "\033[33m  _ __ ___ (_)_ __ (_) |_ __ _| | | __ | |__   ___  _ __  _   _ ___ "
	@echo "\033[33m | '_ \` _ \| | '_ \| | __/ _\` | | |/ / | '_ \ / _ \| '_ \| | | / __|"
	@echo "\033[34m | | | | | | | | | | | || (_| | |   <  | |_) | (_) | | | | |_| \__ \\"
	@echo "\033[34m |_| |_| |_|_|_| |_|_|\__\__,_|_|_|\_\ |_.__/ \___/|_| |_|\__,_|___/"
	@echo "\033[0m"
clean:
	make clean -C ./ft_printf
	rm -rf $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS) $(OBJS) $(BONUS_OBJS)

fclean: clean
	make fclean -C ./ft_printf

re: fclean all bonus

.PHONY: all clean fclean re bonus
