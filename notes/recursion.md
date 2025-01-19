# Recursion

## What is recursion?
* A function that calls itself during its execution
* Useful for solving problems that can be broken down into smaller, similar subproblems.

## How it works
1. Base case: stops the recursion to prevent infinite calls
2. Recursive case: function calls itself with smaller input

## Key Concepts
1. Call Stack:
    * each recursive call adds a new frame to the stack
    * the stack unwinds once the base case is reached
2. Examples:
    * factorial of a number
    * fibonacci sequence
    * tower of hanoi

## Advandages
* Simpler code for complex problems, recursion simplifies problems that naturally fit into a divide-and-conquer paradigm
* Readable and Elegant, recursive solutions are often more concise compared to iterative solutions
* Natural fit for recursive data structures like trees and graphs

## Disadvantages
* Performance overhead: each call adds a frame to the call stack, which includes function parameters, return address, and local variables, so for deep recursion, this can significantly affect performance compared to iterative solutions
* Risk of Stack Overflow: if recursion depth exceeds the stack size, it leads to a stack overflow error
* Difficult to debug, cause it's harder to keep track of the stack's state
* Memory Usage: recursion consumes more memory, so it is less memory-efficient for problems with large input sizer 

## Performance and Memory Considerations
1. Function call overhead
    * each recursive call requires additional operations: saving the current state (local variables, return address), setting up the environment for the new function call
2. Call stack and memory usage
    * for every recursive call, a new frame is pushed onto the stack, the stack is unwound once the base case is reached
    * iterative solutions avoid this by maintaining state in local variables
3. Tail recursion optimization
    * some compilers (gcc, clang) can optimize tail recursion, converting recursion into iteration internally
4. Iterative vs Recursive

```c
int factorial_recursive(int n) {
    if (n == 0) return 1;
    return n * factorial_recursive(n - 1);
}
```

memory: stack space proportional to n

```c
int factorial_iterative(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}
```

memory: contant space O(1)

## When to Use Recursion
* When the problem is naturally recursive (e.g., tree traversal).
* When readability and simplicity are more important than performance.
* For problems where iterative solutions would be complex and error-prone.

## When to Avoid Recursion
* When performance and memory efficiency are critical.
* For problems with very large input sizes that could cause stack overflow.
* When an iterative solution is straightforward and more efficient.
