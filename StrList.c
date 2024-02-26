#include "StrList.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct _Node
{
    char* _data;
    struct _Node* _next;
} Node;

struct _StrList
{
    size_t _size;
    Node* _head;
};

// Helper Functions Prototypes
void Node_free(Node* node);
Node* Node_alloc(const char* data, Node* next);

StrList* StrList_alloc()
{
    StrList* newStrList = (StrList*)malloc(sizeof(StrList));
    newStrList->_head = NULL;
    newStrList->_size = 0;
    return newStrList;
}

void StrList_free(StrList* StrList)
{
    if (StrList == NULL)
        return;
    Node* p1 = StrList->_head;
    Node* p2;
    while (p1)
    {
        p2 = p1;
        p1 = p1->_next;
        Node_free(p2);
    }
    free(StrList);
}

void Node_free(Node* node)
{
    free(node->_data);
    free(node);
}

Node* Node_alloc(const char* data, Node* next)
{
    Node* node = (Node*)malloc(sizeof(Node));
    char* alloc_data = (char*)malloc(sizeof(char) * (strlen(data) + 1));
    strcpy(alloc_data, data);
    node->_data = alloc_data;
    node->_next = next;
    return node;
}

size_t StrList_size(const StrList* StrList)
{
    return StrList->_size;
}

void StrList_insertLast(StrList* StrList, const char* data)
{
    if (StrList == NULL)
    {
        StrList->_head = Node_alloc(data, NULL);
    }
    else
    {
        Node* node = StrList->_head;
        if (node == NULL)
        {
            StrList->_head = Node_alloc(data, NULL);
        }
        else
        {
            while (node->_next)
            {
                node = node->_next;
            }
            node->_next = Node_alloc(data, NULL);
        }
    }
    ++(StrList->_size);
}

void StrList_insertAt(StrList* StrList, const char* data, int index)
{
    if (index > StrList->_size || index < 0)
        return;

    if (index == 0)
    {
        Node* nextNode = StrList->_head;
        StrList->_head = Node_alloc(data, nextNode);
    }
    else
    {
        Node* p1 = StrList->_head;
        Node* p2 = p1;
        int i = 0;
        while (p1 && i < index)
        {
            p2 = p1;
            p1 = p1->_next;
            ++i;
        }

        Node* previousNode = p2;
        Node* nextNode = p1;
        Node* newNode = Node_alloc(data, nextNode);
        previousNode->_next = newNode;
    }
    ++(StrList->_size);
}

char* StrList_firstData(const StrList* StrList)
{
    if (StrList->_head != NULL)
        return StrList->_head->_data;
    return NULL;
}

void StrList_print(const StrList* StrList)
{
    if (StrList == NULL || StrList->_head == NULL)
        return;
    const Node* p = StrList->_head;
    while (p)
    {
        printf("%s ", p->_data);
        p = p->_next;
    }
}

void StrList_printAt(const StrList* StrList, int index)
{
    if (StrList == NULL || StrList->_head == NULL)
        return;
    int i = 0;
    const Node* p = StrList->_head;
    while (p)
    {
        if (i == index)
        {
            printf("%s ", p->_data);
            break;
        }
        p = p->_next;
        ++i;
    }
}

int StrList_printLen(const StrList* StrList)
{
    if (StrList == NULL || StrList->_head == NULL)
        return 0;

    int sum = 0;
    const Node* p = StrList->_head;
    while (p)
    {
        int charAmount = strlen(p->_data);
        sum += charAmount;
        p = p->_next;
    }

    return sum;
}

int StrList_count(StrList* StrList, const char* data)
{
    if (StrList == NULL || StrList->_head == NULL)
        return 0;

    int count = 0;
    Node* p = StrList->_head;
    while (p)
    {
        if (strcmp(p->_data, data) == 0)
            count++;
        p = p->_next;
    }
    return count;
}

void StrList_remove(StrList* StrList, const char* data)
{
    if (StrList == NULL || StrList->_head == NULL)
        return;

    Node* p1 = StrList->_head;
    Node* prev = NULL;

    // Removing head node if it matches
    while (p1 != NULL && strcmp(p1->_data, data) == 0)
    {
        StrList->_head = p1->_next;
        Node_free(p1);
        p1 = StrList->_head;
        StrList->_size--;
    }

    // Removing non-head nodes if they match
    while (p1 != NULL)
    {
        while (p1 != NULL && strcmp(p1->_data, data) != 0)
        {
            prev = p1;
            p1 = p1->_next;
        }

        if (p1 == NULL)
            return;

        prev->_next = p1->_next;
        Node_free(p1);
        p1 = prev->_next;
        StrList->_size--;
    }
}

void StrList_removeAt(StrList* StrList, int index)
{
    if (StrList == NULL || StrList->_head == NULL)
        return;

    Node* p1 = StrList->_head;
    Node* prev = NULL;

    if (index == 0)
    {
        StrList->_head = p1->_next;
        Node_free(p1);
        StrList->_size--;
        return;
    }

    int i = 0;
    while (p1 != NULL && i != index)
    {
        prev = p1;
        p1 = p1->_next;
        i++;
    }

    if (p1 == NULL)
        return;

    prev->_next = p1->_next;
    Node_free(p1);
    StrList->_size--;
}

int StrList_isEqual(const StrList* StrList1, const StrList* StrList2)
{
    if (StrList1->_size != StrList2->_size)
        return 0;

    Node* p1 = StrList1->_head;
    Node* p2 = StrList2->_head;

    while (p1 != NULL && p2 != NULL)
    {
        if (strcmp(p1->_data, p2->_data) != 0)
            return 0;
        p1 = p1->_next;
        p2 = p2->_next;
    }

    return 1;
}

StrList* StrList_clone(const StrList* Strlist)
{
    StrList* clone = StrList_alloc();
    const Node* old = Strlist->_head;
    Node** copy = &(clone->_head);
    clone->_size = Strlist->_size;
    while (old != NULL)
    {
        *copy = Node_alloc(old->_data, NULL);
        old = old->_next;
        copy = &((*copy)->_next);
    }
    return clone;
}

void StrList_reverse(StrList* Strlist)
{
    Node* current = Strlist->_head;
    Node* prev = NULL;
    Node* next = NULL;

    while (current != NULL)
    {
        next = current->_next;
        current->_next = prev;
        prev = current;
        current = next;
    }

    Strlist->_head = prev;
}

void StrList_sort(StrList* Strlist)
{
    if (Strlist == NULL || Strlist->_head == NULL || Strlist->_size == 1)
        return;

    int swapped;
    Node *ptr1;
    Node *lptr = NULL;

    do
    {
        swapped = 0;
        ptr1 = Strlist->_head;

        while (ptr1->_next != lptr)
        {
            if (strcmp(ptr1->_data, ptr1->_next->_data) > 0)
            {
                char* temp = ptr1->_data;
                ptr1->_data = ptr1->_next->_data;
                ptr1->_next->_data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->_next;
        }
        lptr = ptr1;
    } while (swapped);
}

int StrList_isSorted(StrList* Strlist)
{
    if (Strlist == NULL || Strlist->_head == NULL || Strlist->_size == 1)
        return 0;

    Node *current = Strlist->_head;

    while (current->_next != NULL)
    {
        if (strcmp(current->_data, current->_next->_data) > 0)
            return 0;
        current = current->_next;
    }

    return 1;
}
