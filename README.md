# Eight-queens

This is the simplest, cleanest and easiest-to-understand solution I can come up in one night. 

This compares a generate-everything-and-verify approach:

1. Permute _all_ possible queen positions for each column.
2. Go through each permutation and find a valid one.

Against a simple stack-based search (aka Depth-First-Search) using Backtracking:

1. Permute all possible queen position in the _current_ column.
2. If we're at a dead end, stop and rewind one step.
3. Otherwise, proceed to the next column and retry step 1.
4. If we've gone past the last column, check if all queen placements insofar is valid.

There is, however, another way to write this which can make it super-fast, use less memory and can calculate the N-Queens problem at 100x100 scales upwards in a fraction of a second. If I find the time (and inspiration) I just might show you how to do it :) Some key points:

* Store a `long int` that flags row occupation. Since two queens can never be in the same row, we've now reduced this case to an O(1) bitwise check.
* At each column processing, pass an array that lists the row number of queen positions made so far. This can be used to quickly calculate wether or not a position on current column is diagonal to another queen.
* Scan forwards when moving from column to column i.e. if we place a queen at row 2 last column, we should start scanning at row 4 onwards.
* Memoize everything that can be memo-ized (turns out there're quite a few places if you really wrote the thing.)
* Forego recursion entirely. It's actually quite easy to use a simple `for`-loop for the entire solving algorithm.

How to run:

* `make` or `make profile` - to build both implementations and profile them.
* `make naive` - to build naive implementation.
* `make fast` - to build optimized implementation.
* `make both` - to build both implementations.

How to valgrind:

* `make grind` - To grind both implementations.
* `make fast && valgrind --leak-check=full bin/eq-fast` - To grind optimized implementation.
* `make naive && valgrind --leak-check=full bin/eq-naive` - To grind naive implementation.
