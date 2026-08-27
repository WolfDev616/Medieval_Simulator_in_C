CC = gcc

CFLAGS = -Wall -Wextra -I/usr/local/include

LIBS = -L/usr/local/lib -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

TARGET = medieval_test

SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJECTS) $(TARGET)
