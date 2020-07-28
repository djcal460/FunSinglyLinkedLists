# FunSinglyLinkedLists
###Interactive terminal app demonstrating singly linked list computations

FunSinglyLinkedLists was developed in c language to demonstrate how a globally or locally created singly linked list can be manipulated using pointers in many many ways.
  - Enter your own elements to create a magically-numbered singly linked list
  - 18 fun fun menu options to manipulate the list
  - Menu options let you decide to use iteration, tail recurstion or head recursion
  - Repeat menu the same options to continually change the list

# Features!
Menu options include display, sum, count, find max, search (regular and improved), insert at head, insert at position, delete the entire list, check if sorted, sort, insert as sorted, delete head, delete at position, remove duplicates, reverse by elements, reverse by links, concat, and merge! Still not enough for you? Well, in addition to each feature, you will have additional choices to decide how you want the feature computed. For example, you may display the linked list by computing via iteration, tail recursion, or head recursion. 

### Tech
Tech uses the very very very advanced terminal shell and gcc compiler.

### Installation
The program comes with a swanky Makefile for you to automagically compile the .c extensions into .o binaries. Exciting? Make the file and run the file in bash.
```sh
$ make
$ ./funfunlinkedlists
```

Don't have time to type in "make"? Well, I have another solution for you...

```sh
$ gcc -I./ -o funfunlinkedlists menufunc.c llfunc.c funfunlinkedlists.c
```
