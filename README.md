*This project has been created as part of the 42 curriculum by mel-asla.*

# Push_swap

## Description

**push_swap** is a sorting algorithm project where the goal is to sort a stack of integers using a limited set of operations and the smallest possible number of moves.

The program takes a list of integers as arguments and outputs a sequence of instructions that will sort the numbers in ascending order using two stacks:
- **Stack A**
- **Stack B**

Only the operations allowed by the subject are used.

The sorting strategy implemented in this project is based on a **Quick Sort–inspired algorithm**, adapted and optimized to respect all the rules and constraints of the *push_swap* project.

---

## Instructions

### Compilation

To compile the mandatory part, run:

```bash
make
```

To compile the bonus part, run:

```bash
make bonus
```

### Usage

#### Mandatory (push_swap)

```bash
./push_swap <list_of_integers>
```

Example:

```bash
./push_swap 2 1 3 6 5 8
```

The program will output a list of instructions that, when executed, will sort the stack.

#### Bonus (checker)

The bonus part includes a checker program that validates the correctness of the instructions.

```bash
./checker <list_of_integers>
```

Example:

```bash
./push_swap 2 1 3 6 5 8 | ./checker 2 1 3 6 5 8
```

The checker will read instructions from standard input and verify if the stack is correctly sorted.

### Error Handling

The program handles invalid inputs, including:

- Non-numeric arguments
- Integer overflows
- Invalid characters

In case of an error, the program displays:

```
Error
```

### Algorithm

The algorithm uses stack partitioning and pivot-based decisions inspired by Quick Sort.

Several optimizations were applied to reduce the number of moves and ensure efficiency without breaking any of the push_swap rules.

### Resources

- 42 Push_swap subject
- Oceano push_swap video
- Stack-based sorting concepts
- Quick Sort algorithm principles
- Official 42 documentation

### AI Usage

AI tools were used only for:

- Understanding algorithmic concepts
- Clarifying optimization strategies
- Improving documentation clarity
