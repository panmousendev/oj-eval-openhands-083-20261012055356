CC = gcc
CFLAGS = -Wall -Wextra -O2 -std=c99
TARGET = code
SOURCE = main.c

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)

clean:
	rm -f $(TARGET)

.PHONY: clean