CC=gcc
INCLUDE=./include

all: five seven

five: test/five.o src/libpheval5.a
	${CC} ${CFLAGS} $^ -o $@

six: test/six.o src/libpheval6.a
	${CC} ${CFLAGS} $^ -o $@

seven: test/seven.o src/libpheval7.a
	${CC} ${CFLAGS} $^ -o $@

src/libpheval5.a: src/evaluator5.o src/hash.o src/hashtable.o src/hashtable5.o src/dptables.o
	ar rcs $@ $^

src/libpheval6.a: src/evaluator6.o src/hash.o src/hashtable.o src/hashtable6.o src/dptables.o
	ar rcs $@ $^

src/libpheval7.a: src/evaluator7.o src/hash.o src/hashtable.o src/hashtable7.o src/dptables.o
	ar rcs $@ $^

%.o: %.c
	${CC} -c ${CFLAGS} -I${INCLUDE} $< -o $@

clean:
	rm -f src/*.o test/*.o *.o src/*.a five six seven

