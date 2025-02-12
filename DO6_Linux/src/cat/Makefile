CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
SRCS = main.c parser.c reader.c
OBJS = $(SRCS:.c=.o)
CAT = s21_cat

s21_cat: $(CAT)

$(CAT): $(OBJS)
	$(CC) $(OBJS) -o $@    
	rm -rf $(OBJS)


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -rf $(CAT) $(OBJS)

.PHONY: cat