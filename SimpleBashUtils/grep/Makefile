CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
SRCS = main.c parser.c reader.c
OBJS = $(SRCS:.c=.o)
GREP = s21_grep

s21_grep: $(GREP)

$(GREP): $(OBJS)
	$(CC) $(OBJS) -o $@    
	rm -rf $(OBJS)


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -rf $(GREP) $(OBJS)

.PHONY: s21_grep