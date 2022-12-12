# push_swap

## sorting algorithm project with a specific set of rules

From the subject pdf: "This project will make you sort data on a stack, with a limited set of instructions, using
the lowest possible number of actions. To succeed you’ll have to manipulate various
types of algorithms and choose the one (of many) most appropriate solution for an
optimized data sorting."

### 1. The objective
Sort an unspecified number of unique integers with the help of two stacks, using a specific set of moves (or actions, described at part 5. of this README). All numbers will be placed in stack A, then sorted (most likely with the help of stack B as a temporary buffer) and placed in ascending order in stack A. Stack B must be empty when the sorting is done.

### 2. Usage

- Clone the repository
- At the root of the repository, run: make.
- This will compile two programs, called 'push_swap' and 'checker' respectively. You can run these programs with the -h flag (./checker -h) to see how to use them.
- To show a visualization of the algorithm(made with pygame (pip3 install pygame)), run: python3 viz/ps_viz.py [integer between 2-500]
#### Example:
python3 viz/pz_viz.py 200

![push_swap_200](https://user-images.githubusercontent.com/88145164/206723667-24851fe6-2c7e-44a9-8c1f-add5ec715b76.gif)

### 3. The algorithm

- Integer sets of sizes 2-5 have hard coded solutions.
- Integer sets of larger sizes are split into 12, 24 or 32 'chunks', depending on the number of integers to be sorted.
- These chunks are pushed to stack B, four at a time, starting from the two chunks with the smallest integers and the two chunks with the biggest integers. The four middle chunks are pushed last. The integers are then pushed back to stack A in order, and stack A is rotated if necessary.

### 4. The programs

### push_swap
 - takes a set of unique integers to be sorted as argument.
 - prints instructions to the standard output. These instructions sort the integers according to the rules of the project.

### checker
 - takes a set of unique integers to be sorted as argument.
 - waits for instructions (described in part 5.). Reads the instructions (divided by a newline character) from the standard input.
 - if only valid instructions are given, the checker program attempts to sort the integers.
 - if the integers are sorted, checker will print OK. If not, KO is printed.
 
#### To check that the push_swap program works correctly, pipe the output of push_swap to the input of checker
#### example:
ARGS="4 5 1 2 3"; ./push_swap $ARGS | ./checker $ARGS


### 5. The given moves (actions) are:

#### sa: swap the first two elements of stack A
#### sb: swap the first two elements of stack B

<img width="658" alt="sa_sb" src="https://user-images.githubusercontent.com/88145164/206712563-3499bf5f-c6c6-465c-96ca-1d26cbf4743d.png">

#### ss: sa and sb simultaneously

<img width="659" alt="ss" src="https://user-images.githubusercontent.com/88145164/206712801-400331e1-c3f6-4df8-b89a-f7ab26cafbd4.png">

#### pa: push a, take the first element at the top of b and put it at the top of a.

<img width="658" alt="pa" src="https://user-images.githubusercontent.com/88145164/206713079-656971cd-93b2-4672-a163-4e5785b36641.png">

#### pb: push b, take the first element at the top of a and put it at the top of b.

<img width="658" alt="pb" src="https://user-images.githubusercontent.com/88145164/206713096-3e3d0cf5-2425-47cb-b218-b7a12498a289.png">

#### ra: rotate a, shift up all elements of stack a by 1. The first element becomes
#### the last one.
#### rb: rotate b, shift up all elements of stack b by 1. The first element becomes
#### the last one.

<img width="658" alt="ra_rb" src="https://user-images.githubusercontent.com/88145164/206713462-b9e13c29-8cc3-4a7c-8cd9-afc9b14d80e8.png">

#### rr: ra and rb simultaneously.

<img width="657" alt="rr" src="https://user-images.githubusercontent.com/88145164/206713496-dcac9522-5ab6-41fc-bd99-98f1a0416540.png">

#### rra : reverse rotate a, shift down all elements of stack a by 1. The last element
#### becomes the first one.
#### rrb : reverse rotate b, shift down all elements of stack b by 1. The last element
#### becomes the first one.

<img width="658" alt="rra_rrb" src="https://user-images.githubusercontent.com/88145164/206713524-824ba68e-37f3-40c4-a0d7-e557af169d35.png">

#### rrr : rra and rrb simultaneously.

<img width="658" alt="rrr" src="https://user-images.githubusercontent.com/88145164/206713535-ffd7583f-5256-4532-bd78-0f6c550e4516.png">

