# push_swap

"This project will make you sort data on a stack, with a limited set of instructions, using
the lowest possible number of actions. To succeed you’ll have to manipulate various
types of algorithms and choose the one (of many) most appropriate solution for an
optimized data sorting."

BEST:
500: 6084 - 7236
100: 646 - 852

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
