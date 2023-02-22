#Makefile

#target: dependencies
#		action

CLIENT = client
SERVER = server

C_FILES = client.c utils.c
S_FILES = server.c utils.c

C_OBJS = $(C_FILES:.c=.o)
S_OBJS = $(S_FILES:.c=.o)

all: $(CLIENT) $(SERVER)

$(CLIENT): $(C_OBJS)
	cc $(C_FLAGS) $(C_OBJS) -o $(CLIENT)

$(SERVER): $(S_OBJS)
	cc $(C_FLAGS) $(S_OBJS) -o $(SERVER)

clean:
	rm -f $(C_OBJS) $(S_OBJS)

fclean: clean
	rm -f $(CLIENT) $(SERVER)

re: fclean all