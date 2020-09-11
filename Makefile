CC=gcc 
CFLAGS=-g -std=c11 -Wall -Werror
TARGET=sorter

.PHONY: clean

all: $(TARGET)

clean:
	rm -f $(TARGET) 
	rm -f *.o
	rm -f ./src/*.o
	rm -f ./test/*.o

# object/executed file : dependcy
# ingredient

#Compiling
./src/sorter.o: ./src/sorter.c
	$(CC) -c $(CFLAGS) $^ -o $@

sorter: ./src/sorter.o
	$(CC) $(CFLAGS) $^ -o $@
