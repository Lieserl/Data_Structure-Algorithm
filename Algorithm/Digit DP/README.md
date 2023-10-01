# Basic Knowledge about Digit Dynamic Programming

*Digit DP* utilizes the concept of prefix sums, first we calculate the numbers in (0, r), and then (0, l - 1), finally we subtract them to get the answer.

There are two ways to implement *Digit DP*, iterative and recursive.

## Iterative Approach

Let's start from a picture.

![](Explanation%20of%20iterative%20method.png)

In this image, we can visually see the specific process of the iterative method. So let's go through each step for a better understanding of iterative implementation.

1. First, we can select a number to fill $a_{n-1}$ digit, and we have two ways(left & right branch):
> 1. Fill it with a number from $0$ to $a_{n-1} - 1$. In this case, since we do not reach the limit, we can choose any number to fill the last $a_{n-2}$ positions, which can be relatively easily obtained through pre-processed DP.
> 2. Fill it with $a_{n-1}$. In this case, we find it hard to get a pre-processed Array, since the remaining digits are restricted by $a_{n-2}$ $a_{n-3}$ ... $a_0$. So we can go staight to the next loop. One thing need to mention: If $a_{n-i}$ does not satisfy the given restriction, we can just break and end the iteration, Because the later steps all based on the reality that we fill $a_{n-i}$ digit with $a_{n-i}$.

2. After we end the iteration, we need to handle with the special situation, for example, if given restriction asks us not to take leading zero into consideration or our iteration has reached the final step (fill $a_0$ digit with $a_0$)

## Recursive Approach