# push_swap

<img width="842" alt="image" src="https://github.com/AzerSD/push_swap/assets/56733438/e2a4cc04-f1f8-4c0c-baac-4c1c81498b8b">

push_swap is a sorting algorithm based on sorting two stacks with the least amount of moves.
The allowed moves are:

* sa (swap a): Swap the first 2 elements at the top of stack a.
* sb (swap b): Swap the first 2 elements at the top of stack b.
* ss : sa and sb at the same time.
* pa (push a): Take the first element at the top of b and put it at the top of a.
* pb (push b): Take the first element at the top of a and put it at the top of b.
* ra (rotate a): Shift up all elements of stack a by 1. First becomes last.
* rb (rotate b): Shift up all elements of stack b by 1. First becomes last.
* rr : ra and rb at the same time.
* rra (reverse rotate a): Shift down all elements of stack a by 1. Last becomes first.
* rrb (reverse rotate b): Shift down all elements of stack b by 1. Last becomes first.
* rrr : rra and rrb at the same time.

>> By using these moves, the goal is to sort the numbers in stack A in ascending order, using stack B as a temporary storage.

>> This algorithm is considered to be one of the simplest sorting algorithm, but it can be quite hard to optimize it and sort a large amount of numbers with a low amount of moves.

# The Algorithm:


https://user-images.githubusercontent.com/56733438/213343838-583f273e-b108-4648-8d9c-8b2b95d1554b.mov

# ksort




