*This project has been created as part of the 42 curriculum by lmezzaba.*

# push_swap

## Description

`push_swap` sorts a list of integers using two stacks named `a` and `b` and the official Push_swap operations: `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, and `rrr`.

The first argument is treated as the top of stack `a`. The program prints only the operations needed to sort stack `a` in ascending order, with the smallest value at the top. Invalid input prints `Error` on standard error.

## Instructions

Compile the mandatory program:

```sh
make
```

Compile the checker bonus:

```sh
make bonus
```

Clean object files:

```sh
make clean
```

Remove binaries and object files:

```sh
make fclean
```

Rebuild:

```sh
make re
```

Run examples:

```sh
./push_swap 4 67 3 87 23
./push_swap --simple 5 4 3 2 1
./push_swap --medium 5 4 3 2 1
./push_swap --complex 5 4 3 2 1
./push_swap --adaptive 5 4 3 2 1
./push_swap --bench --adaptive 5 4 3 2 1
```

Verify with the checker:

```sh
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker $ARG
```

## Strategies

### Simple strategy: O(n^2)

The simple strategy uses a selection-style stack algorithm. It repeatedly brings the smallest element of stack `a` to the top, pushes it to `b`, and then pushes all elements back to `a`. It is easy to reason about and is useful for low-disorder or small inputs.

### Medium strategy: O(n sqrt(n))

The medium strategy uses chunk sorting. The input is divided into approximately `sqrt(n)` sized ranges. Elements are pushed from `a` to `b` chunk by chunk, then the biggest element in `b` is repeatedly brought to the top and pushed back to `a`.

### Complex strategy: O(n log n)

The complex strategy uses binary radix sorting on normalized indexes. Since each number is replaced by its sorted rank, radix can process the stack bit by bit. For every bit pass, values with bit `0` are pushed to `b`, values with bit `1` are rotated in `a`, then `b` is pushed back to `a`.

### Adaptive strategy

The adaptive strategy first computes the disorder ratio by counting inverted pairs before any move is made.

- If disorder is lower than `0.2`, it uses the simple strategy.
- If disorder is between `0.2` and `0.5`, it uses the medium strategy.
- If disorder is at least `0.5`, it uses the complex radix strategy.

This keeps nearly sorted inputs simple while still using radix for highly disordered inputs.

## Benchmark mode

`--bench` prints metrics to standard error only. The operation stream remains on standard output and can still be piped into the checker.

Benchmark output includes:

- disorder percentage
- selected strategy and complexity class
- total operation count
- count of every operation type

## Resources

- 42 Push_swap subject
- 42 Norm
- Big-O notation references
- Stack-based sorting algorithm references
- Radix sort references

AI was used to help with repetitive refactoring, organization, and documentation drafting.
