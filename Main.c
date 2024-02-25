#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StrList.h"

int main() {
    StrList* list = NULL;
    char input[100];
    char *token;
    int index;
    char *word = NULL;
    size_t word_size = 0;
    int option;

    do
    {
        fgets(input, sizeof(input), stdin);
        token = strtok(input, "\n");
        option = atoi(token);

    switch(option)
     {
        case 1:
            {
            fgets(input, sizeof(input), stdin);
            token = strtok(input,"\n");
            int numWords = atoi(token);

            fgets(input,sizeof(input),stdin);
            token = strtok(input," \t\n,.\"");
            while(token != NULL)
            {
                StrList_insertLast(list,token);
                token = strtok(NULL, " \t\n,.\"");

            }
            break;
            
            // for (int i = 0; i < numWords; i++)
            // {
            // fgets(token,sizeof(token),stdin);
            // token = strtok(input," ");
            // StrList_insertLast(list, token); // Insert the word into the list
            // token = strtok(NULL," "); 
            // }
            // break;
            // }
        
        case 2:
            {
                fgets(input, sizeof(input), stdin);
                token = strtok(input, "\n");
                index = atoi(token);

                fgets(input,sizeof(input),stdin);
                token = strtok(input,"\n");
                StrList_insertAt(list,token,index);
                break;
                // word = (char*)malloc(100 * sizeof(char)); // Allocate memory for the word
                // fgets(word, 100, stdin); // Read the word dynamically
                // word[strcspn(word, " ")] = 0; // remove newline character
                // StrList_insertAt(list, word, index); // Insert the word into the list at index
                // break;
            }
        case 3:
            StrList_print(list);
            break;
        case 4:
            printf("%zu\n", StrList_size(list));
            break;
        case 5:
            {
                fgets(input, sizeof(input), stdin);
                token = strtok(input, "\n");
                index = atoi(token);
                StrList_printAt(list, index);
                break;
        break;
            }
        case 6:
            printf("%d\n", StrList_printLen(list));
            break;
        case 7:
            fgets(input,sizeof(input),stdin);
            token = strtok(input,"\n");
            StrList_count(list,token);
            break;
            // getline(&word, &word_size, stdin); // Read the word dynamically
            // word[strcspn(word, " ")] = 0; // remove newline character
            // printf("%d\n", StrList_count(list, word));
            // free(word); // Free dynamically allocated memory
            // break;
        case 8:
            fgets(input,sizeof(input),stdin);
            token = strtok(input,"\n");
            StrList_remove(list,token);
            break;
            // getline(&word, &word_size, stdin); // Read the word dynamically
            // word[strcspn(word, " ")] = 0; // remove newline character
            // StrList_remove(list, word);
            // free(word); // Free dynamically allocated memory
            // break;
        case 9:
            {
                fgets(input, sizeof(input), stdin);
                token = strtok(input,"\n");
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
        
    }
     } while (option !=0);
    
    
    

     StrList_free(list);

    return 0;
}
