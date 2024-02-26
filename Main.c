#include <stdio.h>
#include <stdlib.h>
#include "StrList.h"




int main() {
    StrList* myList = StrList_alloc();
    int choice;
    char str[100]; // Assuming maximum string length is 100

    do {
        
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                
                int numWords;
                scanf("%d", &numWords);
               
                for (int i = 0; i < numWords; i++) 
                {
                    scanf("%s", str);
                    StrList_insertLast(myList, str);
                }
               
                break;

            case 2:
               
                int index;
                scanf("%d", &index);
                
                scanf("%s", str);
                StrList_insertAt(myList, str, index);
               
                break;

            case 3:
              
                StrList_print(myList);
                printf("\n");
                break;

            case 4:
                printf("%zu\n", StrList_size(myList));
                break;

            case 5:
                
                scanf("%d", &index);
               
                StrList_printAt(myList, index);
                printf("\n");
                break;

            case 6:
                printf("%d\n", StrList_printLen(myList));
                break;

            case 7:
               
                scanf("%s", str);
                printf("%d\n",StrList_count(myList, str));
                break;

            case 8:
                
                scanf("%s", str);
                StrList_remove(myList, str);
              
                break;

            case 9:
               
                scanf("%d", &index);
                StrList_removeAt(myList, index);
               
                break;

            case 10:
                StrList_reverse(myList);
               
                break;

            case 11:
                StrList_free(myList);
                myList = StrList_alloc();
               
                break;

            case 12:
                StrList_sort(myList);
              
                break;

            case 13:
                if (StrList_isSorted(myList))
                    printf("true\n");
                else
                    printf("false\n");
                break;

            case 0:
               
                break;

        }

    } while (choice != 0);

    StrList_free(myList);
    return 0;
}
