CC=gcc
TOPDIR=..
INCLUDE=${TOPDIR}/include
SRC=${TOPDIR}/src

all: example1 example2

example1: example1.o ${SRC}/libpheval7.a
	${CC} ${CFLAGS} $^ -o $@

example2: example2.cc ${SRC}/evaluator7.c ${SRC}/hash.c ${SRC}/hashtable.c ${SRC}/hashtable7.c ${SRC}/dptables.c
	g++ ${CFLAGS} -std=c++11 -I${INCLUDE} $^ -o $@

${SRC}/libpheval5.a: ${SRC}/evaluator5.o ${SRC}/hash.o ${SRC}/hashtable.o ${SRC}/hashtable5.o ${SRC}/dptables.o
	ar rcs $@ $^

${SRC}/libpheval6.a: ${SRC}/evaluator6.o ${SRC}/hash.o ${SRC}/hashtable.o ${SRC}/hashtable6.o ${SRC}/dptables.o
	ar rcs $@ $^

${SRC}/libpheval7.a: ${SRC}/evaluator7.o ${SRC}/hash.o ${SRC}/hashtable.o ${SRC}/hashtable7.o ${SRC}/dptables.o
	ar rcs $@ $^

%.o: %.c
	${CC} -c ${CFLAGS} -I${INCLUDE} $< -o $@

clean:
	rm -rf *.o example1 example2
