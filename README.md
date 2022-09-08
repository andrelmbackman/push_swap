# push_swap

"This project will make you sort data on a stack, with a limited set of instructions, using
the lowest possible number of actions. To succeed you’ll have to manipulate various
types of algorithms and choose the one (of many) most appropriate solution for an
optimized data sorting."

- [] make for 6-90 size a simpler
- [] protect malloc, leaks, free all nodes..
- [] test all sizes, all int overloads, all flags, all atoll errors, -0, +1..
- [] double check the makefile errors, such as no program found = no recompile make re



BEST:
100: 646 - 852
500: 6084 - 7236

100: 583 - 655
500: 5018 - 5445

- Make use of -c and -v flags? only one at a time, if after numbers, display
usage message and exit.

If a == NULL; then return 0 (0 moves for A);

find match depending on if i </> (b_size / 2), if no dst.. or always look for
the smallest that is still larger, rotate it to the top of A. In some cases,
the minimum number of moves requires inefficient rotations in stack A. For instance
if it is closer to the bottom, but the one in stack B is closer to the top relatively speaking.
The use of RR to match both to the top might be beneficial.

1. find the closest above, use the index to calculate the moves.
2. find the closest below, -||-
3. Each of the above has two numbers, one for how many RA it would take, one for
how many RRA it would take to get it to the top (or top->prev in case it is lower
than the one being pushed to A). These can be matched however as long as the amount
of rotations in A is <= the rotations in B. In some cases, the lowest might be
to not rotate in the same direction at all.
4. find the lowest amount of rotations to get both to the right position,
5. ???
6. Profit



PA: (PB: longest increasing subsequence?)
PA: look for subchunks instead of largest to smallest, this will grant easier search,
more use of RR, RRR, SS? - look for (10) numbers? push, get them in order, rotate out
of the way to fit them in
- Push them back in general order, they will not be in perfect order until the
whole subchunk is pushed back to A.

- [ ] if not using dst_prev: deletet it from header and get_destined
- [ ] Every check before pushing to b: check if SS, RR or RRR is useful.

- [ ] protect from a huge number of ints?
- [ ] protect against seg faults when doing -0, +1..
https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e
- make a script that uses curl to get 500 random ints
