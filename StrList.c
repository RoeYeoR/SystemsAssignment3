#include "StrList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the linked list node
struct _StrList {
    char* data;
    struct _StrList* next;
};

// Function to allocate a new empty StrList
StrList* StrList_alloc() {
    return NULL; // Return NULL for an empty list
}

// Function to free the memory allocated to StrList
void StrList_free(StrList* list) {
    StrList* current = list;
    while (current != NULL) {
        StrList* next = current->next;
        free(current->data); // Free the string data
        free(current); // Free the node
        current = next;
    }
}

// Function to return the number of elements in the StrList
size_t StrList_size(const StrList* list) {
    size_t count = 0;
    const StrList* current = list;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Function to insert an element at the end of the StrList
void StrList_insertLast(StrList* list, const char* data) {
    StrList* newNode = (StrList*)malloc(sizeof(StrList));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = strdup(data); // Duplicate the string data
    newNode->next = NULL;

    // If the list is empty, make the new node the head
    if (list == NULL) {
        list = newNode;
        return;
    }

    // Find the last node and append the new node
    StrList* current = list;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Function to insert an element at a given index in the StrList
void StrList_insertAt(StrList* list, const char* data, int index) {
    if (index < 0) {
        fprintf(stderr, "Invalid index\n");
        return;
    }

    // If index is 0, insert at the beginning
    if (index == 0) {
        StrList* newNode = (StrList*)malloc(sizeof(StrList));
        if (newNode == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
        newNode->data = strdup(data);
        newNode->next = list;
        list = newNode;
        return;
    }

    // Traverse the list to find the insertion point
    StrList* current = list;
    int i;
    for (i = 0; i < index - 1 && current != NULL; i++) {
        current = current->next;
    }
    if (current == NULL) {
        fprintf(stderr, "Index out of bounds\n");
        return;
    }

    // Insert the new node
    StrList* newNode = (StrList*)malloc(sizeof(StrList));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = strdup(data);
    newNode->next = current->next;
    current->next = newNode;
}

// Function to return the data of the first element in the StrList
char* StrList_firstData(const StrList* list) {
    if (list == NULL) {
        return NULL;
    }
    return list->data;
}

// Function to print all elements of the StrList to the standard output
void StrList_print(const StrList* list) {
    const StrList* current = list;
    while (current != NULL) {
        printf("%s ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to print the element at a given index in the StrList
void StrList_printAt(const StrList* list, int index) {
    const StrList* current = list;
    int i;
    for (i = 0; i < index && current != NULL; i++) {
        current = current->next;
    }
    if (current != NULL) {
        printf("%s\n", current->data);
    } else {
        fprintf(stderr, "Index out of bounds\n");
    }
}

// Function to return the total number of characters in the StrList
int StrList_printLen(const StrList* list) {
    int totalLen = 0;
    const StrList* current = list;
    while (current != NULL) {
        totalLen += strlen(current->data);
        current = current->next;
    }
    return totalLen;
}

// Function to return the number of times a given string appears in the StrList
int StrList_count(StrList* list, const char* data) {
    int count = 0;
    StrList* current = list;
    while (current != NULL) {
        if (strcmp(current->data, data) == 0) {
            count++;
        }
        current = current->next;
    }
    return count;
}

// Function to remove all occurrences of a given string from the StrList
void StrList_remove(StrList* list, const char* data) {
    StrList* current = list;
    StrList* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->data, data) == 0) {
            if (prev == NULL) { // If the matched node is the head
                list = current->next;
                free(current->data);
                free(current);
                current = list;
            } else {
                prev->next = current->next;
                free(current->data);
                free(current);
                current = prev->next;
            }
        } else {
            prev = current;
            current = current->next;
        }
    }
}

// Function to remove the element at a given index from the StrList
void StrList_removeAt(StrList* list, int index) {
    if (index < 0) {
        fprintf(stderr, "Invalid index\n");
        return;
    }

    // If index is 0, remove the first element
    if (index == 0) {
        StrList* temp = list;
        list = list->next;
        free(temp->data);
        free(temp);
        return;
    }

    // Traverse the list to find the node before the one to be removed
    StrList* current = list;
    StrList* prev = NULL;
    int i;
    for (i = 0; i < index && current != NULL; i++) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        fprintf(stderr, "Index out of bounds\n");
        return;
    }

    // Remove the node
    prev->next = current->next;
    free(current->data);
    free(current);
}

// Function to check if two StrLists have the same elements
int StrList_isEqual(const StrList* list1, const StrList* list2) {
    const StrList* current1 = list1;
    const StrList* current2 = list2;

    while (current1 != NULL && current2 != NULL) {
        if (strcmp(current1->data, current2->data) != 0) {
            return 0; // Not equal if data is different
        }
        current1 = current1->next;
        current2 = current2->next;
    }

    // Lists are equal only if both are NULL at this point
    return (current1 == NULL && current2 == NULL);
}

// Function to clone the given StrList
StrList* StrList_clone(const StrList* list) {
    StrList* newHead = NULL;
    const StrList* current = list;

    while (current != NULL) {
        StrList_insertLast(newHead, current->data);
        current = current->next;
    }

    return newHead;
}

// Function to reverse the order of elements in the StrList
void StrList_reverse(StrList* list) {
    StrList* prev = NULL;
    StrList* current = list;
    StrList* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    list = prev; // New head of the reversed list
}

// Function to compare strings for sorting
int compareStrings(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

// Function to sort the elements of the StrList in lexicographical order
void StrList_sort(StrList* list) {
    int size = StrList_size(list);
    if (size <= 1) {
        return; // Already sorted
    }

    char* arr[size];
    StrList* current = list;

    // Copy data to an array for sorting
    for (int i = 0; i < size; i++) {
        arr[i] = current->data;
        current = current->next;
    }

    // Sort the array
    qsort(arr, size, sizeof(char*), compareStrings);

    // Update the StrList with sorted data
    current = list;
    for (int i = 0; i < size; i++) {
        strcpy(current->data, arr[i]);
        current = current->next;
    }
}

// Function to check if the elements of the StrList are sorted in lexicographical order
int StrList_isSorted(StrList* list) {
    StrList* current = list;
    while (current != NULL && current->next != NULL) {
        if (strcmp(current->data, current->next->data) > 0) {
            return 0; // Not sorted
        }
        current = current->next;
    }
    return 1; // Sorted
}
