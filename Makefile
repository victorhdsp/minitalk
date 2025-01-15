CC=cc -Wall -Wextra -I ./ -ggdb

CLIENT=client
CLIENT_FILES= ./src/generic.o ./src/string.o ./src/client.o

SERVER=server
SERVER_FILES= ./src/generic.o ./src/string.o ./src/server.o

all: client server

client: $(CLIENT)

$(CLIENT):$(CLIENT_FILES)
	$(CC) $^ -o $@

server: $(SERVER)

$(SERVER):$(SERVER_FILES)
	$(CC) $^ -o $@

.o: .c
	$(CC) -c $< -o $@

clean:
	rm -f $(CLIENT_FILES) $(SERVER_FILES)

fclean: clean
	rm -f $(CLIENT) $(SERVER)

re: clean all