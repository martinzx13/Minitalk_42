CC = cc
CFLAGS = -Wall -Wextra -Werror 

CLIENT_SRC = client.c libft.c
SERVER_SRC = server.c libft.c

CLIENT_SRC_BONUS = client_bonus.c libft.c
SERVER_SRC_BONUS = server_bonus.c libft.c

CLIENT_OUT = client
SERVER_OUT = server

CLIENT_OUT_BONUS = client_bonus
SERVER_OUT_BONUS = server_bonus

all: $(CLIENT_OUT) $(SERVER_OUT) $(CLIENT_OUT_BONUS) $(SERVER_OUT_BONUS)

$(CLIENT_OUT): $(CLIENT_SRC)
	$(CC) $(CFLAGS) $(CLIENT_SRC) -o $(CLIENT_OUT)

$(SERVER_OUT): $(SERVER_SRC)
	$(CC) $(CFLAGS) $(SERVER_SRC) -o $(SERVER_OUT)

$(CLIENT_OUT_BONUS): $(CLIENT_SRC_BONUS)
	$(CC) $(CFLAGS) $(CLIENT_SRC_BONUS) -o $(CLIENT_OUT_BONUS)

$(SERVER_OUT_BONUS): $(SERVER_SRC_BONUS)
	$(CC) $(CFLAGS) $(SERVER_SRC_BONUS) -o $(SERVER_OUT_BONUS)

clean:
	rm -f $(CLIENT_OUT) $(SERVER_OUT) $(CLIENT_OUT_BONUS) $(SERVER_OUT_BONUS)

fclean: clean

re: fclean all

.PHONY: all clean fclean re