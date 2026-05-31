*This project has been created as part of the 42 curriculum by lmezzaba and lurossi.*

# Push_swap

## Description

Push_swap is an algorithmic sorting project from the 42 curriculum.

The goal is to sort a list of integers using only two stacks (`a` and `b`) and a restricted set of allowed operations. The challenge is not only to sort the numbers correctly, but also to minimize the number of generated operations.

The program receives a list of integers as input and outputs a sequence of Push_swap instructions that sorts stack `a` in ascending order.

---

# Features

* Parsing and validation of integer arguments
* Duplicate detection
* Overflow protection
* Four available sorting strategies
* Automatic adaptive strategy selection
* Benchmark mode
* Bonus checker program
* No global variables
* Full memory cleanup

---

# Compilation

Compile the mandatory program:

```sh
make
```

Compile the bonus checker:

```sh
make bonus
```

Available Makefile rules:

```sh
make
make clean
make fclean
make re
make bonus
```

---

# Usage

## Basic usage

```sh
./push_swap 3 2 1
```

Example output:

```sh
ra
sa
```

---

## Strategy selection

A strategy can be forced using one of the following flags:

```sh
--simple
--medium
--complex
--adaptive
```

Examples:

```sh
./push_swap --simple 5 4 3 2 1
./push_swap --medium 5 4 3 2 1
./push_swap --complex 5 4 3 2 1
./push_swap --adaptive 5 4 3 2 1
```

If no strategy is specified, the program automatically uses:

```sh
--adaptive
```

---

## Benchmark mode

Benchmark mode can be enabled with:

```sh
--bench
```

Example:

```sh
./push_swap --bench --adaptive 4 67 3 87 23
```

Operations are still written to stdout.

Benchmark information is written to stderr and includes:

* disorder percentage
* selected strategy
* complexity class
* total number of operations
* count of every operation

Example:

```txt
[bench] disorder: 40.00%
[bench] strategy: Adaptive
[bench] total_ops: 13
[bench] sa: 1 sb: 0 ss: 0 pa: 5 pb: 5
[bench] ra: 2 rb: 0 rr: 0 rra: 0 rrb: 0 rrr: 0
```

---

# Valid Input

Accepted:

```sh
./push_swap 4 67 3 87 23
./push_swap -10 5 0 42 -3
```

Rejected:

```sh
./push_swap 1 2 one 3
./push_swap 1 2 2 3
./push_swap 999999999999
./push_swap ""
```

Errors are reported as:

```txt
Error
```

on stderr.

If no arguments are provided, the program exits silently.

---

# Allowed Operations

| Operation | Description                        |
| --------- | ---------------------------------- |
| sa        | swap first two elements of stack a |
| sb        | swap first two elements of stack b |
| ss        | sa and sb simultaneously           |
| pa        | push top of b to a                 |
| pb        | push top of a to b                 |
| ra        | rotate a upward                    |
| rb        | rotate b upward                    |
| rr        | ra and rb simultaneously           |
| rra       | reverse rotate a                   |
| rrb       | reverse rotate b                   |
| rrr       | rra and rrb simultaneously         |

---

# Algorithms

## Simple Strategy — O(n²)

The simple strategy is intended for small inputs and nearly sorted stacks.

The algorithm repeatedly finds the minimum value in stack `a`, rotates the stack until the minimum reaches the top, and pushes it to stack `b`.

Once every element has been extracted, all values are pushed back to stack `a` in sorted order.

This strategy behaves similarly to a selection-sort adaptation and generates a quadratic number of operations.

### Complexity

* Time: O(n²)
* Space: O(1)

---

## Medium Strategy — O(n√n)

The medium strategy uses chunk sorting.

The normalized values are divided into approximately √n chunks. Elements belonging to the current chunk are progressively pushed from stack `a` to stack `b`.

After all chunks have been processed, the largest values are moved back from stack `b` to stack `a`.

This significantly reduces the number of rotations compared to the simple strategy.

### Complexity

* Time: O(n√n)
* Space: O(1)

---

## Complex Strategy

The complex strategy uses a cost-based insertion algorithm implemented in:

```c
ft_sort_everything()
```

The algorithm first pushes a portion of the elements to stack `b`.

For every remaining step, it evaluates all candidate nodes in stack `b` and computes:

* target position in stack `a`
* rotations required in stack `a`
* rotations required in stack `b`
* total movement cost

The node with the lowest cost is selected and inserted into its correct position.

Whenever possible, combined operations (`rr` and `rrr`) are used to reduce the total number of moves.

This strategy produces the best results in practice and is used for large and highly disordered inputs.

### Complexity

* Time: approximately O(n log n) in practice
* Space: O(1)

---

## Adaptive Strategy

The adaptive strategy computes the disorder of the input stack before performing any move.

Based on the measured disorder, it automatically selects one of the internal strategies.

Selection rules:

| Disorder             | Strategy |
| -------------------- | -------- |
| disorder < 0.2       | Simple   |
| 0.2 ≤ disorder < 0.5 | Medium   |
| disorder ≥ 0.5       | Complex  |

The objective is to avoid using expensive algorithms on nearly sorted inputs while still providing strong performance on random data.

---

# Disorder Metric

Disorder measures how far the input stack is from being sorted.

A value of:

```txt
0.0
```

means completely sorted.

A value of:

```txt
1.0
```

means maximally disordered.

The metric is computed as:

```txt
disorder = mistakes / total_pairs
```

where:

```txt
total_pairs = n × (n - 1) / 2
```

and a mistake is a pair:

```txt
(i, j)
```

such that:

```txt
i < j
```

and:

```txt
a[i] > a[j]
```

The disorder is always computed before any Push_swap operation is executed.

---

# Checker

The bonus checker validates a sequence of Push_swap operations.

Example:

```sh
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker $ARG
```

Expected output:

```txt
OK
```

The checker reads instructions from standard input and executes them on the provided stack.

It outputs:

```txt
OK
```

if stack `a` is sorted and stack `b` is empty.

Otherwise it outputs:

```txt
KO
```

Invalid instructions produce:

```txt
Error
```

on stderr.

---

# Performance

Typical operation counts:

## 100 random numbers

* Less than 2000 operations: pass
* Less than 1500 operations: good
* Less than 700 operations: excellent

## 500 random numbers

* Less than 12000 operations: pass
* Less than 8000 operations: good
* Less than 5500 operations: excellent

---

# Project Structure

```txt
push_swap/
├── Makefile
├── README.md
├── push_swap.h
├── main.c
├── checker.c
├── checker_helpers.c
├── ft_sort.c
├── ft_insert_sort.c
├── ft_chunk_sort.c
├── ft_execute.c
├── ft_compare.c
├── ft_fastest.c
├── ft_find.c
├── ft_find_spot_a.c
├── ft_find_spot_b.c
├── ft_position.c
├── ft_swap.c
├── ft_push.c
├── ft_rotate.c
├── ft_reverse_rotate.c
├── ft_list.c
├── ft_array.c
├── ft_checks.c
├── ft_free.c
├── ft_bench_updater.c
└── libft.c
```

---

# Resources

* 42 Subject
* Big-O Notation
* Stack Data Structures
* Sorting Algorithms
* Push_swap Community Resources
* 42 Intra Documentation

---

# AI Usage

AI tools were used as assistants for:


* documentation improvements
* benchmarking interpretation

