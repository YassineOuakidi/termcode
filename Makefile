CC = gcc
CFLAGS = 
SRC = main.c $(wildcard src/*.c)
TARGET = termcode
LIBS = -lncurses

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LIBS)

clean:
	rm -f $(TARGET)

re: clean all

