INCLUDE=./include

all: five six seven

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
	rm -f src/*.o test/*.o *.o src/*.a five six seven ./wasm/*


## wasm build related tasks

WASM2JS=./node_modules/.bin/wasm2js

WASM_DIR=./wasm
WASM_FLAGS=-std=c99 -Oz -O3 -s WASM=1 -s SIDE_MODULE=1

EV5_SRCS=src/evaluator5.c src/hash.c src/hashtable.c src/hashtable5.c src/dptables.c
EV6_SRCS=src/evaluator6.c src/hash.c src/hashtable.c src/hashtable6.c src/dptables.c
EV7_SRCS=src/evaluator7.c src/hash.c src/hashtable.c src/hashtable7.c src/dptables.c
EV_SRCS=src/evaluator5.c src/hashtable5.c \
		src/evaluator6.c src/hashtable6.c \
		src/evaluator7.c src/hashtable7.c \
		src/hash.c src/hashtable.c src/dptables.c

install-emsdk:
	./scripts/install-emsdk.sh

$(WASM_DIR)/phe.wasm.js: $(EV_SRCS)
	source ./emsdk/emsdk_env.sh && \
	emcc $^ $(WASM_FLAGS) -o $(WASM_DIR)/phe.wasm && \
	$(WASM2JS) $(WASM_DIR)/phe.wasm -o $(WASM_DIR)/phe.wasm.js

wasm: $(WASM_DIR)/phe.wasm.js 
