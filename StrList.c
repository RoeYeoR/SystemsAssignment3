#include "StrList.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct _StrList {
    char* data;
    struct _StrList* next;
};

StrList* StrList_alloc() {
    return NULL;
}

void StrList_free(StrList* list) {
    while (list != NULL) {
        StrList* temp = list;
        list = list->next;
        free(temp->data);
        free(temp);
    }
}

size_t StrList_size(const StrList* list) {
    size_t size = 0;
    while (list != NULL) {
        size++;
        list = list->next;
    }
    return size;
}

void StrList_insertLast(StrList* list, const char* data) {
    StrList* newNode = (StrList*)malloc(sizeof(StrList));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = strdup(data);
    newNode->next = NULL;

    if (list == NULL) {
        list = newNode;
        return;
    }

    StrList* current = list;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void StrList_insertAt(StrList* list, const char* data, int index) {
    if (index < 0)
        return;

    StrList* newNode = (StrList*)malloc(sizeof(StrList));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = strdup(data);
    newNode->next = NULL;

    if (index == 0) {
        newNode->next = list;
        list = newNode;
        return;
    }

    StrList* current = list;
    int i = 0;
    while (i < index - 1 && current != NULL) {
        current = current->next;
        i++;
    }
    if (current == NULL) {
        free(newNode->data);
        free(newNode);
        return;
    }
    newNode->next = current->next;
    current->next = newNode;
}


char* StrList_firstData(const StrList* list) {
    if (list == NULL)
        return NULL;
    return list->data;
}

void StrList_print(const StrList* list) {
    while (list != NULL) {
        printf("%s ", list->data);
        list = list->next;
    }
    printf("\n");
}

void StrList_printAt(const StrList* list, int index) {
    int i = 0;
    while (list != NULL && i < index) {
        list = list->next;
        i++;
    }
    if (list != NULL) {
        printf("%s\n", list->data);
    }
}

int StrList_printLen(const StrList* list) {
    int count = 0;
    while (list != NULL) {
        count += strlen(list->data);
        list = list->next;
    }
    return count;
}

int StrList_count(StrList* list, const char* data) {
    int count = 0;
    while (list != NULL) {
        if (strcmp(list->data, data) == 0) {
            count++;
        }
        list = list->next;
    }
    return count;
}

void StrList_remove(StrList* list, const char* data) {
    StrList* current = list;
    StrList* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->data, data) == 0) {
            if (prev == NULL) {
                list = current->next;
            } else {
                prev->next = current->next;
            }
            free(current->data);
            free(current);
            current = prev == NULL ? list : prev->next;
        } else {
            prev = current;
            current = current->next;
        }
    }
}

void StrList_removeAt(StrList* list, int index) {
    if (index < 0)
        return;

    StrList* current = list;
    StrList* prev = NULL;
    int i = 0;

    while (current != NULL && i < index) {
        prev = current;
        current = current->next;
        i++;
    }

    if (current == NULL)
        return;

    if (prev == NULL) {
        list = current->next;
    } else {
        prev->next = current->next;
    }

    free(current->data);
    free(current);
}

int StrList_isEqual(const StrList* list1, const StrList* list2) {
    while (list1 != NULL && list2 != NULL) {
        if (strcmp(list1->data, list2->data) != 0)
            return 0;
        list1 = list1->next;
        list2 = list2->next;
    }
    return list1 == NULL && list2 == NULL;
}

StrList* StrList_clone(const StrList* list) {
    StrList* clone = NULL;
    while (list != NULL) {
        StrList_insertLast(clone, list->data);
        list = list->next;
    }
    return clone;
}

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

    list = prev;
}

static int compare_strings(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

void StrList_sort(StrList* list) {
    int size = StrList_size(list);
    char** array = (char**)malloc(size * sizeof(char*));
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    StrList* temp = list;
    for (int i = 0; i < size; i++) {
        array[i] = temp->data;
        temp = temp->next;
    }

    qsort(array, size, sizeof(char*), compare_strings);

    temp = list;
    for (int i = 0; i < size; i++) {
        temp->data = array[i];
        temp = temp->next;
    }

    free(array);
}

int StrList_isSorted(StrList* list) {
    while (list != NULL && list->next != NULL) {
        if (strcmp(list->data, list->next->data) > 0)
            return 0;
        list = list->next;
    }
    return 1;
}
