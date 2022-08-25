# push_swap

"This project will make you sort data on a stack, with a limited set of instructions, using
the lowest possible number of actions. To succeed you’ll have to manipulate various
types of algorithms and choose the one (of many) most appropriate solution for an
optimized data sorting."

- [ ] determine the range of each chunk, before each push: find the one that is closest
(with ra or rra)
- [ ] make a function that pushes chunks, that takes an int count argument to chose
how many chunks (this way experimenting will be a lot easier)- [ ] when pushing back chunks, check if you can save moves by not rotating, and instead pushing and doing ss
- [ ] Every check before pushing to b: check if SS, RR or RRR is useful.


- [ ] create algorithm
- [ ] protect against seg faults when doing -0, +1..
- [ ] Make radix sort but before the loop, check how many fit the thing, then stop when they have all been pushed??
- [ ] Make radix sort work with negative numbers (make them in order and positive), only call if n < some large number and k < ?
https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e
- [x] Execute moves (dispatch table? Combine functions?)
- [x] Make a circular doubly linked list? Faster to reach the last node.
- [x] Fix free_stacks to work for circular doubly linked list DONE?
- [x] Fix check_stacks to function with CDLL

- make a script that uses curl to get 500 random ints
