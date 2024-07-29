## What is Linked List and how is it different from array:

Arrays are blocks of contiguous data, that stores all the data in continuous locations of the heap, while in linked list, each data is stored in a separate location and contains a link to the location of the next data.

Also, while native arrays are static, linked lists are dynamic and can be extended without limit i.e. until the memory runs out.

## Application of LinkedList in RealLife:

- Web Browsers: Connectivity of tabs implemented using a doubly linked list.
- Intelinking of Directories in a Computer.
- GPS navigation system (it uses graphs actually, but almost the same concept).

## Every LinkedList has 2 main parts:

1. The **data**: int, double, float whatever.

2. **Pointer**: A pointer that points to the address of the next data (called node) .

Since there is no data type to store such a data, we need to define our custom data type for it. A data type called Node, like the one mentioned below.



## Creating a Node:

```cpp
struct Node{
    int data;
    Node* next;

// constructor
    Node(int d, Node n){
        data = d;
        next = n;
    }

}
```
