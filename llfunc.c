/*
 * Author: Derek Calzadillas
 * Purpose: To demonstrate knowledge of linked lists
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "func.h"

struct Node *head = NULL;
int flag = 1;

struct Node *create(int a[], int n)
{

    //t for new nodes, last for last nodes
    struct Node *t, *last;

    //set up the head ptr the ll
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = a[0];
    head->next = NULL;
    last = head; //last also pts to head

    //build list by moving last ptr to new node through each iter
    for (int i = 1; i < n; i++)
    { //0 is the head node
        //set up new node number i
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = a[i];
        t->next = NULL;
        last->next = t; //prev node's next pts to new node
        last = t;       //last ptr pts to new node (now last)
    }
    return head;
} //end create

void display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next; //when null, at end
    }
    printf("\n");
}

void recursiveTailDisplay(struct Node *p)
{
    if (p != NULL)
    {
        printf("%d ", p->data); //operation ascending
        recursiveTailDisplay(p->next);
    }
}

void recursiveHeadDisplay(struct Node *p)
{
    if (p != NULL)
    {
        recursiveHeadDisplay(p->next);
        printf("%d ", p->data); //operation decending
    }
}

int add(struct Node *p)
{
    printf("You Chose Iterative Addition:\n");
    int sum = 0;
    while (p)
    {
        sum = sum + p->data;
        p = p->next; //move p to next ptr until null
    }
    return sum;
}

int recursiveTailAdd(struct Node *p)
{
    //print this only once
    if (flag)
    {
        printf("You Chose Tail Recursion Addition:\n");
        flag = 0;
    }
    if (p == 0)
        return 0;
    else
    {
        return p->data + recursiveTailAdd(p->next); //operation ascending
    }
    //if p back to head, recursion is finished
    if (p == NULL)
    {
        printf("\n");
        flag = 1;
    }
}

int recursiveHeadAdd(struct Node *p)
{
    //print this only once
    if (flag)
    {
        printf("You Chose Head Recursion Addition:\n");
        flag = 0;
    }
    if (p == 0)
        return 0;
    else
    {
        return recursiveHeadAdd(p->next) + p->data; //operation decending
    }
    //if p back to head, reset flag
    if (p == NULL)
    {
        printf("\n");
        flag = 1;
    }
}

int count(struct Node *p)
{
    int c = 0;
    while (p)
    {
        c = c + 1;
        p = p->next; //move to next node
    }
    return c;
}

int recursiveTailCount(struct Node *p)
{
    //print this only once
    if (flag)
    {
        printf("You Chose Head Recursion Count:\n");
        flag = 0;
    }
    if (p == 0)
        return 0;
    else
        return 1 + recursiveTailCount(p->next); //operation ascending
    if (p == NULL)
    {
        printf("\n");
        flag = 1;
    }
}

int recursiveHeadCount(struct Node *p)
{
    //print this only once
    if (flag)
    {
        printf("You Chose Head Recursion Count:\n");
        flag = 0;
    }
    if (p == 0)
        return 0;
    else
        return recursiveHeadCount(p->next) + 1; //operation decending
    if (p == NULL)
    {
        printf("\n");
        flag = 1;
    }
}

int maxEle(struct Node *p)
{
    printf("You Chose Iteration Find Max Element:\n");
    //smallest for signed int
    int m = INT_MIN;
    while (p)
    {
        if (p->data > m) //head go, this should be true
            m = p->data;
        p = p->next; //next node
    }
    return m;
}

int recursiveMaxEle(struct Node *p)
{
    //print this only once
    if (flag)
    {
        printf("You Chose Recursion Find Max Element:\n");
        flag = 0;
    }
    int x = 0;
    if (p == 0)
        return INT_MIN; //set MIN at end of list
    else
    {
        x = recursiveMaxEle(p->next); //will go to end of list, set to MIN above
        if (x > p->data)              //as comes back will do this code (MIN > 12)
            return x;
        else
            return p->data; //will return this to x if current x is smaller
    }
    if (p == NULL)
    {
        printf("\n");
        flag = 1;
    }
}

//linear search
struct Node *search(struct Node **p, int key)
{
    struct Node *temp = *p;
    //while p is not null
    while (*p)
    {
        if (key == (*p)->data)
        {
            printf("Key Found: %d\n", key);
            return temp;
        }
        *p = (*p)->next; //next node
    }
    return NULL;
}

//improved search moves searched item to head
struct Node *improvedSearch(struct Node **p, int key)
{
    struct Node *temp = *p;
    //move to head need a tail ptr to follow p
    struct Node *q = *p;

    while (p)
    {
        //if we find the key
        if (key == (*p)->data)
        {
            q->next = (*p)->next; //p's next becomes q's next
            (*p)->next = temp;    //head becomes p's next
            temp = (*p);          //p becomes the head
            printf("Key found: %d.\n", key);
            return (*p);
        }
        q = (*p);          //make sure q is tailing p before change
        (*p) = (*p)->next; //move p to next node
    }
    return NULL;
}

void insertAsHead(struct Node **p, int d)
{

    //create new node using temp ptr (will be moved to head later)
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));

    //assign whatever data was passed
    t->data = d;
    t->next = *p; //t's next is going to pt to current head (link it)
    *p = t;       //t's node is now the head
}

int insertAtPosition(struct Node **p, int d, int index)
{

    //create new node using temp ptr (will be inserted) and assign data passed
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    //preserve head p
    struct Node *tt = *p;
    t->data = d;
    int c = count(*p); //count indicies
    for (int i = 0; i < index - 1; i++)
    {
        //traverse p from head node to one node before target index
        if (tt && index < c + 1)
        {
            tt = tt->next; //(e.g if you want it to be 4th node, insert after 3 traversals)
        }
        else
        {
            return 0; //out of bounds
        }
    }
    //t's next pt to tt's next (to keep link)
    t->next = tt->next;
    //tt's next pt to t (for insert at head)
    tt->next = t;
    return 1; //in bounds and successful
}

//can use to create new list too
void insertLast(struct Node **h, int d)
{ //here we are picking up a pointer to a pointer from caller

    //create new node to insert at end
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = d;
    t->next = NULL;

    //create last ptr
    struct Node *last;

    //if *h (pointer to pointer) is not pt'ing to anything
    if (*h == NULL)
    {
        *h = last = t; //new node is assigned to last, and *h
        //can look, but need to dereference *h first to access its struct
        //printf("*h is being assigned: %d\n",(*h)->data);
    }
    else
    {
        //last will equal head, traverse it to the end
        last = *h;
        while (last->next)
        { //when last->next is NULL we are at end
            last = last->next;
        }

        last->next = t; //last->next points to new node
        last = t;       //last now also points to new node (t and last pt to new node)
    }
}

void insertInSorted(struct Node *p, int x)
{

    //need to tail p when find insert
    struct Node *q = NULL;

    //traverse until p's data < x (want to insert before this node that p will point to)
    while (p && p->data < x)
    {
        q = p; //q will tail p (want to insert after q)
        p = p->next;
    }

    //assign new node to p with data (since where p is pting is no longer important)
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = x;

    //want to insert new node p after q
    p->next = q->next; //p's next (new node) pts to q's next
    q->next = p;       //q's next now pts to p (new node)
}

void freeList(struct Node **p)
{
    struct Node *tmp;
    while (*p != NULL)
    {
        tmp = *p;
        *p = (*p)->next;
        free(tmp);
    }
}

struct Node *deleteNodeAtPos(struct Node **p, int pos)
{
    struct Node *t = *p; //temp head
    struct Node *q;

    //if insert at head
    if (pos == 1)
    {
        *p = t->next; //move p to pt to next node
        free(t);      //delete t node at pos 1
    }
    else
    {
        //traverse t to one before the position
        q = NULL;
        for (int i = 0; i < pos - 1; i++)
        {
            q = t; //q tails t
            t = t->next;
        }

        if (t)
        {
            q->next = t->next; //link q's next to t's next
            free(t);
        }
        t = *p;
    }
    return t;
}

void sort(struct Node *p)
{

    int x;
    struct Node *sorted;
    struct Node *temp;

    for (sorted = p; sorted != NULL; sorted = sorted->next)
    {
        for (temp = sorted->next; temp != NULL; temp = temp->next)
        {
            if (temp->data < sorted->data)
            {
                x = sorted->data;
                sorted->data = temp->data;
                temp->data = x;
            }
        }
    }
}

int isSorted(struct Node *p)
{
    int x = INT_MIN;
    while (p)
    {
        //if p's data is ever < x then not sorted
        if (p->data < x)
            return 0;
        x = p->data; //cur p data to x
        p = p->next; //move p next node
    }
    return 1; //if passes above, it is sorted
}

struct Node *removeDupsInSortedList(struct Node **p)
{
    //q one node ahead of p
    struct Node *t = *p;
    struct Node *q = (*p)->next;
    while (q)
    {
        //if data aren't equal
        if ((*p)->data != q->data)
        {
            *p = q;      //p jumps ahead one to q node
            q = q->next; //q jumps ahead one to its next node
        }
        else
        {
            //data are equal
            (*p)->next = q->next; //p next jumps over to q's next (two nodes ahead)
            free(q);              //delete q node from list
            q = (*p)->next;       //q is now one ahead of p
        }
    }
    return t;
}

//reverse elements (values switch addresses **not preferred)
void reverseElements(struct Node *p, int size)
{
    struct Node *q = p;
    int a[size];

    int i = 0;
    while (p)
    {
        //add each list data to element of array
        a[i] = p->data;
        p = p->next;
        i++;
    }
    i--; // because i gets incremented after p is null in loop above

    while (q)
    {
        q->data = a[i--];
        q = q->next;
    }
}

struct Node *reverseLinks(struct Node *p)
{
    //sliding ptrs (r->q->p->)
    struct Node *q = NULL, *r = NULL;

    //move all ptrs forward each iter r(null)->q(null)->p(val,next)
    while (p)
    {
        r = q;       //r pts to q
        q = p;       //q pts to p
        p = p->next; //p pts to next node
        //r is at the
        q->next = r;
    }
    p = q;
    return p;
}

struct Node *concat(struct Node *one, struct Node *two)
{

    //traverse p to end of list one
    struct Node *p = one;
    while (p->next)
    {
        p = p->next;
    }

    p->next = two;

    return one;
}

struct Node *mergeTwoSortedLists(struct Node *list1, struct Node *list2)
{

    //check heads: last ptr and third ptr point to smallest head
    struct Node *last, *third;
    if (list1->data < list2->data)
    {
        third = last = list1;
        list1 = list1->next; //move list1 to pt to next node
        last->next = NULL;   //smallest head's next get assigned null
    }
    else
    {
        third = last = list2;
        list2 = list2->next; //move list2 to pt to next node
        last->next = NULL;   //smallest head's next get assigned null
    }

    //SHOW ONE ITER OF THIS LOGIC FROM SITUATION 1
    //Situation1: last/third->(1stNode)-x>list1(2ndNode)  && list2->(1stNode)
    //Situation2: last/third->(1stNode)-x>list2(2ndNode)  && list1->(1stNode)
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->data < list2->data)
        {                        //list1 ptr is less
            last->next = list1;  //Situation1: last/third->(1stNodeL1)->list1(2ndNodeL1)  && list2->(1stNodeL2)
            last = list1;        //Situation1: third->(1stNodeL1)->last/list1(2ndNodeL1)  && list2->(1stNodeL2)
            list1 = list1->next; //Situation1: third->(1stNodeL1)->last(2ndNodeL1)-x>list1->(3rdNode)  && list2->(1stNodeL2)
            last->next = NULL;   //Situation1: third->(1stNodeL1)->last(2ndNodeL1)-NULL-x>list1->(3rdNodeL1)  && list2->(1stNodeL2)
        }
        else
        {
            last->next = list2;  //Situation1: last/third->(1stNodeL1)->list2->(1stNodeL2) && list1->(2ndNodeL1)
            last = list2;        //Situation1: third->(1stNodeL1)->last/list2(1stNodeL2)  && list1->(2ndNodeL1)
            list2 = list2->next; //Situation1: third->(1stNodeL1)->last->(1stNodeL2)-x>list2(2ndNodeL2)  && list1->(2ndNodeL1)
            last->next = NULL;   //Situation1: third->(1stNodeL1)->last->(1stNodeL2)-NULL-x>list2(2ndNodeL2)  && list1->(2ndNodeL1)
        }
        //third will be head, ptr last will be last in merge chain, list1/list2 will be ahead comparing eachother to see where last will pt.
    }

    //at the end, one list will not be NULL, connect last->next to pt to it b/c it's the last node
    if (list1)
        last->next = list1;
    else
        last->next = list2;

    return third;
}

int reprompt(int flag)
{
    int fixin, input, ret = 0;
    if (flag == 1)
    { //check valid size
        while (ret != 1 || input > INT_MAX || input < 1)
        {
            printf("Enter a valid size: ");
            while ((fixin = getchar()) != EOF && fixin != '\n')
                ; // fix stdin
            fflush(stdin);
            ret = scanf("%d", &input);
        }
    }
    else if (flag == 2)
    { // check valid int
        while (ret != 1 || input > INT_MAX)
        {
            printf("Enter a valid integer: ");
            while ((fixin = getchar()) != EOF && fixin != '\n')
                ; // fix stdin
            fflush(stdin);
            ret = scanf("%d", &input);
        }
    }
    else if (flag == 3)
    { // check valid option 1-3
        while (ret != 1 || input > 3 || input < 1)
        {
            printf("\nEnter a valid option 1,2,3: ");
            while ((fixin = getchar()) != EOF && fixin != '\n')
                ; // fix stdin
            fflush(stdin);
            ret = scanf("%d", &input);
        }
    }
    else if (flag == 4)
    { // check valid option 1-2
        while (ret != 1 || input > 2 || input < 1)
        {
            printf("Enter a valid option 1,2: ");
            while ((fixin = getchar()) != EOF && fixin != '\n')
                ; // fix stdin
            fflush(stdin);
            ret = scanf("%d", &input);
        }
    }
    else if (flag == 5)
    { // check valid option 1-18
        while (ret != 1 || input > 19 || input < 1)
        {
            printf("Enter a valid option 1-19: ");
            while ((fixin = getchar()) != EOF && fixin != '\n')
                ; // fix stdin
            fflush(stdin);
            ret = scanf("%d", &input);
        }
    }

    return input;
}

int tryagain()
{
    int prompt, ret;
    printf("Press [Any Key][Enter] to Repeat or [1] to Return to Menu: ");
    ret = scanf("%d", &prompt);
    if (prompt != 1 || ret != 1)
        return 0;
    return 1; //if 1, continue loop
}

int menuloop()
{
    int prompt, ret;
    printf("Press [Any Key][Enter] for New Menu Item or [1] to Exit Program: ");
    ret = scanf("%d", &prompt);
    if (prompt != 1 || ret != 1)
        return 0;
    return 1; //if 1, continue loop
}

struct Node *globallist()
{
    struct Node *t = NULL;
    //prompt user
    int input, size, ret;
    printf("\nEnter the size of desired global linked list: ");
    ret = scanf("%d", &size);
    if (size < 1 || size > INT_MAX || ret != 1)
    {
        size = reprompt(1); //1 flag for size
    }
    int arr[size];
    printf("Enter an integer for each element of the linked list.\n");
    for (int i = 0; i < size; i++)
    {
        printf("Please enter an integer: ");
        ret = scanf("%d", &input);
        if (ret != 1 || input > INT_MAX)
        {
            input = reprompt(2); //2 flag for int only
        }
        arr[i] = input;
    }
    t = create(arr, size);
    return t;
}
