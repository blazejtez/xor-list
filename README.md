## Overview

A double-linked XOR list implementing a FIFO queue. More on XOR list [here](https://en.wikipedia.org/wiki/XOR_linked_list) and [here](https://www.geeksforgeeks.org/xor-linked-list-a-memory-efficient-doubly-linked-list-set-1/)

This project originally was a task for Algorithms and Data Structures course at Gdansk University of Technology, back in 2021. Since then I decided to translate code to English,
rewrite it for C++20 standard, use object oriented approach and let the code be more reusable thanks to templates. Original project requirements are listed in [original requirements section](##Original-requirements-section) at the end of the file.

## Original requirements section

The task is to implement FIFO queue using doubly or singly linked list. It is an extension of XOR linked list assignment XOR linked list and the list implemented for that assignment can be reused; but also an STL <list> list can be used.
In addition to the functions of the XOR list (ADD_BEG, ADD_END, DEL_BEG, DEL_END, PRINT_FORWARD, PRINT_BACKWARD) from the XOR list assignment XOR linked list the list implements:

SIZE - liczba elementów listy.
The queue is a data structure that uses list and provides functions corresponding to the following commands:

PUSH N - add element N to the end of the queue.
POP - remove the first element from the queue.
PRINT_QUEUE - print the queue from the first element to the lastly added.
COUNT - the number of elements in queue ≤ SIZE.
GARBAGE_SOFT - change the values of all elements of the list that do not belong to the queue to 0.
GARBAGE_HARD - remove all elements from the list that does not belong to the queue.
The FIFO queue extends the list to the pointers to the beginning (FRONT) and the end (BACK) of the queue. After inserting an element to the queue the pointer to the end of the queue (BACK) has to be changed so it will point to the next element of the list. After removing an element from the queue (FRONT) pointer has to start pointing at the element after the previously pointer by (FRONT). Notice, that by both removing and adding the element the queue has to “follow the list”. To avoid memory loss and to be able to reuse one can use a cyclical list or after reaching the end of the queue start from the beginning. Also, one has to handle exceptions: inserting an element to an empty queue (no elements), adding elements to full list (the number of elements of the queue equal to the number of elements of the list), or trying to remove elements from an empty queue.
When the list is empty (no elements in it) the pointers point to nullptr. When adding an
