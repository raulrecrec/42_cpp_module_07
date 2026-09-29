*This project has been created as part of the 42 curriculum by rexposit.*

# CPP Module 07

`CPP Module 07` is part of the CPP modules of the 42 curriculum. The project introduces function templates, generic iteration and class templates.

Throughout the module, generic functions are created to operate on different types, arrays are traversed using templated functions, and a dynamic `Array` class is implemented using templates and deep copies.

---

# Table of Contents

- [Description](#description)
- [Project Rules](#project-rules)
- [Exercises Overview](#exercises-overview)
- [Templates Overview](#templates-overview)
- [Implementation](#implementation)
- [Compilation](#compilation)
- [Testing](#testing)
- [Project Structure](#project-structure)
- [What I Learned](#what-i-learned)
- [Author](#author)

---

# Description

CPP Module 07 is divided into three independent exercises, each focusing on a different use of templates in CPP.

### ex00 — Function Templates

Introduces three generic functions:

```cpp
swap
min
max
```

These functions can operate on any compatible type without requiring a separate implementation for each one.

The same templates can therefore be used with:

```text
int
std::string
other comparable types
```

This exercise introduces the basic syntax and behavior of function templates.

---

### ex01 — Iter

Introduces the `iter` function.

It receives:

- the address of an array;
- its length;
- a function to apply to every element.

The implementation uses templates for both the array element type and the function type.

This allows the same `iter` function to work with different arrays and with functions accepting const or non-const elements.

---

### ex02 — Array

Introduces the `Array<T>` class template.

The class manages a dynamically allocated array containing elements of any type.

It supports:

- empty construction;
- construction with a specific size;
- deep copy construction;
- deep copy assignment;
- indexed access;
- bounds checking;
- size retrieval.

The exercise combines templates with dynamic memory management, operator overloading and exceptions.

---

# Project Rules

The project follows the requirements of CPP Module 07.

- CPP98 standard
- Compilation with:

```bash
-Wall -Wextra -Werror -std=c++98
```

- Function templates
- Class templates
- Header include guards
- No STL containers or algorithms
- Dynamic allocation using `new[]`
- Proper memory management using `delete[]`
- Deep copies for dynamically allocated data
- Exception handling for invalid array access

---

# Exercises Overview

| Exercise | Main Concept | Executable |
|----------|--------------|------------|
| ex00 | Function templates | `Templates` |
| ex01 | Generic array iteration | `Iter` |
| ex02 | Class templates | `Array` |

---

# Templates Overview

CPP Module 07 introduces generic programming through templates.

```text
              Templates
                  │
        ┌─────────┴─────────┐
        │                   │
        ▼                   ▼
Function Templates     Class Templates
        │                   │
        ▼                   ▼
 swap / min / max         Array<T>
        │
        ▼
      iter
```

A template defines code using a generic type:

```cpp
template <typename T>
```

The compiler determines the concrete type when the template is used.

For example:

```cpp
Array<int>
Array<std::string>
```

both use the same `Array` implementation with different element types.

---

# Implementation

## Function Templates

Exercise 00 implements:

```cpp
swap
min
max
```

`swap` receives references so the original values can be modified.

`min` and `max` receive const references and return a const reference, avoiding unnecessary copies.

For example:

```text
swap<int>
swap<std::string>

min<int>
min<std::string>

max<int>
max<std::string>
```

The implementation does not need to know the concrete type as long as the required operations are supported.

---

## Generic Iteration

Exercise 01 implements:

```cpp
template <typename T, typename F>
void iter(T *array, const size_t len, F f);
```

`T` represents the array element type.

`F` represents the function passed to `iter`.

The array is traversed and the function is applied to every element:

```text
array[0] ──► f(array[0])
array[1] ──► f(array[1])
array[2] ──► f(array[2])
   ...
```

Using a separate template parameter for the function allows `iter` to work with different callable signatures and both const and non-const elements when compatible.

---

## Array Class

Exercise 02 implements:

```cpp
template <typename T>
class Array;
```

The class stores:

```cpp
T               *array;
unsigned int    n;
```

The constructor receiving a size allocates exactly `n` elements using:

```cpp
new T[n]
```

and the destructor releases them using:

```cpp
delete[] array;
```

---

## Deep Copy

Both the copy constructor and assignment operator perform deep copies.

A shallow copy would make two objects share the same memory:

```text
Array A ──┐
          ├──► [ elements ]
Array B ──┘
```

Instead, each object owns its own allocation:

```text
Array A ─────► [ elements ]

Array B ─────► [ elements ]
```

Changing one array therefore does not modify the other.

The assignment operator also checks for self-assignment before replacing the current allocation.

---

## Indexed Access

The subscript operator:

```cpp
T &operator[](unsigned int index);
```

returns a reference to the requested element.

This allows both reading and modifying values:

```cpp
array[0] = 42;
```

Before accessing the element, the index is checked.

If:

```cpp
index >= n
```

the operator throws:

```cpp
std::exception
```

---

## Array Size

The function:

```cpp
unsigned int size() const;
```

returns the number of elements stored in the array.

The trailing `const` guarantees that retrieving the size does not modify the object.

---

# Compilation

Each exercise is independent.

Compile any exercise by entering its directory.

Example:

```bash
cd ex00
make
./Templates
```

The other exercises can be compiled and executed with:

```bash
cd ex01
make
./Iter
```

or:

```bash
cd ex02
make
./Array
```

Available Makefile rules:

```bash
make
make clean
make fclean
make re
```

---

# Testing

The test programs verify:

- `swap`, `min` and `max` with integers;
- `swap`, `min` and `max` with strings;
- generic iteration over integer arrays;
- modification of elements through `iter`;
- iteration over string arrays;
- iteration over const arrays;
- construction of dynamic arrays;
- array size retrieval;
- indexed element access;
- deep copy construction;
- deep copy assignment;
- arrays containing different types;
- exception handling for out-of-bounds access.

Example `Array` test:

```text
Size: 5
numbers[0] = 0
numbers[1] = 10
numbers[2] = 20
numbers[3] = 30
numbers[4] = 40
```

Deep copy behavior is verified by modifying a copied array:

```text
Original: 0
Copy: 42
```

The different values confirm that both objects own independent storage.

Invalid access is also tested:

```text
Out of bounds:
Exception caught
```

Memory usage can be checked with:

```bash
valgrind --leak-check=full ./Array
```

---

# Project Structure

```text
42_cpp_module_07/
│
├── ex00/
│   ├── Templates.hpp
│   ├── main.cpp
│   └── Makefile
│
├── ex01/
│   ├── iter.hpp
│   ├── main.cpp
│   └── Makefile
│
├── ex02/
│   ├── Array.hpp
│   ├── Array.tpp
│   ├── main.cpp
│   └── Makefile
│
└── README.md
```

---

# What I Learned

Through this module I strengthened my understanding of:

- function templates;
- class templates;
- template type deduction;
- generic programming;
- passing functions to templates;
- const correctness;
- generic dynamic arrays;
- `new[]` and `delete[]`;
- deep and shallow copies;
- operator overloading in class templates;
- bounds checking;
- exception handling;
- separating template declarations and implementations using `.hpp` and `.tpp` files.

CPP Module 07 demonstrates how templates allow the same algorithms and data structures to work with different types while keeping a single reusable implementation.

---

# Author

**Raúl Expósito Campos**

42 Madrid Student

GitHub: https://github.com/raulrecrec