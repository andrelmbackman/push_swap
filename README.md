# push_swap

"This project will make you sort data on a stack, with a limited set of instructions, using
the lowest possible number of actions. To succeed you’ll have to manipulate various
types of algorithms and choose the one (of many) most appropriate solution for an
optimized data sorting."

- [] visualizer: pygame
https://docs.python.org/3/library/subprocess.html

https://www.petercollingridge.co.uk/tutorials/pygame-physics-simulation/creating-pygame-window/

https://www.geeksforgeeks.org/how-to-make-a-pygame-window/

https://github.com/IanGaplichnik/42_Filler/blob/master/visualizer/vis.py

- [] Provide tests

- [] double check the makefile errors, such as no program found = no recompile make re
- [] unused variables


- [] MAKEFILE: remove -g flag from checker, push_swap, libft and ft_printf, compile so that just writing #include "push_swap.h" works

NORM:
- checker [x]
- push_swap [x]
- utilities [x]

BEST:
100: 646 - 852
500: 6084 - 7236

100: 583 - 655
500: 5018 - 5445


If a == NULL; then return 0 (0 moves for A);

find match depending on if i </> (b_size / 2), if no dst.. or always look for
the smallest that is still larger, rotate it to the top of A. In some cases,
the minimum number of moves requires inefficient rotations in stack A. For instance
if it is closer to the bottom, but the one in stack B is closer to the top relatively speaking.
The use of RR to match both to the top might be beneficial.

PA: (PB: longest increasing subsequence?)
PA: look for subchunks instead of largest to smallest, this will grant easier search,
more use of RR, RRR, SS? - look for (10) numbers? push, get them in order, rotate out
of the way to fit them in
- Push them back in general order, they will not be in perfect order until the
whole subchunk is pushed back to A.

- [ ] protect from a huge number of ints?
https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e
