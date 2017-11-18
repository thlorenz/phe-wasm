# PHEvaluator including WASM

Added WASM version and JS API to use it. At this point (using Node.js v8) the JavaScript
implementation itself ([phe](https://github.com/thlorenz/phe)) is only 5% slower than the 
C implementation.

Using wasm (this implementation) drops this difference to about 2-3%. So we get a small
advantage over JS, but in most cases not enough to justify loading the 232K wasm module.

However if you want to use it here are the 3 functions exposed by the API:

- evaluator5: evaluates 5 cards 
- evaluator6: evaluates 6 cards 
- evaluator7: evaluates 7 cards 

More info see [these tests](https://github.com/thlorenz/phe-wasm/tree/master/wasm/test).

* * *

PH stands for Poker Hand, as well as Perfect Hashing.

A poker hand evaluation algorithm with perfect hash functions and dynamic
programming.

Copyright 2016 Henry Lee (lee0906@hotmail.com)

---------
Overview
---------
It's a brand new algorithm, which avoids traversing all 7 choose 5 combinations
when evaluating a 7-card poker hand, but uses a perfect hash function instead.

The implementation supports both 5-card and 7-card evaluation, where the 7-card
version beats many other algorithms in the execution time, and it's also using
a considerably small memory (~100kb for the 7-card evaluation).

Their return value is identical to the Cactus Kev's Poker Hand Evaluator
(http://suffe.cool/poker/evaluator.html), where basically a stronger hand has a
lower return value. However, one can modify the hash table to support any kind
of evaluation system he likes.

`Documentation` contains the description of the algorithms used in the
evaluators.

The `examples` directory has some examples that demonstrates how to use the
interface.

---------
Compile and test
---------
Simply run `make` can compile the libraries and test program.

If you'd like to add some more flags in gcc, you may export the flags to the
environment variable `CFLAGS`. One example is `export CLFAGS="-Ofast"`.

After the compilation, it generates two programs `five` and `seven`. These test
programs are cloned from Cactus Kev's evaulator, which loops over all possible
hands and display the frequency of each hand type, so that we can approximately
tell if the algorithms are correct or not.

If you want to test the time used for evaluating all hands, run `time ./five` or
`time ./seven`.

As for the programs in `examples`, simply `cd examples` and running `make` will
compile all these programs.

---------
Interfaces
---------
The file `include/evaluator.h` contains the interfaces you need to call.

The inputs are card ids ranged [0, 51]. The card id modulo 4 gives the suit.
It doesn't really matter how you assign the four numbers to the 4 suits, as
long as they use distinct numbers. The card id divided by 4 gives the rank,
where ace has the highest value 12 and deuce has the lowest value 0.

The return value is identical to the Cactus Kev's evaluator. The strongest hands
(Royal straight flush) are returned with 1, and the second strongest hands (King
high straight flush) are returned with 2 and so on. The weakest hands have the
return value 7462.

You can find more about Cactus Kev's evaluation system from these websites.

http://suffe.cool/poker/evaluator.html
http://suffe.cool/poker/7462.html


