# Stacks:

Stack is a Data Structure that follows the first in last last out, FILO or LIFO, principle.

**Considering the following operations:**

- push(1)
- push(2)
- push(3)
- push(4)
- pop()
- pop()
- size()

For the above set of Instructions the following are returned in the given order:

- [1] ==> [2,1] ==> [3,2,1] ==> [4,3,2,1]  *Index 0 is the top element in every iteration of the given expression* 
- [4,3,2,1] ==> [3,2,1]

Size of the stack at the end of all operations will be **3**

*The **top** or **peek** function allows us to see the topmost or last inserted element of the stack*



## Implementation of Stack:

The Code for Implementation of Stack in C can be found here:

- [Stack Implemented in C](Stack.c)
- [Another advanced implementation of Stack](Stack2.c)

### Steps of implementing stack:

- Initialize the size of the stack, say n.
- Declare an array of size **n**.
- When the **array is empty** make a top a variable and make it's value as **-1**.
- Insert element at 0th index of the array when insert function is called and update the value of top. Insert rest of the elemnts accordingly in the standard way of inserting in an array.
- Every time an element is inserted the value of top is updated to the index where the last element is present. **top + 1** is also the size of the array.
- If **top == n-1** then no more values can be inserted into the Stack.
- When, the pop is called, i.e. an element is to be removed, top needs to be taken an idex back. If the value of top is -1, a check should be placed on it so that it can not be taken back further.