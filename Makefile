CC=gcc

all: five seven

five: test/five.o src/evaluator5.o src/hash.o src/hashtable.o src/hashtable5.o src/hashtable7.o src/dptables.o
	${CC} ${CFLAGS} $^ -o $@

seven: test/seven.o src/evaluator7.o src/hash.o src/hashtable.o src/hashtable5.o src/hashtable7.o src/dptables.o
	${CC} ${CFLAGS} $^ -o $@

%.o: %.c
	${CC} -c ${CFLAGS} $< -o $@

clean:
	rm -f src/*.o test/*.o *.o five seven

