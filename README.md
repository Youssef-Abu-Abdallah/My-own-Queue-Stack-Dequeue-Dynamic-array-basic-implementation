# Data Structures Implementation: Queue, Stack, Dynamic Array, and Doubly Linked List 

![C++](https://img.shields.io/badge/C++-17%2F20-blue.svg)


This repository provides a C++ implementation of fundamental data structures. All structures are implemented with **doubly linked list** once and with **dynamic array** once, implementations for key abstract data types.

## Features

- **Core Data Structures**:
  - ✅ **Queue** (FIFO): Implemented via doubly linked list (`clsMyQueue.h`) and dynamic array (`clsMyQueueArr.h`)
  - ✅ **Stack** (LIFO): Implemented via doubly linked list (`clsMyStack.h`) and dynamic array (`clsMyStackArr.h`)
  - ✅ **Dynamic Array**: Resizable array implementation (`clsDynamicArray.h`)
  - ✅ **Doubly Linked List**: Bidirectional node-based structure (`clsDblLinkedList.h`)

- **Advanced Application**:
  - 🔄 **Undo/Redo System**: Practical implementation using stack-based command pattern in `main.cpp` and the implementaion is in (`clsMyString.h`)


- **Design Highlights**:
  - Strict separation of concerns (each structure in its own header file)
  - Template-based implementation for type flexibility
  - Comprehensive documentation in headers
  - No external dependencies

