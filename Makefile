CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = Main.c StrList.c
OBJS = $(SRCS:.c=.o)
TARGET = StrList

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c StrList.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS) $(TARGET)
