CC		= gcc
CFLAGS	= -ansi -Wall -Werror -Wextra -pedantic -Og -g
OBJS	= heap.o main.o
TARGET	= a.out

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY : clean

clean :
	rm -rf $(TARGET) $(OBJS)
