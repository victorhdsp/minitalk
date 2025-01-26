CC=cc -Wall -Wextra -I ./ -ggdb
FILES= ./src/generic.o ./src/string.o 

CLIENT=client
CLIENT_FILES= $(FILES) ./src/client.o
CLIENT_B=client_bonus
CLIENT_FILES_B= $(FILES) ./src/client_bonus.o

SERVER=server
SERVER_FILES= $(FILES) ./src/server.o
SERVER_B=server_bonus
SERVER_FILES_B= $(FILES) ./src/server_bonus.o

all: $(CLIENT) $(SERVER)
bonus: $(CLIENT_B) $(SERVER_B)

$(CLIENT):$(CLIENT_FILES)
	$(CC) $^ -o $@

$(SERVER):$(SERVER_FILES)
	$(CC) $^ -o $@

$(CLIENT_B):$(CLIENT_FILES_B)
	$(CC) $^ -o $@

$(SERVER_B):$(SERVER_FILES_B)
	$(CC) $^ -o $@

.o: .c
	$(CC) -c $< -o $@

clean:
	rm -f $(CLIENT_FILES) $(SERVER_FILES)
	rm -f $(CLIENT_FILES_B) $(SERVER_FILES_B)

fclean: clean
	rm -f $(CLIENT) $(SERVER)
	rm -f $(CLIENT_B) $(SERVER_B)

re: clean all