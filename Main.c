#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StrList.h"

// Function to display the menu options
void displayMenu() {
    printf("\nMenu:\n");
    printf("1 - Insert strings into the list\n");
    printf("2 - Insert a string at a certain index\n");
    printf("3 - Print the list\n");
    printf("4 - Print the length of the list\n");
    printf("5 - Print a string at a certain index\n");
    printf("6 - Print the number of characters that appear in the entire list\n");
    printf("7 - Print how many times a string appears\n");
    printf("8 - Delete all occurrences of a string from the list\n");
    printf("9 - Delete a member at a certain index\n");
    printf("10 - Reverse the list\n");
    printf("11 - Delete the entire list\n");
    printf("12 - Arrange the list in lexicographical order\n");
    printf("13 - Check whether the list is arranged in lexicographical order\n");
    printf("0 - Exit\n");
    printf("Enter your choice: ");
}

// Function to insert strings into the list
void insertStrings(StrList** list) {
    int numWords;
    printf("Enter the number of words to insert: ");
    scanf("%d", &numWords);

    char buffer[100]; // Assuming maximum word length is 99 characters
    fgets(buffer, sizeof(buffer), stdin); // Clear input buffer

    printf("Enter the words separated by space:\n");
    fgets(buffer, sizeof(buffer), stdin);

    char* token = strtok(buffer, " ");
    while (token != NULL) {
        StrList_insertLast(&list, token);
        token = strtok(NULL, " ");
    }
}

int main() {
    StrList* list = StrList_alloc();
    int choice;
    char buffer[100];
    int index;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertStrings(&list);
                break;
            case 2:
                printf("Enter the index: ");
                scanf("%d", &index);
                printf("Enter the string: ");
                scanf("%s", buffer);
                StrList_insertAt(&list, buffer, index);
                break;
            case 3:
                printf("List: ");
                StrList_print(list);
                break;
            case 4:
                printf("Length of the list: %zu\n", StrList_size(list));
                break;
            case 5:
                printf("Enter the index: ");
                scanf("%d", &index);
                printf("String at index %d: ", index);
                StrList_printAt(list, index);
                break;
            case 6:
                printf("Total characters in the list: %d\n", StrList_printLen(list));
                break;
            case 7:
                printf("Enter the string: ");
                scanf("%s", buffer);
                printf("Number of times '%s' appears: %d\n", buffer, StrList_count(list, buffer));
                break;
            case 8:
                printf("Enter the string to delete: ");
                scanf("%s", buffer);
                StrList_remove(&list, buffer);
                break;
            case 9:
                printf("Enter the index to delete: ");
                scanf("%d", &index);
                StrList_removeAt(&list, index);
                break;
            case 10:
                StrList_reverse(&list);
                printf("List reversed.\n");
                break;
            case 11:
                StrList_free(list);
                list = StrList_alloc();
                printf("List deleted.\n");
                break;
            case 12:
                StrList_sort(list);
                printf("List sorted in lexicographical order.\n");
                break;
            case 13:
                if (StrList_isSorted(list)) {
                    printf("List is arranged in lexicographical order.\n");
                } else {
                    printf("List is not arranged in lexicographical order.\n");
                }
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}