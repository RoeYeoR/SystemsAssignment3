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

// // Function to insert strings into the list
// void insertStrings(StrList* list) {
//     int numWords;
//     //printf("Enter the number of words to insert: ");
//     scanf("%d", &numWords);

//     // Clear input buffer
//     while (getchar() != '\n');

//     //printf("Enter the words separated by space:\n");
//     char* buffer = malloc(sizeof(char) * 100); // Initial buffer size
//     fgets(buffer, 100, stdin);

//     size_t buffer_size = 100;
//     size_t buffer_length = strlen(buffer);
//     char* new_buffer;

//     while (buffer[buffer_length - 1] != '\n') {
//         buffer_size *= 2; // Double the buffer size
//         new_buffer = realloc(buffer, buffer_size * sizeof(char));
//         if (new_buffer == NULL) {
//             // Handle memory allocation failure
//             fprintf(stderr, "Memory allocation failed\n");
//             free(buffer);
//             return;
//         }
//         buffer = new_buffer;
//         fgets(buffer + buffer_length, buffer_size - buffer_length, stdin);
//         buffer_length = strlen(buffer);
//     }

//     char* token = strtok(buffer, " ");
//     while (token != NULL) {
//         StrList_insertLast(list, token);
//         token = strtok(NULL, " ");
//     }

//     free(buffer); // Free dynamically allocated memory
// }

// // Function to insert strings into the list
// void insertStrings(StrList* list) {
//     int numWords;
//     //printf("Enter the number of words to insert: ");
//     scanf("%d", &numWords);

//    char buffer[100]; // Assuming maximum word length is 99 characters
//     fgets(buffer, sizeof(buffer), stdin); // Clear input buffer

//     //printf("Enter the words separated by space:\n");
//     fgets(buffer, sizeof(buffer), stdin);

//     char* token = strtok(buffer, " ");
//     while (token != NULL) {
//         StrList_insertLast(list, token);
//         token = strtok(NULL, " ");
//     }
// }

// Function to insert strings into the list
void insertStrings(StrList* list) {
    int numWords;
    //printf("Enter the number of words to insert: ");
    scanf("%d", &numWords);

    // Clear input buffer
    while (getchar() != '\n');

    //printf("Enter the words separated by space:\n");
    for (int i = 0; i < numWords; i++) {
        char word[100]; // Assuming maximum word length is 99 characters
        scanf("%s", word);
        StrList_insertLast(list, word);
    }
}

int main() {
    StrList* list = StrList_alloc();
    int choice;
    char buffer[100];
    int index;

    do {
        //displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertStrings(list);
                break;
            case 2:
                //printf("Enter the index: ");
                scanf("%d", &index);
                //printf("Enter the string: ");
                scanf("%s", buffer);
                StrList_insertAt(list, buffer, index);
                break;
            case 3:
                
                StrList_print(list);
                break;
            case 4:
               size_t len = StrList_size(list);
               printf("%d\n", len);
                break;
            case 5:
                //printf("Enter the index: ");
                scanf("%d", &index);
                //printf("String at index %d: ", index);
                StrList_printAt(list, index);
                break;
            case 6:
                StrList_printLen(list);
                break;
            case 7:
                //printf("Enter the string: ");
                scanf("%s", buffer);
                StrList_count(list, buffer);
                break;
            case 8:
                //printf("Enter the string to delete: ");
                scanf("%s", buffer);
                StrList_remove(list, buffer);
                break;
            case 9:
                //printf("Enter the index to delete: ");
                scanf("%d", &index);
                StrList_removeAt(list, index);
                break;
            case 10:
                StrList_reverse(list);
                //printf("List reversed.\n");
                break;
            case 11:
                StrList_free(list);
                list = StrList_alloc();
                //printf("List deleted.\n");
                break;
            case 12:
                StrList_sort(list);
                //printf("List sorted in lexicographical order.\n");
                break;
            case 13:
                if (StrList_isSorted(list)) {
                    printf("True\n");
                } else {
                    printf("False\n");
                }
                break;
            case 0:
                //printf("Exiting program.\n");
                break;
            default:
                //printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}
