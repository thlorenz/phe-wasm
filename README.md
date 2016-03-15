# PHEvaluator

PH stands for Poker Hand, as well as Perfect Hashing.

A poker hand evaluation algorithm with perfect hash functions and dynamic
programming.

Copyright 2016 Henry Lee (lee0906@hotmail.com)

---------
Overview
---------
It's a brand new algorithm, mainly designed to avoid traversing all 21
combinations when evaluating a 7-card poker hand.

The implementation supports both 5-card and 7-card evaluating, where the 7-card
version beats every other implementation I can find on the Internet.

The source code provides a 5-card hand evaluator and a 7-card hand evaluator in
a considerably small memory. The branch `fast` contains another implementation
(with a slightly different algorithm) which uses a nearly 300Mb memory when
evaluating a 7-card hand, but the amount of CPU cycles is very small.

Their return value is identical to the Cactus Kev's Poker Hand Evaluator
(http://suffe.cool/poker/evaluator.html). However, one can modify the hash table
to support any kinds of evaluation system he likes.

`Documentation` contains the description of the algorithms used in the
evaluators.

---------
Compile and test
---------
Simply run `make` can compile the source files and test program.

If you like to add more flags in gcc, you may export the flags to the variable
CFLAGS. One example is `export CLFAGS="-Ofast"`.

After the compilation, it generates two programs `five` and `seven`. These test
programs are cloned from Cactus Kev's evaulator, which loops over all possible
hands and display the frequency of each hand type, so that we can approximately
tell if the algorithms are correct or not.

If you want to test the time used for evaluating all hands, run `time ./five` or
`time ./seven`.

---------
Interfaces
---------
If you want to port the code to your own project, you need to copy all the files
under the `src` directory. The file `evaluator.h` contains the interfaces you
need to call.

The inputs are card ids ranged from 0 - 51. The card id modulo 4 gives the suit.
It doesn't really matter how you assign the four numbers to the 4 suits, as
long as they use a distinct number. The card id divided by 4 gives the rank,
where ace has the highest value 12 and deuce has the lowest value 0.

The return value is identical to the Cactus Kev's evaluator. The strongest hands
(Royal straight flush) are returned with 1, and the second strongest hands (King
high straight flush) are returned with 2 and so on. The weakest hands have the
return value 7462.

You can find more about Cactus Kev's evaluation system from these websites.

http://suffe.cool/poker/evaluator.html
http://suffe.cool/poker/7462.html


