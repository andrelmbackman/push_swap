# push_swap

"This project will make you sort data on a stack, with a limited set of instructions, using
the lowest possible number of actions. To succeed you’ll have to manipulate various
types of algorithms and choose the one (of many) most appropriate solution for an
optimized data sorting."

BEST:
500: 6084 - 7236
100: 646 - 852

100: 583 - 655
500: 5018 - 5445


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

- [ ] f(x): find the range of subchunk
- [ ] f(x): subchunk(int chunk_no, int subcount) >> 
>> one_subchunk(pushes one subchunk) >> quickest(pushes one node from the subchunk in order, RB, RRB, RA, RRA, RR, RRR)

- [ ] make two_chunks work with any number of ints
(- [ ] function that checks the general visinity, would it be beneficial to keep
doing rb or rrb?)
- [x] push the necessary ones when rotating
- [ ] if not using dst_prev: deletet it from header and get_destined
- [x] determine the range of each chunk, before each push: find the one that is closest
(with ra or rra)
- [x] make a function that pushes chunks, that takes an int count argument to chose
how many chunks (this way experimenting will be a lot easier)- [ ] when pushing back chunks, check if you can save moves by not rotating, and instead pushing and doing ss
- [ ] Every check before pushing to b: check if SS, RR or RRR is useful.

- [ ] protect from a huge number of ints?
- [ ] protect against seg faults when doing -0, +1..

- [ ] Make radix sort but before the loop, check how many fit the thing, then stop when they have all been pushed??
- [ ] Make radix sort work with negative numbers (make them in order and positive), only call if n < some large number and k < ?
https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e

- make a script that uses curl to get 500 random ints
