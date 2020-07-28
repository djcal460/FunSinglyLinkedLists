/*
 * Author: Derek Calzadillas
 * Purpose: To demonstrate knowledge of linked lists
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "func.h"

int main()
{

    //welcome to this prog
    int input, size, ret;
    struct Node *local = NULL;
    printf("\nWelcome to Fun Fun Linked Lists. Demonstrating Knowledge of Linked Lists.\n");
    printf("To start, let's create two linked lists (one global and one local).\n");
    //create a global list called head
    struct Node *global = globallist();
    //create a local linked list (ptr to ptr)
    printf("\nEnter the size of the desired local linked list: ");
    ret = scanf("%d", &size);
    if (size < 1 || size > INT_MAX || ret != 1)
    {
        size = reprompt(1); //1 flag for size
    }
    printf("Enter an integer for each element of the local linked list.\n");
    for (int i = 0; i < size; i++)
    {
        printf("Please enter an integer: ");
        ret = scanf("%d", &input);
        if (ret != 1 || input > INT_MAX)
        {
            input = reprompt(2); //2 flag for int only
        }
        insertLast(&local, input);
    }

    //display the lists to the user
    printf("\nThis is your global linked list: ");
    display(global);
    printf("This is your local linked list: ");
    display(local);

    //have user choose preferred list
    int llchoice;
    printf("Choose a list to work with (1: global 2: local): ");
    ret = scanf("%d", &llchoice);
    if (ret != 1 || llchoice > 2 || llchoice < 1)
    {
        llchoice = reprompt(4); //4 flag for 1,2 only
    }

    //create a reference to the global/local list by choice
    struct Node *choicelist1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *choicelist2 = (struct Node *)malloc(sizeof(struct Node));
    char *strchoice1 = "Global";
    char *strchoice2 = "Local";
    //set choice
    if (llchoice == 1)
    {
        choicelist1 = global;
        choicelist2 = local;
    }
    else if (llchoice == 2)
    {
        choicelist1 = local;
        choicelist2 = global;
        //swap choices for string printout
        char *temp = strchoice1;
        strchoice1 = strchoice2;
        strchoice2 = temp;
    }
    else
    {
        fprintf(stderr, "Incorrect linked list choice.\n");
        exit(1);
    }

    //prompt user for what they would like to do with the linked list
    do
    {

        printf("\nWhat Do You Want to Do with %s Linked List?\n", strchoice1);
        printf("1.  Display\n");
        printf("2.  Sum the Elements\n");
        printf("3.  Count the Elements\n");
        printf("4.  Find Max Element\n");
        printf("5.  Search\n");
        printf("6.  Insert at Head\n");
        printf("7.  Insert at Position\n");
        printf("8.  Delete the %s Linked List From Memory\n", strchoice1);
        printf("9.  Check if Sorted\n");
        printf("10. Sort Linked List\n");
        printf("11. Sort and Add New Sorted Node.\n");
        printf("12. Delete Head Node\n");
        printf("13. Delete at Position\n");
        printf("14. Remove Duplicates and sort\n");
        printf("15. Reverse Link List by Elements\n");
        printf("16. Reverse Link List by Links\n");
        printf("17. Concat with %s Linked List\n", strchoice2);
        printf("18. Sort, then Merge with %s Linked List\n", strchoice2);
        printf("19. Exit Program.\n");

        printf("\nEnter your choice: ");
        ret = scanf("%d", &input);
        if (ret != 1 || input > 19 || input < 1)
        {
            input = reprompt(5); //flag#5 for 1-18 choices
        }
        switch (input)
        {
        case 1:
            printf("Display");
            displayMenu(choicelist1);
            break;
        case 2:
            printf("Sum");
            sumMenu(choicelist1);
            break;
        case 3:
            printf("Count");
            countMenu(choicelist1);
            break;
        case 4:
            printf("Find Max");
            maxMenu(choicelist1);
            break;
        case 5:
            printf("Search");
            searchMenu(choicelist1);
            break;
        case 6:
            printf("Insert Head");
            choicelist1 = insertHeadMenu(choicelist1);
            break;
        case 7:
            printf("Insert Pos");
            choicelist1 = insertPosMenu(choicelist1);
            break;
        case 8:
            printf("Delete this linked list");
            choicelist1 = freeMenu(choicelist1);
            break;
        case 9:
            printf("Is Sorted?");
            isSortedMenu(choicelist1);
            break;
        case 10:
            printf("Sort");
            sortMenu(choicelist1);
            break;
        case 11:
            printf("Sort and Insert");
            choicelist1 = insertSortedMenu(choicelist1);
            break;
        case 12:
            printf("Delete Head");
            choicelist1 = deleteHeadMenu(choicelist1);
            break;
        case 13:
            printf("Delete at Pos");
            choicelist1 = deleteAtPosMenu(choicelist1);
            break;
        case 14:
            printf("Remove Dups and Sort");
            choicelist1 = removeDupsMenu(choicelist1);
            break;
        case 15:
            printf("Reverse by Ele");
            choicelist1 = reverseEleMenu(choicelist1);
            break;
        case 16:
            printf("Reverse by Links");
            choicelist1 = reverseListMenu(choicelist1);
            break;
        case 17:
            printf("Concat with other linked list and Exit");
            choicelist1 = concatListsMenu(choicelist1, choicelist2, strchoice1, strchoice2);
            exit(0);
            break;
        case 18:
            printf("Merge with other linked list and Exit");
            choicelist1 = sortMergeMenu(choicelist1, choicelist2, strchoice1, strchoice2); //decending display
            exit(0);
        case 19:
            printf("Exiting Program\n");
            exit(0);
        default:
            printf("Invalid option.\n");
        }
    } while (input != 19);
}
