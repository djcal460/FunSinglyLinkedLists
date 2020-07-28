/*
 * Author: Derek Calzadillas
 * Purpose: To demonstrate knowledge of linked lists
 */

#ifndef __func_h__
#define __func_h__

//create structure for ll nodes
struct Node
{
    int data;
    struct Node *next;
};

struct Node *create(int[], int);
void display(struct Node *);
void recursiveTailDisplay(struct Node *);
void recursiveHeadDisplay(struct Node *);
int add(struct Node *);
int recursiveTailAdd(struct Node *);
int recursiveHeadAdd(struct Node *);
int count(struct Node *);
int recursiveTailCount(struct Node *);
int recursiveHeadCount(struct Node *p);
int maxEle(struct Node *);
int recursiveMaxEle(struct Node *);
struct Node *search(struct Node **, int);
struct Node *improvedSearch(struct Node **, int);
void insertAsHead(struct Node **, int);
int insertAtPosition(struct Node **p, int, int);
void insertLast(struct Node **, int);
void insertInSorted(struct Node *, int);
void freeList(struct Node **);
struct Node *deleteNodeAtPos(struct Node **, int);
void sort(struct Node *);
int isSorted(struct Node *);
struct Node *removeDupsInSortedList(struct Node **);
void reverseElements(struct Node *, int);
struct Node *reverseLinks(struct Node *);
int reprompt(int);
int tryagain();
int menuloop();
struct Node *globallist();
void displayMenu(struct Node *);
void sumMenu(struct Node *);
void countMenu(struct Node *);
void maxMenu(struct Node *);
void searchMenu(struct Node *);
struct Node *insertHeadMenu(struct Node *);
struct Node *insertPosMenu(struct Node *);
struct Node *freeMenu(struct Node *);
struct Node *insertSortedMenu(struct Node *);
void isSortedMenu(struct Node *);
void sortMenu(struct Node *);
struct Node *deleteHeadMenu(struct Node *);
struct Node *deleteAtPosMenu(struct Node *);
struct Node *removeDupsMenu(struct Node *);
struct Node *reverseEleMenu(struct Node *);
struct Node *reverseListMenu(struct Node *);
struct Node *concatListsMenu(struct Node *, struct Node *, char *, char *);
struct Node *sortMergeMenu(struct Node *, struct Node *, char *, char *);
struct Node *concat(struct Node *, struct Node *);
struct Node *mergeTwoSortedLists(struct Node *, struct Node *);

#endif
