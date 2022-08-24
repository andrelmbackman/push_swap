# push_swap

"This project will make you sort data on a stack, with a limited set of instructions, using
the lowest possible number of actions. To succeed you’ll have to manipulate various
types of algorithms and choose the one (of many) most appropriate solution for an
optimized data sorting."

- [X] finds destined next and prev
- [ ] create algorithm
- [ ] protect against seg faults when doing -0, +1..
- [ ] Make radix sort but before the loop, check how many fit the thing, then stop when they have all been pushed??
- [ ] Make radix sort work with negative numbers (make them in order and positive), only call if n < some large number and k < ?
https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e
- [x] Execute moves (dispatch table? Combine functions?)
- [x] Make a circular doubly linked list? Faster to reach the last node.
- [x] Fix free_stacks to work for circular doubly linked list DONE?
- [x] Fix check_stacks to function with CDLL
- [ ] for size 5, find index of smallest, find if you should ra or rra, then pb.
do the same with the next smallest, pb. Then solve 3, then pa pa. (max 10), perfect = 8
(find the minimum move to move the two smallest to b, then see if ss is an option?)

- make a script that uses curl to get 500 random ints
