# C Data Structure

Hi There,<br/>
This is my implementation of data structures using C Programming Language.<br/>
I develop it to fill my github repo ;p and also to develop my C Programming's skill.

It's been build and tested by me on my PC (5.2.8-arch1-1-ARCH #1 SMP PREEMPT x86_64 GNU/Linux)<br/>
You just need to run make on root diretory of this repo.
Two binary version will be build which are debug and release version.
Binary files is made inside bin directory which will be created after you run make.

By sharing this project to public I hope, Public may get benefit from it.


## Data Structure
Currently I'm developing these following data structures 
- [Single Linked List](https://github.com/ipgdbali/c-data-structure/blob/master/README.md#single-linked-list)
- [Single Linked List Iterator](https://github.com/ipgdbali/c-data-structure/blob/master/README.md#single-linked-list-iterator) dependencies [Single Linked List](https://github.com/ipgdbali/c-data-structure/blob/master/README.md#single-linked-list)
- [Sorted List](https://github.com/ipgdbali/c-data-structure/blob/master/README.md#sorted-list) dependencies [Single Linked List Iterator](https://github.com/ipgdbali/c-data-structure/blob/master/README.md#single-linked-list-iterator)

### Single Linked List
Single Linked List is a way to store data in list favor.<br/>
You can insert data into it without have to worry about its capacity or wasted memory.<br/>
To gain its behavior,Single linked list is implemented as chain of node.<br/>
In A Single Linked List,each single node contains of data and a pointer to next node.<br/>
You may think it as a train where it's a chain of coaches instead of nodes<br/>
If node doesn't have succeeding node then, pointer to next node in this node is NULL
This last node is known as TAIL NODE.<br/>
Whereas the first node that does not have preceeding node is called HEAD NODE.

To push data into Linked List, we may push it before head (we call it prepend) or
append after tail .<br/>
To remove data in a Linked List, we may only remove the head node,and pointing head node to succeeding node.
This operation is called pop<br/>

By using this operations we can implement data structure queue and stack.

Please look [header/single_linked_list.h](https://github.com/ipgdbali/c-data-structure/blob/master/header/single_linked_list.h) to have more detailed function of my single linked list implementation

### Single Linked List Iterator
Iterator allows you to visit each node from Head Node to Tail Node.
Reseting Iterator means you move iterator to Head Node.
for each iterator, next function is called to progress iterator to next node.

Please look header/single_linked_list_iterator.h
### Sorted List
While inserting new item into list,
Sorted list will place the new item with left node < new node < right node.
So when you iterate,you will get your list sorted.

Please look at header/sorted_list.h for more info

