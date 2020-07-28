/*
 * Author: Derek Calzadillas
 * Purpose: To demonstrate knowledge of linked lists
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "func.h"

void displayMenu(struct Node *p)
{
    //display LL using iter, tail recursion, and head recursion
    int input, ret;
    int f = 0;
    while (!f)
    {
        printf("\nHow do you want the display computed?\n");
        printf("Press [1] iterative display [2] tail recursion display [3] head recursion display (Reverse): ");
        ret = scanf("%d", &input);
        if (ret != 1 || input > 3 || input < 1)
        {
            input = reprompt(3); //3 flag for 1,2,3 only
        }
        switch (input)
        {
        case 1:
            printf("You Chose Iterative Display:\n");
            display(p); //ascending display
            break;
        case 2:
            printf("You Chose Tail Recursion Display:\n");
            recursiveTailDisplay(p); //ascending display
            printf("\n");
            break;
        case 3:
            printf("You Chose Head Recursion Display (Reverse):\n");
            recursiveHeadDisplay(p); //decending display
            printf("\n");
            break;
        default:
            printf("Invalid option.\n");
        }
        f = tryagain();
    }
}

void sumMenu(struct Node *p)
{
    //add LL using iter, tail recursion, and head recursion
    int input, ret, result = 0;
    int f = 0;
    while (!f)
    {
        printf("\nHow do you want to compute the addition of your elements?\n");
        printf("Enter 1 for iterative, 2 for tail recursion, or 3 for head recursion:");
        ret = scanf("%d", &input);
        if (ret != 1 || input > 3 || input < 1)
        {
            input = reprompt(3); //3 flag for 1,2,3 only
        }
        switch (input)
        {
        case 1:
            result = add(p); //ascending add
            break;
        case 2:
            result = recursiveTailAdd(p); //ascending add
            break;
        case 3:
            result = recursiveHeadAdd(p); //decending add
            break;
        default:
            printf("Invalid option.\n");
        }
        printf("The sum is: %d\n", result);
        f = tryagain();
    }
}

void countMenu(struct Node *p)
{
    //count LL using iter, tail recursion, and head recursion
    int input, ret, result = 0;
    int f = 0;
    while (!f)
    {
        printf("\nHow do you want to compute the count of your elements?\n");
        printf("Enter 1 for iterative, 2 for tail recursion, or 3 for head recursion:");
        ret = scanf("%d", &input);
        if (ret != 1 || input > 3 || input < 1)
        {
            input = reprompt(3); //3 flag for 1,2,3 only
        }
        switch (input)
        {
        case 1:
            result = count(p); //ascending add
            break;
        case 2:
            result = recursiveTailCount(p); //ascending add
            break;
        case 3:
            result = recursiveHeadCount(p); //decending add
            break;
        default:
            printf("Invalid option.\n");
        }
        printf("The count is: %d\n", result);
        f = tryagain();
    }
}
void maxMenu(struct Node *p)
{
    //Find Max Element LL using iter, tail recursion, and head recursion
    int input, ret, result = 0;
    int f = 0;
    while (!f)
    {
        printf("\nHow do you want to compute finding the max element?\n");
        printf("Enter 1 for iterative, 2 for recursion:");
        ret = scanf("%d", &input);
        if (ret != 1 || input > 2 || input < 1)
        {
            input = reprompt(4); //4 flag for 1,2 only
        }
        switch (input)
        {
        case 1:
            result = maxEle(p); //ascending add
            break;
        case 2:
            result = recursiveMaxEle(p); //ascending add
            break;
        default:
            printf("Invalid option.\n");
        }
        printf("The max element is: %d\n", result);
        f = tryagain();
    }
}
void searchMenu(struct Node *p)
{
    //Search ll using linear search or improved linear search
    int input, query, ret;
    int f = 0;
    while (!f)
    {
        printf("\nHow do you want to search for your element?\n");
        printf("Enter 1 for linear search, 2 for improved linear search (move found ele to head):");
        fflush(stdin);
        ret = scanf("%d", &input);
        if (ret != 1 || input > 2 || input < 1)
        {
            input = reprompt(4); //4 flag for 1,2 only
            fflush(stdin);
        }
        printf("Enter integer to search for in linked list:");
        fflush(stdin);
        ret = scanf("%d", &query);
        if (ret != 1 || query > INT_MAX)
        {
            query = reprompt(2); //2 flag for valid int
            fflush(stdin);
        }
        struct Node *s;
        switch (input)
        {
        case 1:
            s = search(&p, query); //ascending add
            break;
        case 2:
            s = improvedSearch(&p, query); //ascending add
            break;
        default:
            printf("Invalid option.\n");
        }
        if (s)
        {
            p = s; //improved search will update the ll
            display(s);
        }
        else
            printf("Search not found\n");
        f = tryagain();
    }
}

struct Node *insertHeadMenu(struct Node *p)
{
    //Insert at head of LL
    int f = 0;
    int ins, ret;
    while (!f)
    {
        printf("\nInsert an integer to the head of the linked list.\n");
        printf("Enter a valid integer: ");
        fflush(stdout);
        ret = scanf("%d", &ins);
        if (ret != 1 || ins > INT_MAX)
        {
            ins = reprompt(2); //2 flag for valid int
        }
        insertAsHead(&p, ins);
        printf("You inserted %d in: ", ins);
        printf("\n");
        display(p);
        f = tryagain();
    }
    return p;
}
struct Node *insertPosMenu(struct Node *p)
{
    //Insert at position of ll
    int f = 0;
    int pos, ins, ret;
    while (!f)
    {
        printf("\nInsert an integer a a given pos of the linked list.\n");
        display(p);
        printf("Enter a valid integer to insert: ");
        fflush(stdout);
        ret = scanf("%d", &ins);
        if (ret != 1 || ins > INT_MAX)
        {
            ins = reprompt(2); //2 flag for valid int
        }
        printf("Enter a position: ");
        fflush(stdout);
        ret = scanf("%d", &pos);
        if (ret != 1 || pos > INT_MAX)
        {
            pos = reprompt(2); //2 flag for valid int
        }
        int bounds = insertAtPosition(&p, ins, pos);
        if (bounds)
        {
            printf("You inserted %d at pos %d in: ", ins, pos);
            display(p);
        }
        else
        {
            printf("Your position was out of bounds\n");
        }
        f = tryagain();
    }
    return p;
}
struct Node *freeMenu(struct Node *p)
{
    freeList(&p);
    printf("Linked list is now deleted (blank->): ");
    display(p);
    printf("Free this list. Press any key:");
    getchar();
    getchar();
    fflush(stdin);
    printf("\n");
    return p;
}
struct Node *insertSortedMenu(struct Node *p)
{
    //insert nodes into a sorted linked list
    sort(p);
    int f = 0;
    int res, input;
    while (!f)
    {

        printf("\nAdd an integer; it will be sorted in the linked list: ");
        display(p);
        printf("Please enter an integer to insert: ");
        fflush(stdin);
        res = scanf("%d", &input);
        if (res != 1 || input > INT_MAX)
        {
            input = reprompt(2); //2 flag for int only
        }
        insertInSorted(p, input); //instead of passing head, could just create p ptr in function (applic for many of functions here)
        printf("Updated linked list: ");
        display(p);
        f = tryagain();
    }
    return p;
}

void isSortedMenu(struct Node *p)
{
    //check if sorted
    int ret, input, f = 0;
    while (!f)
    {
        printf("\nCheck if linked list is sorted: ");
        display(p);
        printf("Check it? Enter 1 for yes, 2 for no: ");
        ret = scanf("%d", &input);
        if (ret != 1 || input > 2 || input < 1)
        {
            input = reprompt(4); //4 valid option 1 or 2
        }
        int b = isSorted(p);
        if (b)
            printf("Yes, Linked List Is Sorted\n");
        else
            printf("No, Linked List Is Not Sorted\n");
        f = tryagain();
    }
}

void sortMenu(struct Node *p)
{
    printf("\nPreparing to sort: ");
    display(p);
    sort(p);
    printf("Sorted: ");
    display(p);
    printf("Press any key to continue");
    getchar();
    getchar();
    fflush(stdin);
}

struct Node *deleteHeadMenu(struct Node *p)
{
    //delete head of list
    int ret, input, f = 0;
    while (!f)
    {
        printf("\nDelete head node from list: ");
        display(p);
        printf("Delete head node? Enter 1 for yes, 2 for no: ");
        ret = scanf("%d", &input);
        if (ret != 1 || input > 2 || input < 1)
        {
            input = reprompt(4); //4 valid option 1 or 2
        }
        if (input == 1)
        {
            struct Node *t = p;
            p = p->next;
            free(t);
            printf("Updated linked list: ");
            display(p);
        }
        else
        {
            printf("Head Not Deleted.\n");
        }
        f = tryagain();
    }
    return p;
}

struct Node *deleteAtPosMenu(struct Node *p)
{
    //delete node at position
    int pos, ret, f = 0;
    while (!f)
    {
        printf("\nChoose a position to delete the node: ");
        display(p);
        ret = scanf("%d", &pos);
        if (pos < 1 || pos > INT_MAX || ret != 1)
        {
            pos = reprompt(2); //2 flag for int only
        }
        p = deleteNodeAtPos(&p, pos);
        printf("Updated linked list: ");
        display(p);
        f = tryagain();
    }
    return p;
}

struct Node *removeDupsMenu(struct Node *p)
{
    //remove duplicates
    int ret, input;
    printf("\nRemove duplicates and sort linked list: ");
    display(p);
    printf("Need to sort and remove dups? Enter 1 for yes, 2 for no: ");
    ret = scanf("%d", &input);
    if (ret != 1 || input > 2 || input < 1)
    {
        input = reprompt(4); //4 valid option 1 or 2
    }
    sort(p);
    p = removeDupsInSortedList(&p);
    printf("Duplicates have been removed: ");
    display(p);
    printf("Press any key to continue: ");
    getchar();
    getchar();
    fflush(stdin);
    return p;
}

struct Node *reverseEleMenu(struct Node *p)
{
    //reverse by element
    int input, ret, f = 0;
    while (!f)
    {
        printf("\nReverse linked list by swapping elements: ");
        display(p);
        printf("Note: The same addresses will not be mapped to same values.\n");
        printf("Reverse em'? Enter 1 for yes, 2 for no: ");
        ret = scanf("%d", &input);
        if (ret != 1 || input > 2 || input < 1)
        {
            input = reprompt(4); //4 valid option 1 or 2
        }

        if (input == 1)
        {
            reverseElements(p, count(p));
            printf("Elements have been reversed by swapping addresses: ");
            display(p);
        }
        else
        {
            printf("List was not reversed.\n");
        }
        f = tryagain();
    }
    return p;
}
struct Node *reverseListMenu(struct Node *p)
{
    //reverse by link
    int ret, input, f = 0;
    while (!f)
    {
        printf("\nReverse linked list by swapping links: ");
        display(p);
        printf("Note: The same addresses will be mapped to same values.\n");
        printf("Reverse em'? Enter 1 for yes, 2 for no: ");
        ret = scanf("%d", &input);
        if (ret != 1 || input > 2 || input < 1)
        {
            input = reprompt(4); //4 valid option 1 or 2
        }
        if (input == 1)
        {
            p = reverseLinks(p);
            printf("Elements have been reversed by swapping addresses: ");
            display(p);
        }
        else
        {
            printf("List was not reversed.\n");
        }
        f = tryagain();
    }
    return p;
}

struct Node *concatListsMenu(struct Node *list1, struct Node *list2, char *l1, char *l2)
{
    int input, ret;
    printf("\nThis is your %s linked list: ", l1);
    display(list1);
    printf("This is your %s linked list: ", l2);
    display(list2);
    printf("Do you wish to concat these two lists?\n");
    printf("Enter 1 for yes, 2 for no: ");
    ret = scanf("%d", &input);
    if (ret != 1 || input > 2 || input < 1)
    {
        input = reprompt(4); //4 valid option 1 or 2
    }
    if (input == 1)
    {
        list1 = concat(list1, list2);
        printf("Result: ");
        display(list1);
    }
    else
    {
        printf("List was not concatenated.\n");
    }
    printf("Exiting Program... Press any key to continue: ");
    getchar();
    getchar();
    fflush(stdin);
    return list1;
}

struct Node *sortMergeMenu(struct Node *list1, struct Node *list2, char *l1, char *l2)
{
    int input, ret;
    printf("\nThis is your %s linked list: ", l1);
    display(list1);
    printf("This is your %s linked list: ", l2);
    display(list2);
    printf("Do you wish to merge these two lists?\n");
    printf("Enter 1 for yes, 2 for no: ");
    ret = scanf("%d", &input);
    if (ret != 1 || input > 2 || input < 1)
    {
        input = reprompt(4); //4 valid option 1 or 2
    }
    if (input == 1)
    {
        printf("Merge Two Sorted Lists\n");
        sort(list1);
        sort(list2);
        list1 = mergeTwoSortedLists(list1, list2);
        display(list1);
    }
    else
    {
        printf("List was not merged");
    }
    printf("Exiting Program... Press any key to continue: ");
    getchar();
    getchar();
    fflush(stdin);
    return list1;
}
