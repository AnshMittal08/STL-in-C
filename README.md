# C Standard Template Library (STL) Implementation

This project is a comprehensive implementation of various Standard Template Library (STL) data structures, algorithms, and utility functions in the C programming language. It provides reusable, efficient, and easy-to-use data structures, allowing developers to work with STL-like features in C.

## Table of Contents

- [Features](#features)
- [Data Structures Implemented](#data-structures-implemented)
- [Algorithms Implemented](#algorithms-implemented)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Examples](#examples)
- [Testing](#testing)
- [Contributing](#contributing)
- [License](#license)

## Features

- **Reusable Code**: All data structures are implemented as libraries with clear and reusable interfaces.
- **Dynamic Memory Management**: Supports dynamic memory allocation and resizing where applicable.
- **Error Handling**: Proper error handling and boundary checking to ensure robustness.
- **Header-Based**: Each data structure is provided as a header file for easy integration.
- **Well-Documented**: Functions are documented with their purpose, parameters, and return types.
- **Comprehensive Coverage**: Implements a wide range of data structures and algorithms similar to C++ STL.

## Data Structures Implemented

1. **Dynamic Array (Vector)**
   - Supports dynamic resizing, insertion, deletion, and access.
   - Provides a versatile array that grows as needed.

2. **Linked List**
   - **Singly Linked List**: Basic linked list operations (insert, delete, search).
   - **Doubly Linked List**: More flexible linked list operations allowing bidirectional traversal.
   - **Deque**: Double-ended queue implemented using a doubly linked list, allowing insertion and deletion from both ends.

3. **Stack**
   - Implemented using both arrays and linked lists.
   - Supports standard stack operations like `push`, `pop`, `peek`, and `size`.

4. **Queue**
   - Implemented using both arrays and linked lists.
   - Supports standard queue operations like `enqueue`, `dequeue`, `front`, `rear`, and `size`.

5. **Priority Queue (Min Heap and Max Heap)**
   - **Min Priority Queue**: Implements a Min Heap for priority queue operations.
   - **Max Priority Queue**: Implements a Max Heap for priority queue operations.
   - Supports operations like `insert`, `extract-min/max`, `heapify`, and `peek`.

6. **Heap**
   - **Min Heap** and **Max Heap** implementations.
   - Supports operations like `insert`, `extract-min/max`, `heapify`, and building a heap from an array.

7. **Binary Tree**
   - Basic binary tree implementation with insertion, traversal, and deletion operations.

8. **Binary Search Tree (BST)**
   - Supports operations like `insert`, `delete`, `search`, and various traversal methods (in-order, pre-order, post-order).

9. **Hash Map**
   - Provides a hash table with chaining for collision resolution.
   - Supports standard operations like `insert`, `delete`, `search`, and `rehash`.

10. **Set**
    - Implements a set data structure using a hash table for fast lookups, insertions, and deletions.
    - Supports operations like `insert`, `remove`, `contains`, and `union`.

11. **Deque**
    -Deque: Double-ended queue implemented using a doubly linked list, allowing insertion and deletion from both ends.

## Algorithms Implemented

- **Sorting Algorithms**
  - Implements various sorting algorithms such as Bubble Sort, Insertion Sort, Quick Sort, Merge Sort, and Heap Sort.

## Getting Started

To use these data structures and algorithms in your project, clone this repository and include the relevant header files in your source files.

### Prerequisites

- GCC (GNU Compiler Collection) or any standard C compiler.
- Make (optional).

### Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/yourusername/c-stl-implementation.git
   cd c-stl-implementation

2. Compile the source code:

    ```bash 
    gcc -o test_program src/*.c tests/*.c

3. Run the test program:

    ```bash 
    ./test_program

### Contributing
Contributions are welcome! If you have any ideas, suggestions, or improvements, feel free to open an issue or submit a pull request.

- Fork the repository.
- Create a new branch (git checkout -b feature-branch).
- Commit your changes (git commit -m 'Add some feature').
- Push to the branch (git push origin feature-branch).
- Open a pull request.

### License
This project is licensed under the MIT License - see the LICENSE file for details.
