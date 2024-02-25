#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StrList.h"

int main() {
    StrList* list = NULL;
    char input[100];
    char *token;
    int index;
    char word[100];

    fgets(input, sizeof(input), stdin);
    token = strtok(input, " \n");
    int option = atoi(token);

    switch(option) {
        case 1:
            {
                token = strtok(NULL, " \n");
                int numWords = atoi(token);
                for (int i = 0; i < numWords; i++) {
                    fgets(word, sizeof(word), stdin);
                    word[strcspn(word, "\n")] = 0; // remove newline character
                    StrList_insertLast(list, word);
                }
                break;
            }
        case 2:
            {
                token = strtok(NULL, " \n");
                index = atoi(token);
                fgets(word, sizeof(word), stdin);
                word[strcspn(word, "\n")] = 0; // remove newline character
                StrList_insertAt(list, word, index);
                break;
            }
        case 3:
            StrList_print(list);
            break;
        case 4:
            printf("%zu\n", StrList_size(list));
            break;
        case 5:
            {
                token = strtok(NULL, " \n");
                index = atoi(token);
                StrList_printAt(list, index);
                break;
            }
        case 6:
            printf("%d\n", StrList_printLen(list));
            break;
        case 7:
            fgets(word, sizeof(word), stdin);
            word[strcspn(word, "\n")] = 0; // remove newline character
            printf("%d\n", StrList_count(list, word));
            break;
        case 8:
            fgets(word, sizeof(word), stdin);
            word[strcspn(word, "\n")] = 0; // remove newline character
            StrList_remove(list, word);
            break;
        case 9:
            {
                token = strtok(NULL, " \n");
                index = atoi(token);
                StrList_removeAt(list, index);
                break;
            }
        case 10:
            StrList_reverse(list);
            break;
        case 11:
            StrList_free(list);
            list = NULL;
            break;
        case 12:
            StrList_sort(list);
            break;
        case 13:
            if (StrList_isSorted(list))
                printf("true\n");
            else
                printf("false\n");
            break;
        case 0:
            break;
        default:
            printf("Invalid option!\n");
    }

    return 0;
}
