# Hive-Push_swap
This project involves sorting data on a stack, with a limited set of instructions, and the smallest number of moves. To make this happen, you will have to manipulate various sorting algorithms and choose the most appropriate solution(s) for optimized data sorting.

## Objectives
This project will make you sort data on a stack, with a limited set of instructions, using
the lowest possible number of actions. To succeed you’ll have to manipulate various
types of algorithms and choose the one (of many) most appropriate solution for an
optimized data sorting.

The Push_swap project is a very simple and highly effective algorithm project: data will
need to be sorted. You have at your disposal a set of int values, 2 stacks and a set of
instructions to manipulate both stacks.

## Basic idea behind the main algorithm
Idea is to push all but three numbers to stack b at start. First pushing smallest half (index < size/2) besides the index 0. After that pushing till there is only 3 numbers left in stack: first, last and 3rd index.

Then we start main algo that calculates moves to the top of the stack where the push to other stack happens. It calculates distance_to_top of a node in stack b and then finds its next index in stack a and counts distance_to_top for that one. Smallest dist a + dist b gets stored and after whole stack b has been looped thru the smallest move gets executed.
During execution algo checks if it is possible to combine operations (ss, rr, rrr).

Do this until stack b is empty and a is already sorted because push happens only to the right place in stack a. At the end rotate stack to shortest direction till index 0 is at top.

## Allowed operations

* sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
* sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
* ss : sa and sb at the same time.
* pa : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
* pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
* ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
* rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
* rr : ra and rb at the same time.
* rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
* rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
* rrr : rra and rrb at the same time.

## Optimizing possibilities

* Find optimal cluster sizes for pushing to stack b at start.
* Check rr/rrr possibilities already during finding next move.
* Implement sa/sb/ss to the main algo.
* Running operations thru multiple algorithms and choosing the best to be executed.

## How to use

```git clone https://github.com/MikeyLHolm/Hive-Push_swap.git```

In project folder: ```make```


Running program: ```./push_swap 1 5 7 9 4 2```

PS + CH: ```ARG="1 5 2 4 3"; ./push_swap $ARG | ./checker $ARG```


RNG generator: ```ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"` ; time ./push_swap $ARG | wc -l```


Python visualizer by [Emmanuel Ruaud](https://github.com/o-reo)

To use (remove []): ```[python3 pyviz.py `ruby -e "puts (1..100).to_a.shuffle.join(' ')"`]```

## Grade
**118 / 100**

_Completed 6.3.2020_
