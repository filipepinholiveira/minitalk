#Makefile

#target: dependencies
#		action

CLIENT = client
SERVER = server

CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

C_FILES = client.c utils.c
S_FILES = server.c utils.c

C_FILES_BONUS = client_bonus.c utils.c
S_FILES_BONUS = server_bonus.c utils.c

C_OBJS = $(C_FILES:.c=.o)
S_OBJS = $(S_FILES:.c=.o)

C_OBJS_BONUS = $(C_FILES_BONUS:.c=.o)
S_OBJS_BONUS = $(S_FILES_BONUS:.c=.o)

all: $(CLIENT) $(SERVER)

$(CLIENT): $(C_OBJS)
	cc $(C_FLAGS) $(C_OBJS) -o $(CLIENT)

$(SERVER): $(S_OBJS)
	cc $(C_FLAGS) $(S_OBJS) -o $(SERVER)

bonus: $(CLIENT_BONUS) $(SERVER_BONUS) 
$(CLIENT_BONUS): $(C_OBJS_BONUS)
	cc $(C_FLAGS) $(C_OBJS_BONUS) -o $(CLIENT_BONUS)

$(SERVER_BONUS): $(S_OBJS_BONUS)
	cc $(C_FLAGS) $(S_OBJS_BONUS) -o $(SERVER_BONUS)

clean:
	rm -f $(C_OBJS) $(S_OBJS) $(C_OBJS_BONUS) $(S_OBJS_BONUS)

fclean: clean
	rm -f $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

re: fclean all bonus