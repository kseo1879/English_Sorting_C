CC=gcc 
CFLAGS=-g -std=c11 -Wall -Werror
TARGET=sorter

.PHONY: clean
.PHONY: test1
.PHONY: test2
.PHONY: test3
.PHONY: test4

all: $(TARGET)

clean:
	rm -f $(TARGET) 
	rm -f *.o
	rm -f ./src/*.o
	rm -f ./src/helper/*.o
	rm -f ./test/*.o

test1:
	./sorter ./test/alph-ascending.txt -a -alph

test2:
	./sorter ./test/alph-descending.txt -d -alph

test3:
	./sorter ./test/num-ascending.txt -a -num

test4:
	./sorter ./test/num-descending.txt -d -num


# object/executed file : dependcy
# ingredient

#Compiling
./src/sorter.o: ./src/sorter.c
	$(CC) -c $(CFLAGS) $^ -o $@

./src/helper/alpha.o: ./src/helper/alpha.c
	$(CC) -c $(CFLAGS) $^ -o $@

./src/helper/num.o: ./src/helper/num.c
	$(CC) -c $(CFLAGS) $^ -o $@

sorter: ./src/sorter.o ./src/helper/alpha.o ./src/helper/num.o
	$(CC) $(CFLAGS) $^ -o $@
