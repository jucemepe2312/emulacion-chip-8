CC = gcc
CFLAGS = -Wall -Wextra -Ilib
SRC = src/main.c lib/chip8.c
OBJ = $(SRC:.c=.o)
TARGET = bin/chip8

all: $(TARGET)

$(TARGET): $(OBJ)
	@mkdir -p bin
	$(CC) $(OBJ) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)